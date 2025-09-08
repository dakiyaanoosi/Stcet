// Program to create an array, take inputs and display its content.

#include<stdio.h>
int main()
{
    printf("Size of array : ");
    int s;
    scanf("%d",&s);

    int a[s];

    printf("Enter the elements : ");
    for(int i=0;i<s;i++)
    scanf("%d",&a[i]);

    printf("Displaying the elements : ");
    for(int i=0;i<s;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}
