// Program to print non-Fibonacci numbers.

#include<stdio.h>
int main()
{
    printf("Enter the limit (number) : ");
    int lim;
    scanf("%d",&lim);
    
    int a=0,b=1;
    while(b<lim)
    {
        int next=a+b;
        a=b;
        b=next;

        for(int i=a+1;i<b && i<lim;i++)
        {
            printf("%d   ",i);
        }
    }
    printf("\n");
    return 0;
}