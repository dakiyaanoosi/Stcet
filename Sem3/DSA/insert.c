// Menu Driven Program for Array insertions

#include<stdio.h>

void print(int a[], int size) {
    printf("\nArray : ");
    for(int i=0;i<size;i++) {
        printf("%d  ", a[i]);
    }
    printf("\n");
}

void showMenu() {
    printf("\n1. Insert at 1st position\n2. Insert at the Last position\n3. Insert at any position\n\nType anything else to quit\n\n");
}

void insertFirst(int a[], int *size, int element) {
    for(int i=*size;i>0;i--)
    a[i]=a[i-1];

    (*size)++;
    a[0]=element;
}

void insertLast(int a[], int *size, int element) {
    a[*size]=element;
    (*size)++;
}

void insertAny(int a[], int *size, int index, int element) {
    if(index>=0 && index<=*size) {
        for(int i=*size;i>index;i--)
        a[i]=a[i-1];

        (*size)++;
        a[index]=element;
    }
    else printf("Wrong position entered!\n");
}

int main() {
    int size, loop=1;
    printf("Number of elements in the array : ");
    scanf("%d", &size);

    int a[size+100];
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
            case '1': printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            insertFirst(a, &size, element);
            print(a,size);
            break;

            case '2': printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            insertLast(a, &size, element);
            print(a,size);
            break;

            case '3': printf("Insert at position (1 - %d): ", size);
            scanf("%d", &index);
            index-=1;
            printf("Enter the element to be inserted : ");
            scanf("%d", &element);
            insertAny(a, &size, index, element);
            print(a,size);
            break;

            default: loop=0;
        }
    }
    return 0;
}
