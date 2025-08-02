// Program to change the content of a particular position of the array.

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

    printf("Change the element at (position) : ");
    int p;
    scanf("%d",&p);
    if(p<0 || p>=s)
    {
        printf("Invalid position\n");
        return 0;
    }
    else
    {
        printf("Enter the value at array[%d] : ",p);
        int val;
        scanf("%d",&val);
        a[p]=val;
    }

    printf("Displaying the elements : ");

    for(int i=0;i<s;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}
