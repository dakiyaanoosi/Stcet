// Program to generate amicable pairs. 

#include<stdio.h>
int sumOfDivisors(int n)
{
    int sum=0;
    for(int i=1;i<n;i++)
    {
        if(n%i==0)
        sum+=i;
    }
    return sum;
}
int main()
{
    for(int i=1;i<10000;i++)
    {
        int sum1=sumOfDivisors(i);
        if(sum1>i && sum1<=10000)
        {
            int sum2=sumOfDivisors(sum1);
            if(sum2<=10000)
            {
                if(sum2==i)
                {
                    printf("(%d, %d)   ",i,sum1);
                }
            }
        }
    }
    return 0;
}