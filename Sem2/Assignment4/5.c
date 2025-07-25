// Program to check if a number is Palindrome.

#include<stdio.h>
int main()
{
    int n;
    printf("Enter a number : ");
    scanf("%d",&n);
    int t=n;
    int rev=0;
    while(t>0)
    {
        int rem=t%10;
        rev=(rev*10)+rem;
        t/=10;
    }
    if(rev==n) printf("PALINDROME\n");
    else printf("NOT A PALINDROME\n");
    return 0;
}