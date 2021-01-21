#include "EncryptThis.h"

bool containsConsecutiveSpaces(const char *str){
    bool result = false;

    for(int i = 0; str[i] != '\0';i++){
        if(isspace(str[i]) && str[i+1] != '\0'){
            if(isspace(str[i+1])){
                result = true;
                break;
            }
        }
    }

    return result;
}

bool isUntrimmed(const char *str){
    return str[0] == ' ' || str[strlen(str)-1] == ' ';
}

void removeAt(char *str,int pos){
    int len = strlen(str);
    for(int i = pos;str[i] != '\0';i++){
        str[i] = str[i+1];
    }
    len--;
    str[len] = '\0';
}

//Should be called only if the string is trimmed
void removeSpacesFromMiddle(char *str){
    for(int i = 0;str[i] != '\0';i++){
        if(isspace(str[i]) && isspace(str[i+1])){
            removeAt(str,i);
            i--;
        }
    }
}

void ltrim(char *str){
    int count = 0;
    while(isspace(str[count])){
        count++;
    }

    int j = 0;
    for(int i = count;str[i] != '\0';i++){
        str[j++] = str[i];
    }

    str[j] = '\0';
}

void rtrim(char *str){
    int pos = strlen(str)-1;
    while(isspace(str[pos])){
        pos--;
    }

    int j = 0;
    for(int i = 0;i <= pos;i++){
        str[j++] = str[i];
    }

    str[j] = '\0';    
}


char *removeExtraSpaces(const char *str){
    char *buffer = strdup(str);
    ltrim(buffer);
    rtrim(buffer);
    removeSpacesFromMiddle(buffer);
    return buffer;
}

int convertToASCII(char c){
    return c;
}

void switchLetters(char *str, int src, int dest){
    char aux = str[src];
    str[src] = str[dest];
    str[dest] = aux;
}

int tokenCount(const char *str,char c){
    int tokens = 0;

    for(int i = 0;str[i] != '\0';i++){
        if(str[i] == c){
            tokens++;
        }
    }

    return tokens+1;
}

char **string_split(const char *str,int tokens, char *delimiter){
    int i = 0;
    char *buffer = strdup(str);
    char **split = malloc(tokens * sizeof(char *));

    char *token = strtok(buffer,delimiter);
    split[i] = strdup(token);

    while(token != NULL && i != tokens-1){
        i++;
        token = strtok(NULL,delimiter);
        split[i] = strdup(token);
    }

    free(buffer);
    return split;
}

void freeStringArr(char **str,int len){
    for(int i = 0;i < len;i++){
        free(str[i]);
    }
    free(str);
}

char *multipleWordsRoutine(char **words,int tokens){
    for(int i = 0;i < tokens;i++){
        char *aux = encrypt_this(words[i]);
        free(words[i]);
        words[i] = strdup(aux);
        free(aux);
    }

    char *buffer = NULL;
    int sizeBuffer = 1;
    int offset = 0;
    int needed, written;

    for(int i = 0;i < tokens;i++){
        needed = strlen(words[i]);
        sizeBuffer += needed;
        buffer = realloc(buffer,sizeBuffer);
        written = snprintf(buffer+offset,needed+1,"%s",words[i]);
        offset += written;

        if(i != tokens-1){
            sizeBuffer += 1;
            buffer = realloc(buffer,sizeBuffer);
            strcat(buffer," ");
            offset += 1;
        }
    }

    freeStringArr(words,tokens);
    return buffer;
}

char *intToString(int num){
    int needed = snprintf(NULL,0,"%d",num);
    char *str = malloc(needed+1);
    snprintf(str,needed+1,"%d",num);
    return str;
}

char *encrypt_this(const char *str){
    int len = strlen(str);

    switch(len){
        case 0:;
            return strdup(str);

        case 1:;
            return intToString(convertToASCII(*str));

        default:;
            char *trimStr;

            if(containsConsecutiveSpaces(str) || isUntrimmed(str)){
                trimStr = removeExtraSpaces(str);
                int tokens = tokenCount(trimStr,' ');

                switch(tokens){
                    case 1:;
                        char *buffer = encrypt_this(trimStr);
                        free(trimStr);
                        return buffer;

                    default:;
                        char **words = string_split(trimStr,tokens," ");
                        free(trimStr);
                        return multipleWordsRoutine(words,tokens);
                }

            }else{
                int tokens = tokenCount(str,' ');
                if(tokens >= 2){
                    char **words = string_split(str,tokens," ");
                    return multipleWordsRoutine(words,tokens);
                }
            }

            char *asciiCode = intToString(convertToASCII(*str));
            char *strWithoutFirstChar = malloc(len);
            strcpy(strWithoutFirstChar,str+sizeof(char));
            switchLetters(strWithoutFirstChar,0,(int) strlen(strWithoutFirstChar)-1);

            int needed = snprintf(NULL,0,"%s%s",asciiCode,strWithoutFirstChar);
            char *buffer = malloc(needed+1);
            snprintf(buffer,needed+1,"%s%s",asciiCode,strWithoutFirstChar);
            free(strWithoutFirstChar);
            free(asciiCode);
            return buffer;
    }
}
