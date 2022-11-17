int myPow(int, int );

int numLength(int);

int isArmstrongRec(int, int, int);

int isPalindromeRec(int, int);

int isArmstrong(int num)
{
    int sum = isArmstrongRec(num, 0, numLength(num));
    if (sum==num)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int num)
{
    int reverse = isPalindromeRec(num, 0);
    if (reverse == num)
    {
        return 1;
    }
    return 0;
}

int isArmstrongRec(int original, int sum, int length)
{
    if (original == 0)
    {
        return sum;
    }
    return(isArmstrongRec(original/10, sum+myPow(original%10, length), length));
}

int isPalindromeRec(int original, int reverse)
{
    if (original==0)
    {
        return reverse;
    }
    return(isPalindromeRec(original/10, (reverse*10)+original%10));
}

int myPow(int base, int power)
{
    int num=1;
    while (power>0)
    {
        num*= base;
        power--;
    }
    return num;
}

int numLength(int num)
{
    int count_len=0;
    while(num!=0)
    {
        num/=10;
        count_len++;
    }
    return count_len;
}