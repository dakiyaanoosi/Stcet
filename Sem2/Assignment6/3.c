// Bubble Sort

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

    //Sorting
    for(int i=0;i<s-1;i++)
    {
        for(int j=0;j<s-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                int t=a[j];
                a[j]=a[j+1];
                a[j+1]=t;
            }
        }
    }

    printf("Sorted array : ");
    for(int i=0;i<s;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}