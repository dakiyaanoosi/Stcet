// Program to print prime numbers in a given limit.

#include<stdio.h>
#include<math.h>
int isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        return 0;
    }
    return 1;
}
int main()
{
    int lim;
    printf("Enter the limit (number) : ");
    scanf("%d",&lim);
    
    for(int i=2;i<=lim;i++)
    {
        if(isPrime(i)) printf("%d   ",i);
    }
    printf("\n");
    return 0;
}