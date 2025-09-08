// Program to read three sides from the user and calculate its perimeter and area.

#include<stdio.h>
#include<math.h>
int main()
{
    printf("Enter the 3 sides of the triangle : ");
    float a,b,c;
    scanf("%f%f%f",&a,&b,&c);
    if(a+b>c && b+c>a && a+c>b)
    {
        float perimeter=a+b+c;
        float s=perimeter/2;
        float area=sqrt(s*(s-a)*(s-b)*(s-c));

        printf("Perimeter : %.2f\n Area : %.2f\n",perimeter,area);
    }
    else
    printf("Invalid Triangle Sides !\n");
    return 0;
}