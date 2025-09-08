// Program to print patterns.

#include<stdio.h>
int main()
{
    int n;
    printf("Number of lines : ");
    scanf("%d",&n);

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("%d   ",j);
        }
        printf("\n");
    }
    printf("\n\n");

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            printf("*   ");
        }
        printf("\n");
    }
    printf("\n\n");

    int c=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            c++;
            printf("%d   ",c);
        }
        printf("\n");
    }
    return 0;
}