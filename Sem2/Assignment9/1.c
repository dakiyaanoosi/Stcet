// Program to find factorial using recursion.

#include<stdio.h>
unsigned long long int fact(int n)
{
    if(n==0)
    return 1;
    return n*fact(n-1);
}
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    if(n>=0)
    printf("Factorial of %d : %llu",n,fact(n));
    else printf("Factorial not defined for -ve numbers!\n");
    return 0;
}