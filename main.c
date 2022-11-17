#include <stdio.h>
#include "NumClass.h"

int main()
{
    int low_num, high_num;
    scanf("%d", &low_num);
    scanf("%d", &high_num);
    
    printf("The Armstrong numbers are:");
    for (int i = low_num; i <= high_num; i++)
    {
        if (isPrime(i))
        {
            printf(" %d", i);
           
        }
    }
    printf("\n");

    printf("The Palindromes are:");
    for (int i = low_num; i <= high_num; i++)
    {
        if (isArmstrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Prime numbers are:");
    for (int i = low_num; i <= high_num; i++)
    {
        if (isStrong(i))
        {
            printf(" %d", i);
        }
    }
    printf("\n");

    printf("The Strong numbers are:");
    for (int i = low_num; i <= high_num; i++)
    {
        if (isPalindrome(i))
        {
            printf(" %d", i);
        }
    }
}