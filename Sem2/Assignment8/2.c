// Program to substitute toupper() and tolower().

#include<stdio.h>
int toUpper(char c)
{
    if(c>=97 && c<=122)
    return (c-32);
    else
    return c;
}
int toLower(char c)
{
    if(c>=65 && c<=90)
    return (c+32);
    else
    return c;
}
int main()
{
    char c;
    printf("Enter any character : ");
    scanf("%c",&c);
    
    printf("toLower : %c\n",toLower(c));
    printf("toUpper : %c",toUpper(c));
    return 0;
}