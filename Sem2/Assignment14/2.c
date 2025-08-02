#include<stdio.h>
int main()
{
    FILE *f1, *f2;
    int a[100],n=0;
    f1=fopen("input.txt","r");
    while(fscanf(f1,"%d",&a[n])==1)
    n++;
    fclose(f1);
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {

            if(a[j]>a[j+1])
            {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    f2=fopen("output.txt","w");
    fprintf(f2,"SORTED ELEMENTS\n");
    for(int i=0;i<n;i++)
    {
        fprintf(f2,"%d\n",a[i]);
    }
    fclose(f2);
    return 0;
}