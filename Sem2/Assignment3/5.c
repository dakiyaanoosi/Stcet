#include<stdio.h>
int main()
{
    int p;
    printf("Enter your percentage : ");
    scanf("%d",&p);

    char grade;
    if(p>=90)
    grade='O';
    else if(p>=80)
    grade='E';
    else if(p>=70)
    grade='A';
    else if(p>=60)
    grade='B';
    else if(p>=50)
    grade='C';
    else if(p>=40)
    grade='D';
    else
    grade='F';

    printf("Grade : %c\n",grade);

    return 0;
}