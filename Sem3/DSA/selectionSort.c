#include<stdio.h>

void selectionSort(int a[], int size) {
    for(int i=0; i<size-1; i++) {
        int min=i;
        for(int j=i+1; j<size; j++) {
            if(a[j]<a[min]) {
                min=j;
            }
        }
        if(min!=i) {
            int temp=a[i];
            a[i]=a[min];
            a[min]=temp;
        }
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

	selectionSort(a,size);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
    return 0;
}