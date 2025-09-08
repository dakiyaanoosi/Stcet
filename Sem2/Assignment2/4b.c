#include<stdio.h>
int main()
{
    int a;
    printf("Enter a number : ");
    scanf("%d",&a);

    int result=a;
    result*=2;
    printf("%d*=2 : %d\n",a,result);

    result=a;
    result/=2;
    printf("%d/=2 : %d\n",a,result);

    result=a;
    result+=2;
    printf("%d+=2 : %d\n",a,result);

    result=a;
    result-=2;
    printf("%d-=2 : %d\n",a,result);

    return 0;
}