#include<stdio.h>

void printArray(int a[], int size){
    printf("\nArray: [");
    for(int i=0; i<size-1; i++)
    printf("%d, ", a[i]);
    
    printf("%d]\nSize: %d\n", a[size-1], size);
}

void insertFirst(int a[], int *size){
    int element;
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    for(int i=*size-1; i>=0; i--)
    a[i+1]=a[i];

    a[0]=element;
    *size+=1;
    printArray(a, *size);
}

void insertlast(int a[], int *size) {
    int element;
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    a[*size] = element;
    *size+=1;  
    printArray(a, *size); 
}

void insertAny(int a[], int *size) {
    
    int index, element;
    printf("Insert at index: ");
    scanf("%d", &index);
    if(index<0 || index>*size) {
        printf("Invalid index!");
        return;
    };
    printf("Enter the element you want to insert: ");
    scanf("%d", &element);

    for(int i=*size-1; i>=index; i--)
    a[i+1] = a[i];

    a[index] = element;
    *size+=1;
    printArray(a, *size);
}

void showMenu() {
    printf("\nMenu\n1. Insert at the first position\n2. Insert at the last position\n3. Insert at any position\n\nEnter anything else to exit\n\nInput: ");
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
            case '1': insertFirst(a, &size);
                      break;
            case '2': insertlast(a, &size);
                      break;
            case '3': insertAny(a, &size);
                      break;
            default:  return 0;
        } 
    }
}
