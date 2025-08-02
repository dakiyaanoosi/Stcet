#include<stdio.h>
int main()
{
    FILE *file;
    int n,num;
    file=fopen("input.txt","w");
    printf("Number of integers : "); scanf("%d",&n);
    printf("Enter %d integers.......\n",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&num);
        fprintf(file,"%d\n",num);
    }
    fclose(file);
    printf("Integers stored successfully!!");
    return 0;
}