// Program to print text backwards using recursion.+

#include<stdio.h>
#include<string.h>
void print(char text[100], int l)
{
    if(l<0)
    {
        printf("\n");
        return;
    }
    printf("%c",text[l]);
    print(text,l-1);
}
int main()
{
    char text[100];
    printf("Enter a text : ");
    scanf(" %[^\n]",text);
    int l=strlen(text);
    print(text,l-1);
    return 0;
}