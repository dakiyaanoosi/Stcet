#include<stdio.h>
int main()
{
    int a=10,b=13;
    printf("(AND) 10 & 13 : %d\n",a&b); //OUTPUT = 8
    printf("(OR) 10 | 13 : %d\n",a|b);
    printf("(NOT) !10 : %d\n",~a);
    printf("(XOR) 10^13 : %d\n",a^b);
    printf("(LEFT SHIFT) 10<<3 : %d\n",a<<3); //OUTPUT = 10*2^3 = 80
    printf("(RIGHT SHIFT) 10>>3 : %d\n",a>>3); //OUTPUT = 10/2^3 = 1

    return 0;
}