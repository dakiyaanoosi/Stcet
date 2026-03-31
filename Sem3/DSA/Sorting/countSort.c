#include<stdio.h>
#include<stdlib.h>

//single digit elements

void countSort(int a[], int size) {
    int *count = (int*)calloc(10, sizeof(int));
    int *temp = (int*)malloc(size*sizeof(int));

    for(int i=0; i<size; i++)
    count[a[i]]++;

    for(int i=1; i<10; i++)
    count[i] += count[i-1];

    for(int i=size-1; i>=0; i--) {
        temp[count[a[i]]-1] = a[i];
        count[a[i]]--;
    }

    for(int i=0; i<size; i++)
    a[i]=temp[i];

    free(temp);
    free(count);
}