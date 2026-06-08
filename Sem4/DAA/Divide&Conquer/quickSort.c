#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>

void swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}

int partition(int a[], int start, int end, char P) {
	if(P=='L' || P=='l') {
		int pivot = a[end];
		int index=start;
		for(int i=start; i<end; i++) {
			if(a[i]<pivot) {
				swap(&a[index++], &a[i]);
			}
		}
		swap(&a[index], &a[end]);
		return index;
	}

	else if(P=='F' || P == 'f') {
		int pivot = a[start];
		int index=start;
		for(int i=start+1; i<=end; i++) {
			if(a[i]<pivot) {
				swap(&a[++index], &a[i]);
			}
		}
		swap(&a[index], &a[start]);
		return index;
	}

	else {
		printf("Invalid pivot choice!\n");
		exit(1);
	}

	return -1;
}

void quickSort(int a[], int start, int end, char P) {
	if(start<end) {
		int pivotIndex = partition(a, start, end, P);
		quickSort(a, start, pivotIndex-1, P);
		quickSort(a, pivotIndex+1, end, P);
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

	char P;
	printf("Set pivot! First or Last [F/L]: ");
	scanf(" %c", &P);

	clock_t s, e;
	s=clock();
	quickSort(a, 0, size-1, P);
	e=clock();

	double time_taken = ((double)(e-s))/CLOCKS_PER_SEC;
	struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);
	
	printf("Sorted ");
	printArray(a, size);	
	
	printf("Time taken: %f\n", time_taken);
	printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);
	
	return 0;
}