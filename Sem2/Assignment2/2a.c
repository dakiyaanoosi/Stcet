// Program to swap two integer values (using temporary variable).

#include<stdio.h>
int main()
{
    int a=2,b=3;
    printf("Before Swapping : a=%d, b=%d\n",a,b);
    int t=a;
    a=b;
    b=t;
    printf("After Swapping : a=%d, b=%d",a,b);
    return 0;
}