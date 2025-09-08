// Check if the given is leap year.

#include<stdio.h>
int main()
{
    int y;
    printf("Enter the year : ");
    scanf("%d",&y);
    if((y%4==0 && y%100!=0) || (y%400==0)) printf("LEAP YEAR\n");
    else printf("NOT A LEAP YEAR\n");
    return 0;
}