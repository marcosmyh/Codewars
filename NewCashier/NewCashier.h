#ifndef NewCashier_H_
#define NewCashier_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *substr(const char *,int,int);
int hashString(char *);
int obtainIndex(char *);
char *obtainItem(char,char *);
int *determineOcurrences(const char *,int *);
int cmpFunc(const int *,const int *);
char *get_order(const char *);

#endif
