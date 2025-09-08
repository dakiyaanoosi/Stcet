// Tower of Hanoi

#include<stdio.h>
void TOH(int n, char s, char h, char d)
{
    if(n==1)
    {
        printf("Disk %d : %c --> %c\n",n,s,d);
        return;
    }
    TOH(n-1,s,d,h);
    printf("Disk %d : %c --> %c\n",n,s,d);
    TOH(n-1,h,s,d);
}
int main()
{
    int n;
    printf("Number of disks : "); scanf("%d",&n);
    TOH(n,'S','H','D');
    return 0;
}