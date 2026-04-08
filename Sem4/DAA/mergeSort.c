#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void merge(int a[], int start, int mid, int end) {
	int i=start, j=mid+1, k=0;
	int len=end-start+1;
	int *temp = (int*)malloc(10*sizeof(int));
	
	while(i<=mid && j<=end) {
		if(a[i] <= a[j]) temp[k++] = a[i++];
		else temp[k++] = a[j++];
	}
	
	while(i<=mid) temp[k++] = a[i++];
	while(j<=end) temp[k++] = a[j++];

	for(int i=0; i<len; i++)
	a[start+i]=temp[i];
	
	free(temp);
}

void mergeSort(int a[], int start, int end) {
	if(start<end) {
		int mid = start + (end-start)/2;
		mergeSort(a, start, mid);
		mergeSort(a, mid+1, end);
		merge(a, start, mid, end);
	}
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

	clock_t s, e;
	s=clock();
	mergeSort(a, 0, size-1);
	e=clock();

	double time_taken = ((double)(e-s))/CLOCKS_PER_SEC;
	
	printf("Sorted ");
	printArray(a, size);	
	
	printf("Time taken: %.3f: \n", time_taken);
	
	return 0;
}