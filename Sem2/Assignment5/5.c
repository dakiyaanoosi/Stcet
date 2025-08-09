// Program to print Armstrong numbers between 100 to 1000.

#include<stdio.h>

int isArmstrong(int n)
{
    int t=n;
    int sum=0;
    while(t>0)
    {
        int r=t%10;
        sum+=r*r*r;
        t/=10;
    }
    if(sum==n) return 1;
    return 0;
}
int main()
{
    for(int i=100;i<=999;i++)
    {
        if(isArmstrong(i)) printf("%d   ",i);
    }
    printf("\n");
    return 0;
}