// Sorting students by their roll numbers using structures.

#include<stdio.h>
struct Student
{
    int roll;
    char name[50];
    char address[100];
};

void sort(struct Student s[], int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(s[j].roll>s[j+1].roll)
            {
                struct Student temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
}
int main()
{
    int n;
    printf("Number of students : "); scanf("%d",&n);
    struct Student s[n];
    printf("Enter student details !!\n");
    for(int i=0;i<n;i++)
    {
        printf("Student %d\n",i+1);
        printf("Name : "); scanf(" %[^\n]",s[i].name);
        printf("Roll no. : ");
        scanf("%d",&s[i].roll);
        printf("Address : ");
        scanf(" %[^\n]",s[i].address);
    }
    sort(s,n);
    printf("\n\nSORTED Details !!\n\n");
    for(int i=0;i<n;i++)
    {
        printf("Student %d\n",i+1);
        printf("Name : %s\n",s[i].name);
        printf("Roll no. : %d\n",s[i].roll);
        printf("Address : %s\n\n",s[i].address);
    }
    return 0;
}