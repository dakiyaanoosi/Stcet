#include<stdio.h>
int main()
{
    int a,b,ch;
    
    printf("Enter First Number : ");
    scanf("%d",&a);
    printf("Enter Second Number : ");
    scanf("%d",&b);

    printf("\n1.Sum\n2.Difference\n3.Product\n4.Quotient\n\nEnter your choice [1/2/3/4]: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1: printf("Sum : %d\n",a+b);
                break;
        case 2: printf("Difference : %d\n",a-b);
                break;
        case 3: printf("Product : %d\n",a*b);
                break;
        case 4: printf("Quotient : %d\n",a/b);
                break;
        default: printf("Invalid Choice !!\n");
    }
    
    return 0;
}