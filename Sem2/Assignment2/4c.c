#include<stdio.h>
int main()
{
    int a,b;
    printf("Enter a number 'a' : ");
    scanf("%d",&a);
    printf("Enter a number 'b' : ");
    scanf("%d",&b);

    printf("a>0 && b>0 : %d\n",(a>0 && b>0));
    printf("a>0 || b>0 : %d\n",(a>0 || b>0));
    printf("!(a>0) : %d",!(a>0));
    return 0;
}