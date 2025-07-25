// Selection Sort

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
        int index=i;
        for(int j=i+1;j<s;j++)
        {
            if(a[j]<a[index])
            index=j;
        }
        if(index!=i)
        {
            int t=a[i];
            a[i]=a[index];
            a[index]=t;
        }
    }

    printf("Displaying the elements : ");
    for(int i=0;i<s;i++)
    printf("%d ",a[i]);
    printf("\n");

    return 0;
}