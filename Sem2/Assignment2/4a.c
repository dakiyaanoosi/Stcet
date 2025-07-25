#include<stdio.h>
int main()
{
    int a,b,c;
    printf("Enter a number 'a' : ");
    scanf("%d",&a);
    printf("Enter a number 'b' : ");
    scanf("%d",&b);
    printf("Enter a number 'c' : ");
    scanf("%d",&c);

    int result1=a>b;
    int result2=b>c;
    int result3=a==c;
    int result4=a!=b;

    printf("\n[1=true,0=false]\n\n");
    printf("a>b : %d\nb>c : %d\na==c : %d\na!=b : %d\n",result1,result2,result3,result4);

    return 0;
}