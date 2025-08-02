// Program to find the largest and smallest among 3 numbers.

#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter 3 numbers : ");
    scanf("%d%d%d",&a,&b,&c);

    int l = (a>b) ? ((a>c) ? a : c) : ((b>c) ? b : c);
    int s = (a<b) ? ((a<c) ? a : c) : ((b<c) ? b : c);

    printf("Largest : %d\nSmallest : %d",l,s);
    return 0;
}