#include<stdio.h> 

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left-1;

    for(int j=left; j<right; j++) {
        if(a[j]<pivot) {
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[right]);
    return i+1;
}

void quickSort(int a[], int left, int right) {
    if(left<right) {
        int pivotIndex = partition(a, left, right);
        quickSort(a, left, pivotIndex-1);
        quickSort(a, pivotIndex+1, right);
    }
}

int main() {
    printf("Enter the size of the array: ");
    int size;

    scanf("%d",&size);
	int a[size];

	printf("Enter the %d elements : ",size);

	for(int i=0;i<size;i++)
	scanf("%d",&a[i]);

	quickSort(a,0, size-1);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
    return 0;
}
