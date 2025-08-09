// Program to search a pattern of characters within a string.

#include<stdio.h>
#include<ctype.h>
#include<string.h>
int main()
{
    char str[100];
    char pat[100];
    printf("Enter the string : ");
    scanf(" %[^\n]",str);
    printf("Enter the pattern : ");
    scanf(" %[^\n]",pat);

    int ls=strlen(str);
    int lp=strlen(pat);

    int c=0,j=0;
    for(int i=0;i<=ls-lp;i++)
    {
        for(j=0;j<lp;j++)
        {
            if(tolower(str[i+j])!=tolower(pat[j]))
            break;
        }
        if(j==lp)
        {
            printf("Found at index %d\n",i);
            return 0;
        }
    }
    printf("Pattern not found!\n");
    return 0;
}