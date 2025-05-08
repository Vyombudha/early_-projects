#ifndef CUSTOMSTRINGS_H
#define CUSTOMSTRINGS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char value[256];
    void (*printString)(char *);
    void (*freeString)(char *);
    void (*toUpper)(char *);
    int len;
} string;

void toUpper(char* str);

char *inputString(const char *prompt);

string newString(char *inputStr);


#endif