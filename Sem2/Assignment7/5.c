// Program to find the mean and Standard Deviation of a given set of numbers.

#include<stdio.h>
#include<math.h>
int main()
{
    int n;
    float sum=0;
    printf("Number of values : ");
    scanf("%d",&n);
    float a[n];

    printf("Enter the %d values : ",n);
    for(int i=0;i<n;i++)
    {
        scanf("%f",&a[i]);
        sum+=a[i];
    }
    float mean=(sum/n);

    sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=pow((a[i]-mean),2);
    }
    float sd=sqrt(sum/n);
    printf("Mean : %.2f\nStandard Deviation : %.2f\n",mean,sd);
    
    return 0;
}