#include<stdio.h>
int main()
{
	printf("Enter the size of the array : ");
	int size;
	scanf("%d",&size);
	int a[size];

	printf("Enter the %d elements : ",size);

	for(int i=0;i<size;i++)
	scanf("%d",&a[i]);

	printf("\nArray : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]):
	printf("\n");

	printf("Enter the element you want to search for : ");
	int element;
	scanf("%d",&element);

	for(int i=0;i<size;i++)
	{
		if(a[i]==element)
		{
			printf("\nElement found at position : %d\n\n",i+1);
			return 0;
		}
	}
	
	printf("\nElement not found!\n\n");
	return 0;
}
