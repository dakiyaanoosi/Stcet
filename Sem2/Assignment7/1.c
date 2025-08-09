// Program to add two matrices.

#include<stdio.h>
int main()
{
    int r,c;
    printf("Rows : ");
    scanf("%d",&r);
    printf("Columns : ");
    scanf("%d",&c);

    int mat1[r][c];
    int mat2[r][c];
    int mat[r][c];

    printf("Enter MATRIX 1 (Row-wise) : \n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        scanf("%d",&mat1[i][j]);

    printf("Enter MATRIX 2 (Row-wise) : \n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
        {
            scanf("%d",&mat2[i][j]);
            mat[i][j]=mat1[i][j]+mat2[i][j];
        }
    
    printf("MATRIX 1  \tMATRIX 2\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%-4d",mat1[i][j]);

        printf("\t");

        for(int j=0;j<c;j++)
        printf("%-4d",mat2[i][j]);

        printf("\n");
    }

    printf("\nResult of ADDITION \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%-4d",mat[i][j]);
        printf("\n");
    }
    return 0;
}