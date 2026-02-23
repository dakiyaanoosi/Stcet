#include<stdio.h>

int main() {
    printf("Enter size of the array: ");
    int size;
    scanf("%d", &size);
    int a[size];

    printf("Enter the %d elements: ",size);
    for(int i=0;i<size;i++)
    scanf("%d", &a[i]);

    printf("Enter the element you want to search for: ");
    int key;
    scanf("%d", &key);

    for(int i=0;i<size;i++) {
        if(a[i]==key) {
            printf("%d found at index %d\n", key, i);
            return 0;
        }
    }
    printf("%d not found in the array!\n", key);
    return 0;
}
