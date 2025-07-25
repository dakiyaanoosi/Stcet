// Program to swap two integer values (Without using temporary variable).


#include<stdio.h>
int main()
{
    int a=2,b=3;
    printf("Before Swapping : a=%d, b=%d\n",a,b);
    a=a+b;
    b=a-b;
    a=a-b;
    printf("After Swapping : a=%d, b=%d",a,b);
    return 0;
}