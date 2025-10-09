#include<stdio.h>

void insertionSort(int a[], int size) {
    for(int i=1; i<size; i++) {
        int currElement=a[i];
        int index=i-1;
        while(index>=0 && currElement<a[index]) {
            a[index+1]=a[index];
            index--;
        }
        a[index+1]=currElement;
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

	insertionSort(a,size);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
    return 0;
}
