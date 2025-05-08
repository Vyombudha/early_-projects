#include <stdio.h>

typedef struct
{
    int value;
    int (*add)(int, int);
    int (*rev)(int num);
} Integer;

int add(int num1, int num2)
{
    return num1 + num2;
}    

int rev(int num)
{
    int revNum = 0, rev;
    while (num != 0)
    {
        rev = num % 10;
        revNum = revNum * 10 + rev;
        num /= 10;
    }    
    return revNum;
}    


Integer newInt(int value)
{
    Integer Int;
    Int.value = value;
    Int.add = add;
    Int.rev = rev;
    return Int;
}
 
