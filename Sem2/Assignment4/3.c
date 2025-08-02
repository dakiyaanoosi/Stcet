// Program to check for Prime and Composite.

#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    int isPrime=1;

    if(n==1)
    {
        printf("NEITHER PRIME NOR COMPOSITE\n");
        return 0; 
    }

    for(int i=2;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
            isPrime=0;
            break;
        }
    }
    if(isPrime) printf("PRIME\n");
    else printf("COMPOSITE\n");
    return 0;
}