#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<sys/resource.h>

struct Pair {
    int min;
    int max;
};

struct Pair findMinMax(int a[], int start, int end) {
    struct Pair result, left, right;

    if(start == end) {
        result.min = result.max = a[start];
        return result;
    }

    if(end == start + 1) {
        if(a[start] < a[end]) {
            result.min = a[start];
            result.max = a[end];
        }
        else {
            result.min = a[end];
            result.max = a[start];
        }
        return result;
    }

    int mid = start + (end - start)/2;

    left = findMinMax(a, start, mid);
    right = findMinMax(a, mid+1, end);

    result.min = (left.min < right.min) ? left.min : right.min;
    result.max = (left.max > right.max) ? left.max : right.max;

    return result;
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
    if(size <= 0) return 0;

    int a[size];

    printf("Generate Random elements? [y/n]: ");
    char random;
    scanf(" %c", &random);

    if(random == 'y' || random == 'Y') {
        srand(time(NULL));
        for(int i=0; i<size; i++) {
            a[i] = rand()%100;
        }
    }
    else {
        printf("Enter the %d elements: ", size);
        for(int i=0; i<size; i++)
            scanf("%d", &a[i]);

        printf("Entered ");
        printArray(a, size);
    }

    clock_t s, e;
    s = clock();
    struct Pair result = findMinMax(a, 0, size-1);
    e = clock();

    double time_taken = ((double)(e-s))/CLOCKS_PER_SEC;
    struct rusage usage;
	getrusage(RUSAGE_SELF, &usage);

    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);
    printf("Time taken: %f\n", time_taken);
    printf("Memory Usage (Max Resident Set Size): %ld KB\n", usage.ru_maxrss);

    return 0;
}