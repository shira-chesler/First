int myPow(int base, int power);

int numLength(int);

int isArmstrong(int num)
{
    int ch_num = num;
    int power = numLength(num);
    int sum = 0;
    while (ch_num!=0)
    {
        int mod = ch_num%10;
        sum+= myPow(mod, power);
        ch_num/=10;
    }
    if (sum == num)
    {
        return 1;
    }
    return 0;
}

int isPalindrome(int num)
{
    int ch_num=num;
    int reverse_num;
    while (ch_num!=0)
    {
        int mod = ch_num%10;
        ch_num/=10;
        reverse_num*=10;
        reverse_num+= mod;
    }
    if (reverse_num == num)
    {
        return 1;
    }
    return 0;
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