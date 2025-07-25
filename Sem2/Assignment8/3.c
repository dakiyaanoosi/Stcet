// Program to substitute pow() with integer parameters.

#include<stdio.h>
#include<math.h>
double power(int b,int e)
{
    double result=1.0;
    if(b==0)
    {
        if(e==0)
        return NAN;
        return 0;
    }
    if(e==0)
    return 1;
    for(int i=0;i<e;i++)
    result*=b;
    return result;
}
int main()
{
    int b,e;
    double result;
    printf("Base : ");
    scanf("%d",&b);
    printf("Exponent : ");
    scanf("%d",&e);

    if(b==0 && e<0)
    {
        printf("Not Defined!!\n");
        return 0;
    }
    else if(e<0)
    result=1.0/power(b,-e);
    else
    result=power(b,e);

    printf("%.3f\n",result);    
    return 0;
}
