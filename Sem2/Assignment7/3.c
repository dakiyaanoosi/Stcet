// Program to chcek if the string is Palindrome.

#include<stdio.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char str[100];
    printf("Enter the string : ");
    scanf(" %[^\n]",str);
    int isPalin=1;
    int l=strlen(str);
    for(int i=0,j=l-1;i<j;i++,j--)
    {
        if(tolower(str[i])!=tolower(str[j]))
        {
            isPalin=0;
            break;
        }
    }
    if(isPalin) printf("PALINDROME\n");
    else printf("NOT A PALINDROE\n");
    return 0;
}