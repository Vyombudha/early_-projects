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

bool isChar(char input[])
{
    int len = strlen(input);

    if (len != 1)
    {
        return false;
    }

    if ((input[0] >= 'a' && input[0] <= 'z') || (input[0] >= 'A' && input[0] <= 'Z'))
    {
        return true;
    }

    return false;
}

bool isInt(char input[])
{
    int len = strlen(input), start = 0;

    if (input[start] == '-')
    {
        if (len == 1)
        {
            return false;
        }
        start = 1;
    }

    for (int i = start; i < len; i++)
    {
        if (!(input[i] >= '0' && input[i] <= '9'))
        {
            return false;
        }
    }
    return true;
}

bool isFloat(char input[])
{
    int len = strlen(input), start = 0, dotCount = 0;

    // Check for negative numbers
    if (input[start] == '-')
    {
        if (len == 1)
        {
            return false; // "-" alone is not valid
        }
        start = 1; // Skip the minus sign for the rest of the check
    }

    // Special case: the number can start with a decimal point, e.g., ".123"
    if (input[start] == '.')
    {
        dotCount = 1;
        start = 1;
    }

    // Iterate through each character
    for (int i = start; i < len; i++)
    {
        // Check for digits
        if (input[i] >= '0' && input[i] <= '9')
        {
            continue; // If it's a digit, continue
        }

        // Check for decimal point (only one allowed)
        if (input[i] == '.' && dotCount == 0)
        {
            dotCount = 1;
            continue; // Allow the decimal point
        }

        // If it's neither a digit nor a valid decimal point, return false
        return false;
    }

    return true; // If no invalid characters, it's a valid float
}

void printVar(var V)
{

    switch (V.assignedDataType)
    {
    case CHAR:
        printf("The Variable (char) is %c", V.value.c);
        break;
    case INT:
        printf("The Variable (int) is %d", V.value.i);
        break;
    case FLOAT:
        printf("The Variable (float) is %f", V.value.f);
        break;
    default:
        printf("The Variable (string) is %s",V.value.s.value);
        break;
    }
}

var newVar(char input[])
{
    var Variable;
    if (isChar(input))
    {
        Variable.assignedDataType = CHAR;
        Variable.value.c = (char)input[0];
    }
    else if (isInt(input))
    {
        Variable.assignedDataType = INT;
        Variable.value.i = atoi(input);
    }
    else if (isFloat(input))
    {
        Variable.assignedDataType = FLOAT;
        Variable.value.f = atof(input);
    }
    else
    {
        Variable.assignedDataType = STRING;
        Variable.value.s = newString(input);
    }
    return Variable;
}

