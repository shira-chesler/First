#include <stdio.h>
#include "NumClass.h"

int main()
{
    int low_num, high_num;
    scanf("%d", &low_num);
    scanf("%d", &high_num);
    
    for (int i = low_num; i <= high_num; i++)
    {
        if (isPrime(i))
        {
            printf("%d", i);
        }
    }
    printf("\n");

    for (int i = low_num; i <= high_num; i++)
    {
        if (isArmstrong(i))
        {
            printf("%d", i);
        }
    }
    printf("\n");

    for (int i = low_num; i <= high_num; i++)
    {
        if (isStrong(i))
        {
            printf("%d", i);
        }
    }
    printf("\n");

    for (int i = low_num; i <= high_num; i++)
    {
        if (isPalindrome(i))
        {
            printf("%d", i);
        }
    }
}