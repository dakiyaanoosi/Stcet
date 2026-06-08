#include<stdio.h>

void insertionSort(int den[], int n) {
	for(int i=1; i<n; i++) {
		int currentElement = den[i];
		int index=i-1;
		while(index>=0 && currentElement>den[index]) {
			den[index+1]=den[index];
			index--;
		}
		den[index+1]=currentElement;
	}
}

void coinChange(int den[], int n, int amt) {
    for(int i=0; i<n; i++) {
        if(amt == 0) break;
        int count = amt/den[i];
        amt = amt % den[i];
        if(count != 0)
            printf("%d x %d = %d\n", den[i], count, den[i]*count);
    }

    if(amt != 0)
        printf("Remaining amount: %d\n", amt);
}

int main() {
    int n;
    printf("Number of denominations: ");
    scanf("%d", &n);

    int den[n];
    printf("Enter the denoinations: ");
    for(int i=0; i<n; i++)
        scanf("%d", &den[i]);

    insertionSort(den, n);

    printf("Denominations: ");
    for(int i=0; i<n; i++)
        printf("%d  ", den[i]);
    printf("\n");

    int amt;
    printf("Enter the Amount: ");
    scanf("%d", &amt);

    coinChange(den, n, amt);

    return 0;
}