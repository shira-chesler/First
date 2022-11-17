int factorial(int);

int isPrime(int num)
{
    if (num<=1)
    {
        return 0;
    }
    if (num==2)
    {
        return 1;
    }
    
    for (int i = 2; i <= (num/2)+1; i++)
    {
        if (num%i==0)
        {
            return 0;
        }
        
    }
    return 1;
}

int isStrong(int num)
{
    int ch_num=num, fact_sum=0;
    while (ch_num!=0)
    {
        int mod = ch_num%10;
        fact_sum+= factorial(mod);
        ch_num/=10;
    }
    if (fact_sum == num)
    {
        return 1;
    }
    return 0;
}

int factorial(int num)
{
    int mul_num=1;
    for(int i=2; i<=num; i++)
    {
        mul_num*=i;
    }
    return mul_num;
}