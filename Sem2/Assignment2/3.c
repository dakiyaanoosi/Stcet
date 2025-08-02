// Program to find units and tens place of an integer.

#include<stdio.h>
#include<stdlib.h>
int main()
{
    printf("Enter an integer : ");
    int n;
    scanf("%d",&n);
    n=abs(n);
    int u=n%10;
    n=n/10;
    int t=n%10;
    printf("Units place : %d\nTens place : %d\n",u,t);
    return 0;
}