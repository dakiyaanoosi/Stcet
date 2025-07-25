// Insertion Sort

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
    for(int i=1;i<s;i++)
    {
        int index=i-1;
        int currElement=a[i];
        while(index>=0 && currElement<a[index])
        {
            a[index+1]=a[index];
            index--;
        }
        a[index+1]=currElement;
    }

    printf("Displaying the elements : ");
    for(int i=0;i<s;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}