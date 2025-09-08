// Program to generate AP.

#include<stdio.h>
int main()
{
    int a,d,t;
    printf("First term : ");
    scanf("%d",&a);
    printf("Common difference : ");
    scanf("%d",&d);
    printf("Number of terms : ");
    scanf("%d",&t);

    printf("AP: ");
    for(int i=0;i<t;i++)
    {
        printf("%d   ",a);
        a+=d;
    }
    return 0;
}