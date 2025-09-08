// Program to find roots of a quadratic equation.

#include<stdio.h>
#include<math.h>
int main()
{
    float a,b,c;
    printf("Enter a, b & c : ");
    scanf("%f%f%f",&a,&b,&c);
    
    if(a==0)
    {
        printf("'a' cannot be zero!\n");
        return 0;
    }

    float D=b*b-(4*a*c);
    if(D<0) printf("No Real Roots\n");
    else
    {
        float x1=(-b+sqrt(D))/(2*a);
        float x2=(-b-sqrt(D))/(2*a);
        printf("The roots are (%.2f, %.2f)\n",x1,x2);
    }
    return 0;
}