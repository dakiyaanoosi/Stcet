#include<stdio.h>
#include<stdlib.h>

void display(int a[], int size) {
    printf("Array: [");
    for(int i=0; i<size-1; i++)
    printf("%d, ", a[i]);
    printf("%d]\n", a[size-1]);
}

int MAX(int a[], int size) {
    int max = a[0];
    for(int i=1; i<size; i++)
    if(a[i] > max) max=a[i];

    return max;
}

void countingSort(int a[], int size, int place) {
    int *count = calloc(10, sizeof(int));
    if(!count) {
        printf("Memory Allocation failed!");
        return;
    }
    int *temp = malloc(size*sizeof(int));
    if(!temp) {
        printf("Memory Allocation failed!");
        return;
    }

    for(int i=0; i<size; i++) {
        int digit = (a[i]/place)%10;
        count[digit] += 1;
    }

    for(int i=1; i<10; i++) {
        count[i] += count[i-1];
    }    

    for(int i=size-1; i>=0; i--) {
        int digit = (a[i]/place)%10;
        temp[count[digit] - 1] = a[i];
        count[digit]--;
    }

    for(int i=0; i<size; i++)
    a[i] = temp[i];

    free(temp);
    free(count);
}

void radixSort(int a[], int size) {
    int max = MAX(a, size);

    for(int place=1; max/place > 0; place*=10) {
        countingSort(a, size, place);
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
            return 1;
        }
    }

    display(a, size);

    radixSort(a, size);
    printf("Sorted ");
    display(a, size);

    free(a);
    return 0;
}
