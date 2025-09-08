// program to find area of a circle.
#include<stdio.h>
const float PI=3.1415926;
int main()
{
    float r;
    printf("Enter the radius : ");
    scanf("%f",&r);
    if(r<0)
    {
        printf("Radius cannot be negative\n");
        return 0;
    }
    float area=PI*r*r;
    printf("Area : %.2f\n",area);
    return 0;
}