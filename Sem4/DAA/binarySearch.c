#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void insertionSort(int a[], int size) {
	for(int i=1; i<size; i++) {
		int currentElement = a[i];
		int index=i-1;
		while(index>=0 && currentElement<a[index]) {
			a[index+1]=a[index];
			index--;
		}
		a[index+1]=currentElement;
	}
}

int binarySearch(int a[], int start, int end, int key) {
	if(start>end) return -1;
	int mid=start + (end-start)/2;
	if(a[mid]==key) return mid;
	else if(key>a[mid]) return binarySearch(a, mid+1, end, key);
	else return binarySearch(a, start, mid-1, key);
}

void printArray(int a[], int size) {
	printf("Array: ");
	for(int i=0; i<size; i++)
	printf("%d  ", a[i]);
	printf("\n");
}

int main() {
	printf("Enter the size of the array: ");
	int size;
	scanf("%d", &size);
	if(size<=0) return 0;

	int a[size];

	printf("Generate Random elements? [y/n]: ");
	char random;
	scanf(" %c", &random);
	if(random == 'y' || random == 'Y') {
		srand(time(NULL));
		for(int i=0; i<size; i++) {
			int num = rand()%100;
			a[i]=num;
		}

		printf("Generated ");
		printArray(a, size);
	}
	else {
		printf("Enter the %d elements: ", size);
		for(int i=0; i<size; i++)
		scanf("%d", &a[i]);

		printf("Entered ");
		printArray(a, size);
	}

	insertionSort(a, size);

	printf("Sorted ");
	printArray(a, size);	
	
	int ch;
	clock_t s, e;

	while(1) {
		int key;
		printf("Enter the key: ");
		scanf("%d", &key);
		
		s=clock();
		int index = binarySearch(a, 0, size-1, key);
		e=clock();

		double time_taken = ((double)(e-s))/CLOCKS_PER_SEC;

		if(index==-1)
			printf("%d not found in the rray!\n", key); 
		else
			printf("%d found at index %d.\n", key, index);
		printf("Time Taken: %f\n", time_taken);

		printf("\n1. Search Again\n2. Enter new Array\n3. Enter anything else to exit\nEnter your choice [1/2]: ");
		scanf("%d", &ch);
		
		if(ch==1) continue;
		else if(ch==2) return main();
		else break;
	}
	
	return 0;
}