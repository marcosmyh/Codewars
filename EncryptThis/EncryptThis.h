#ifndef EncryptThis_H_
#define EncryptThis_H_

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *encrypt_this(const char *);
void switchLetters(char *, int, int);
int convertToASCII(char);
bool isUntrimmed(const char *);
bool containsConsecutiveSpaces(const char *);
void freeStringArr(char **, int);
int tokenCount(const char *,char);
char **string_split(const char *,int,char *);
char *multipleWordsRoutine(char **,int);
void removeAt(char *,int);
void removeSpacesFromMiddle(char *);
char *removeExtraSpaces(const char *);
void ltrim(char *);
void rtrim(char *);
char *intToString(int);

#endif
