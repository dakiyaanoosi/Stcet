#include<stdio.h>
#include<stdlib.h>

void display(int a[], int size) {
    printf("Array: [");
    for(int i=0; i<size-1; i++)
    printf("%d, ", a[i]);
    printf("%d]\n", a[size-1]);
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int a[], int start, int end) {
    int pivot = a[end], index=start;
    for(int i=start; i<end; i++) {
        if(a[i] <= pivot) {
            swap(&a[index], &a[i]);
            index++;
        }
    }
    swap(&a[index], &a[end]);
    return index;
}

void quickSort(int a[], int start, int end) {
    if(start<end) {
        int pivotIndex = partition(a, start, end);
        quickSort(a, start, pivotIndex-1);
        quickSort(a, pivotIndex+1, end);
    }
}

int main() {
    printf("Enter the size of the array: ");
    int size;
    if(scanf("%d", &size) != 1) {
        printf("Invalid input for 'Size of the array'.\n");
        return 1;
    }
    if(size<=0) {
        printf("No elements to enter.\n");
        return 1;
    }

    int *a = malloc(size * sizeof(int));
    if(!a) {
        printf("Memory Allocation failed!");
        return 1;
    }

    printf("Enter the %d elements:\n", size);
    for(int i=0; i<size; i++) {
        if(scanf("%d", &a[i]) != 1) {
            printf("Invalid input for 'element of the array'.\n");
            free(a);
            return 1;
        }
    }

    display(a, size);

    quickSort(a, 0, size-1);
    printf("Sorted ");
    display(a, size);

    free(a);
    return 0;
}
