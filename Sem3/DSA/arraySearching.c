// Menu driven program for searching using Linear and Binary Search algorithms

#include<stdio.h>

int element;
void printArray(int a[],int size)
{
	printf("\nArray : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
}

void showMenu()
{
	printf("\n\nMenu\n1.Linear Search\n2.Binary Search\n3.Change the Array\n\nPress anything else to quit.\n\n");
}

void takeKey()
{
	printf("Enter the element you want to search for : ");
	scanf("%d",&element);
}

void printResult(int index)
{
	if(index==-1) printf("\nElement not found!\n");
	else printf("\nElement found at position %d !\n",index);
}

void Sort(int a[], int size)
{
	for(int i=1;i<size;i++)
	{
		int currElement = a[i];
		int index=i-1;
		while(currElement<a[index] && index>=0)
		{
			a[index+1]=a[index];
			index--;
		}
		a[index+1]=currElement;
	}
}

int linearSearch(int a[], int size) 
{
	for(int i=0;i<size;i++)
	{
		if(a[i]==element)
		{
			return i+1;
		}
	}
	return -1;
}

int binarySearch(int a[], int l, int h)
{
	if(l>h) return -1;

	int mid=l+(h-l)/2;

	if(a[mid]==element) {
		return mid+1;
	}
	else if(element>a[mid]) l=mid+1;
	else h=mid-1;
	
	return binarySearch(a,l,h);
}

int main()
{
	int size,sorted=0,index;
	printf("Enter the size of the array : ");
	scanf("%d",&size);
	int a[size];

	printf("Enter the %d elements : ",size);

	for(int i=0;i<size;i++)
	scanf("%d",&a[i]);

	printArray(a,size);

	int loop=1;
	while(loop)
	{
		showMenu();

		printf("Enter your choice [1/2/3] : ");
		char ch;
		scanf(" %c",&ch);

		switch(ch)
		{
			case '1': printf("\n\nLinear Search!\n");
			printArray(a, size);
			takeKey();
			index = linearSearch(a, size);
			printResult(index);
			break;
		
			case '2': printf("\n\nBinary Search!\n");
			if(!sorted) {
				Sort(a, size);
				sorted=1;
			}
			printArray(a, size);
			takeKey();
			int index = binarySearch(a, 0, size-1);
			printResult(index);
			break;

			case '3': return main();
			break;

			default: loop=0;
		}
	}
	return 0;
}
