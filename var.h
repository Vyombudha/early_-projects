#ifndef VAR_H
#define VAR_H 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "customStrings.h"


typedef enum
{
    INT,
    CHAR,
    FLOAT,
    STRING
} listOfTypes;

typedef union
{
    string s;
    int i;
    char c;
    float f;
} Types;

typedef struct
{
    listOfTypes assignedDataType;
    Types value;
} var;

bool isChar(char input[]);

bool isInt(char input[]);

bool isFloat(char input[]);

void printVar(var V);

var newVar(char input[]);





#endif

