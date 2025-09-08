// Binary Search

#include<stdio.h>
int main()
{
    int n,s;
    printf("Number of elements : "); scanf("%d",&n);
    int a[n];
    printf("Enter %d sorted elements.......\n",n);
    for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
    printf("Enter the search element : "); scanf("%d",&s);
    int l=0,h=n-1,mid,position=-1;
    while(l<=h)
    {
        mid=l+(h-l)/2;
        if(a[mid]==s)
        {
            position=mid;
            break;
        }
        else if(s<a[mid]) h=mid-1;
        else l=mid+1;
    }
    printf("%d",position);
}