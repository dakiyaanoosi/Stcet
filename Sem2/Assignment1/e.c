// Program to change temperature from Celcius to Fahrenheit and vice versa.

#include<stdio.h>
int main()
{
    printf("1. Celsius --> Fahrenheit\n2. Fahrenheit --> Celsius\n");
    printf("Enter your choice [1/2] : ");
    int ch;
    scanf("%d",&ch);
    float c,f;

    switch(ch)
    {
        case 1: printf("Enter the temperature in Celsius : ");
                scanf("%f",&c);
                f=(c*9/5)+32;
                printf("Temperature in Fahrenheit : %.2f\n",f);
                break;
        case 2: printf("Enter the temperature in Fahrenheit : ");
                scanf("%f",&f);
                c=(f-32)*(5.0/9);
                printf("Temperature in Celsius : %.2f\n",c);
                break;
        default: printf("invalid Choice\n");
    }
    return 0;
}