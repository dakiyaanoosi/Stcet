// Demonstrating the use of structures and unions.

#include<stdio.h>
struct Data
{
    float x;
    float y;
    int isFloat;
};
union Number
{
    int n;
    float f;
};
int main()
{
    struct Data cal;
    union Number n;
    printf("x : "); scanf("%f",&cal.x);
    printf("Is 'n' a floating point number ? [0/1] : "); 
    scanf("%d", &cal.isFloat);

    if (cal.isFloat)
    {
        printf("n : "); scanf("%f", &n.f);
        cal.y = cal.x * n.f;
    }
    else
    {
        printf("n : "); scanf("%d", &n.n);
        cal.y = cal.x * n.n;
    }

    printf("RESULT : y = %.2f\n",cal.y);
    return 0;
}