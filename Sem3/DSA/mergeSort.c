#include<stdio.h>
#include<stdlib.h>

void display(int a[], int size) {
    printf("Array: [");
    for(int i=0; i<size-1; i++)
    printf("%d, ", a[i]);
    printf("%d]\n", a[size-1]);
}

void merge(int a[], int start, int mid, int end) {
    int i=start, j=mid+1, k=0;
    int len = end-start+1;
    int *temp = malloc(len * sizeof(int));

    while(i<=mid && j<=end) {
        if(a[i] <= a[j]) {
            temp[k] = a[i];
            i++;
        }
        else {
            temp[k] = a[j];
            j++;
        }
        k++;
    }

    while(i<=mid) {
        temp[k] = a[i];
        i++;
        k++;
    }
    
    while(j<=end) {
        temp[k] = a[j];
        j++;
        k++;
    }

    for(int i=0; i<len; i++) {
        a[start+i] = temp[i];
    }

    free(temp);
}

void mergeSort(int a[], int start, int end) {
    if(start < end) {
        int mid = start + (end-start)/2;
        mergeSort(a, start, mid);
        mergeSort(a, mid+1, end);
        merge(a, start, mid, end);
    }
}

int main() {
    printf("Size of array: ");
    int size;
    if(scanf("%d", &size) != 1) {
        printf("Invalid input for 'Size of the array'.\n");
        return 1;
    }
    
    if(size<=0) {
        printf("Size should be greater than 0.\n");
        return 1;
    }

    int *a = malloc(size * sizeof(int));
    if(!a) {
        printf("Memory Allocation failed!");
        return 1;
    }

    for(int i=0; i<size; i++) {
        if(scanf("%d", &a[i]) != 1) {
            printf("Invalid input for array element.\n");
            free(a);
            return 1;
        }
    }

    display(a, size);

    mergeSort(a, 0, size-1);

    printf("Sorted ");
    display(a, size);

    free(a);
    return 0;
}