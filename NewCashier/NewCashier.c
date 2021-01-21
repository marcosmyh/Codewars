#include "NewCashier.h"

char *menu[] = {"Burger","Fries","Chicken","Pizza","Sandwich","Onionrings","Milkshake","Coke"};

char *substr(const char *str,int start,int end){
    int len = end-start;
    char *buffer = malloc(len+2);
    int j = 0;
    for(int i = start;i <= end;i++){
        buffer[j++] = str[i];
    }
    buffer[j] = '\0';
    return buffer;
}

int hashString(char *item){
    int len = strlen(item);
    int hash = len;
    hash += item[0] + item[len-1];
    return hash;
}

int obtainIndex(char *item){
    switch(hashString(item)){
        case 186:
            return 0;
        case 190:
            return 1;
        case 184:
            return 2;
        case 182:
            return 3;
        case 195:
            return 4;
        case 204:
            return 5;
        case 187:
            return 6;
        case 172:
            return 7;
        default:
            return -1;
    }
}

char *obtainItem(char c,char *auxSubstring){
    switch(c){
        case 'b':case 'B':
            return menu[0];
        case 'f':case 'F':
            return menu[1];
        case 'c':case 'C':;
            auxSubstring[0] = tolower(auxSubstring[0]);
            return strcmp("ch",auxSubstring) == 0? menu[2]: menu[7];
        case 'p':case 'P':
            return menu[3];
        case 's':case 'S':
            return menu[4];
        case 'o':case 'O':
            return menu[5];
        case 'm':case 'M':
            return menu[6];
        default:
            return "-1";
    }
}

int *determineOcurrences(const char *str,int *len){
    int *arr = NULL;
    int size = 0;
    int j = 0;

    for(int i = 0;str[i] != '\0';i++){
        char *item;

        if(str[i] == 'c' || str[i] == 'C'){
            char *aux = substr(str,i,i+1);
            item = obtainItem(str[i],aux);
            free(aux);
        }else{
            item = obtainItem(str[i],NULL);
        }

        i += strlen(item)-1;
        size += sizeof(int);
        arr = realloc(arr,size);
        arr[j++] = obtainIndex(item);
    }

    memcpy(len,&j,sizeof(int));
    return arr;
}

int cmpFunc(const int *a,const int *b){
    return *a-*b;
}

char *get_order(const char *str){
    int len;
    int *ocurrences = determineOcurrences(str,&len);
    qsort(ocurrences,len,sizeof(int),(void *) cmpFunc);

    //size initialized in 1 for the null terminator ('\0');
    int size = 1;
    int offset = 0;
    int needed,written;
    char *buffer = NULL;

    for(int i = 0;i < len;i++){
        needed = strlen(menu[ocurrences[i]]);
        size += needed;
        buffer = realloc(buffer,size);
        written = snprintf(buffer+offset,needed+1,"%s",menu[ocurrences[i]]);
        offset += written;

        if(i != len-1){
            size += 1;
            buffer = realloc(buffer,size);
            strcat(buffer," ");
            offset += 1;
        }
    }

    free(ocurrences);
    return buffer;
}
