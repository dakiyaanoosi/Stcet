#include<stdio.h>

void Sort(int a[], int size) {
	for(int i=1;i<size;i++) {
		int currElement = a[i];
		int index=i-1;
		while(currElement<a[index] && index>=0) {
			a[index+1]=a[index];
			index--;
		}
		a[index+1]=currElement;
	}
}

int main()
{
	printf("Enter the size of the array : ");
	int size;
	scanf("%d",&size);
	int a[size];

	printf("Enter the %d elements : ",size);

	for(int i=0;i<size;i++)
	scanf("%d",&a[i]);

	Sort(a,size);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");

	printf("Enter the element you want to search for : ");
	int element;
	scanf("%d",&element);

	int l=0, h=size-1, mid;
	while(l<=h)
	{
		mid=l+(h-l)/2;
		if(a[mid]==element) {
			printf("\nElement found at position : %d\n\n",mid+1);
			return 0;
		}
		else if(element>a[mid]) l=mid+1;
		else h=mid-1;
	}
	
	printf("\nElement not found!\n\n");
	return 0;
}
