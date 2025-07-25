// Menu Driven Program for Array deletions

#include<stdio.h>

void print(int a[], int size) {
    printf("\nArray : ");
    for(int i=0;i<size;i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void showMenu() {
    printf("\n1. Delete the first element\n2. Delete the last Element\n3. Delete element at any position\n\nType anything else to quit\n\n");
}

void deleteFirst(int a[], int *size) {
    for(int i=0;i<*size;i++)
    a[i]=a[i+1];

    (*size)--;
}

void deleteLast(int *size) {
    (*size)--;
}

void deleteAny(int a[], int *size, int index) {
    if(index>=0 && index<=*size) {
        for(int i=index;i<*size;i++)
        a[i]=a[i+1];

        (*size)--;
    }
    else printf("Wrong position entered!\n");
}

int main() {
    int size, loop=1;
    printf("Number of elements in the array : ");
    scanf("%d", &size);

    int a[size];
    printf("Enter the %d elements : ", size);
    for(int i=0;i<size;i++) {
        scanf("%d", &a[i]);
    }

    print(a,size);

    char ch;
    int element,index;

    while(loop) {
        showMenu();
        printf("Enter your choice [1/2/3] : ");
        scanf(" %c", &ch);
        
        switch(ch) {
            case '1': deleteFirst(a, &size);
            print(a,size);
            break;

            case '2': deleteLast(&size);
            print(a,size);
            break;

            case '3': printf("Delete at position (1 - %d): ", size);
            scanf("%d", &index);
            index-=1;
            deleteAny(a, &size, index);
            print(a,size);
            break;

            default: loop=0;
        }
    }
}
