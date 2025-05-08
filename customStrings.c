#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char value[256];
    void (*printString)(char *);
    void (*toUpper)(char *);
    int len;
} string;

void toUpper(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - 32; // Convert to uppercase
        }
    }
}

char *inputString(const char *prompt)
{
    printf("%s", prompt);
    int maxSize = 20, realSize = 0;
    char *temp = malloc(sizeof(char) * maxSize);

    if (temp == NULL)
    {
        printf("\nError In Allocating Memory for String of Prompt '%s'!\n", prompt);
        return NULL;
    }
    char ch;
    while ((ch = getchar()) != EOF && ch != '\n')
    {
        if (realSize == maxSize)
        {
            maxSize *= 2;
            temp = realloc(temp, sizeof(char) * maxSize);
            if (temp == NULL)
            {
                printf("\nError In Reallocating Memory for String of Prompt '%s'! at length %d\n", prompt, realSize);
                return NULL;
            }
        }
        temp[realSize] = ch;
        realSize++;
    }

    temp[realSize] = '\0';

    temp = realloc(temp, sizeof(char) * realSize);
    if (temp == NULL)
    {
        printf("\nError In Reallocating Memory for String of Prompt '%s'! at length %d\n", prompt, realSize);
    }

    return temp;
}

void printString(char *str)
{
    printf("The String is: %s", str);
}



string newString(char *inputStr)
{
    string str;

    str.len = strlen(inputStr);
    str.printString = printString;
    str.toUpper = toUpper;
    strcpy(str.value, inputStr);

    return str;
}
