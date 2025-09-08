// Program to read two integers from the user and print their sum, difference, product,
// quotient and remainder when the first number is divided by the second.

#include<stdio.h>
int main()
{
    printf("Enter two numbers : ");
    int a,b;
    scanf("%d%d",&a,&b);

    printf("Sum : %d\n",a+b);
    printf("Difference : %d\n",a-b);
    printf("Product : %d\n",a*b);
    
    if(b!=0)
    {
        printf("Quotient : %d\n",a/b);
        printf("Remainder : %d\n",a%b);
    }
    else
    {
        printf("Quotient and Remainder undefined (division by zero error)\n");
    }
    return 0;
}