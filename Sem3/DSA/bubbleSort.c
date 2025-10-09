#include<stdio.h>

void bubbleSort(int a[], int size) {
    for(int i=0; i<size-1; i++) {
        int swapped=0;
        for(int j=0; j<size-1-i; j++) {
            if(a[j] > a[j+1]) {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                swapped=1;
            }
        }
        if(!swapped) {
            break;
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

	bubbleSort(a,size);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
    return 0;
}