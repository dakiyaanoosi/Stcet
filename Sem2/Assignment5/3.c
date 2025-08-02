// Sum of a series.

#include<stdio.h>
int main()
{
    int t,dp;
    printf("Number of terms : ");
    scanf("%d",&t);
    printf("Number of decimal places : ");
    scanf("%d",&dp);

    int n=2;
    float d=1.3,sum=0;
    for(int i=0;i<t;i++)
    {
        sum+=(n/d);
        n+=2;
        d+=2.2;
    }
    printf("Sum : %.*f\n",dp,sum);
    return 0;
}
