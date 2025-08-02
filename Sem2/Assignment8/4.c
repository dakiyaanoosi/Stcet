// Program to find factorial, permutation and combinationn.

#include<stdio.h>
unsigned long long int factorial(int n)
{
    unsigned long long int fact=1;
    for(int i=n;i>=2;i--)
    fact*=i;
    return fact;
}
long double combination(int n,int r)
{
    return (long double)factorial(n)/(factorial(n-r)*factorial(r));   
}
long double permutation(int n,int r)
{
    return (long double)factorial(n)/factorial(n-r);
}
int main()
{
    int n,r,ch;
    printf("1.Find Factorial\n2.Combination\n3.Permutatioin\n\nEnter your choice [1/2/3] : ");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1: printf("Enter the number : ");
                scanf("%d",&n);
		 		if(n<0)
	         	printf("Factorial is not defined for negative numbers!!\n");
				else
		 		printf("The Factrorial is : %llu\n",factorial(n));
		 		break;
    	case 2: printf("Enter 'n' : ");
		 		scanf("%d",&n);
		 		printf("Enter 'r' : ");
				scanf("%d",&r);
		 		if(n<0 || r<0 || n<r)
		 		printf("Invalid input! Ensure that n>=r>=0.\n");
		 		else
		 		printf("%dC%d : %.0Lf\n",n,r,combination(n,r));
		 		break;
        case 3: printf("Enter 'n' : ");
		 		scanf("%d",&n);
		 		printf("Enter 'r' : ");
		 		scanf("%d",&r);
		 		if(n<0 || r<0 || n<r)
		 		printf("Invalid input! Ensure that n>=r>=0.\n");
		 		else
		 		printf("%dP%d : %.0Lf\n",n,r,permutation(n,r));
		 		break;
		default: printf("Invalid choice!\n");
    }
}
    
