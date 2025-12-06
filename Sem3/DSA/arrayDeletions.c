#include<stdio.h>

void printArray(int a[], int size){
    printf("\nArray: [");
    for(int i=0; i<size-1; i++)
    printf("%d, ", a[i]);

    printf("%d]\nSize: %d\n", a[size-1], size);
}

void deleteFirst(int a[], int*size) {
    if(*size<=0) {
        printf("Array is Empty!");
        return;
    }

    for(int i=0; i<*size-1; i++)
    a[i]=a[i+1];

    *size-=1;
    printArray(a, *size);
}

void deleteLast(int a[], int *size) {
    if(*size<=0) {
        printf("Array is Empty!");
        return;
    }

    *size-=1;
    printArray(a, *size);
}

void deleteAny(int a[], int *size) {
    if(*size<=0) {
        printf("Array is Empty!");
        return;
    }

    int index;
    printf("Delete at index: ");
    scanf("%d", &index);
    if(index<0 || index>*size-1) {
        printf("Invalid index!\n");
        return;
    };

    for(int i=index; i<*size-1; i++)
    a[i]=a[i+1];

    *size-=1;
    printArray(a, *size);
}

void showMenu() {
    printf("\nMenu\n1. Delete the first element\n2. Delete the last element\n3. Delete element at any index\n\nEnter anything else to exit\n\nInput: ");
}

int main() {
    printf("Enter the size of the array: ");
    int size;
    scanf("%d", &size);
    int a[100];
    printf("Enter the %d elements: ",size);
    for(int i=0;i<size;i++)
    scanf("%d", &a[i]);
    
    printArray(a, size);

    char ch;
    while(1) {
        showMenu();
        scanf(" %c", &ch);
        switch(ch) {
            case '1': deleteFirst(a, &size);
                      break;
            case '2': deleteLast(a, &size);
                      break;
            case '3': deleteAny(a, &size);
                      break;
            default:  return 0;
        }
    }
}
