#include<stdio.h>

void merge(int a[], int left, int mid, int right) {
    int s1 = mid-left+1;
    int s2 = right-mid;
    int L[s1], R[s2];

    int i, j, k=left;
    for(i=0; i<s1; i++)
    L[i]=a[left+i];
    for(j=0; j<s2; j++)
    R[j]=a[mid+1+j];

    i=0;
    j=0;

    while(i<s1 && j<s2) {
        if(L[i] <= R[j]) {
            a[k]=L[i];
            i++;
        }
        else {
            a[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<s1) {
        a[k] = L[i];
        i++;
        k++;
    }
    while(j<s2) {
        a[k]=R[j];
        j++;
        k++;
    }
}

void mergeSort(int a[], int left, int right) {
    if(left<right) {
        int mid=left+(right-left)/2;
        mergeSort(a, left, mid);
        mergeSort(a, mid+1, right);

        merge(a, left, mid, right);
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

	mergeSort(a,0, size-1);

	printf("\nSorted Array : ");
	for(int i=0;i<size;i++)
	printf("%d  ",a[i]);
	printf("\n");
    return 0;
}
