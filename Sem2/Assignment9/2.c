// Program to find sum of a series using recursion.

#include<stdio.h>
double sum(int num, double den, int terms)
{
    if(terms==0)
    return 0;
    return (num/den)+sum(num+2, den+2.2, terms-1);
}
int main()
{
    int terms,d;
    printf("Number of terms : ");
    scanf("%d",&terms);
    printf("Number of decimal places : ");
    scanf("%d",&d);
    printf("Sum : %.*f\n",d,sum(2, 1.3, terms));
    return 0;
}