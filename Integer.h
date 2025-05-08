#ifndef TEST_H
#define TEST_H


#include <stdio.h>

typedef struct
{
    int value;
    int (*add)(int, int);
    int (*rev)(int num);
} Integer;

int add(int num1, int num2);

int rev(int num);

Integer newInt(int value);


#endif