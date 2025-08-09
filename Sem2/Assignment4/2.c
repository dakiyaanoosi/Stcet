// Program to generate Fibonacci series.

#include<stdio.h>
int main()
{
    int t;
    printf("Number of terms : ");
    scanf("%d",&t);

    int a=0,b=1;
    printf("Fibonacci series : ");
    for(int i=0;i<t;i++)
    {
        printf("%d  ",a);
        int nxt=a+b;
        a=b;
        b=nxt;
    }
    return 0;
}