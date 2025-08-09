// Program to input and display student details using structure and functions.


#include <stdio.h>
struct Student
{
    char name[50];
    int roll;
};

void input(struct Student *s)
{
    printf("Roll no. : ");
    scanf("%d", &s->roll);
    printf("Name: ");
    scanf(" %[^\n]", s->name);
}

void display(struct Student s)
{
    printf("\n\nStudent Details !!\n\n");
    printf("Name: %s\n", s.name);
    printf("Roll no. : %d\n", s.roll);
}

int main()
{
    struct Student st;
    input(&st);
    display(st);
    return 0;
}