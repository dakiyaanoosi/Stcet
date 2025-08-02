// program to multiply two matrices.

#include<stdio.h>
int main()
{
    printf("MATRIX 1\n");
    int r1,c1;
    printf("Rows : ");
    scanf("%d",&r1);
    printf("Columns : ");
    scanf("%d",&c1);

    int mat1[r1][c1];

    printf("Enter MATRIX 1 (Row-wise) : \n");
    for(int i=0;i<r1;i++)
        for(int j=0;j<c1;j++)
        scanf("%d",&mat1[i][j]);

        
    printf("MATRIX 2\n");
    int r2,c2;
    do
    {
        printf("Rows : ");
        scanf("%d",&r2);
    } while(c1!=r2);
    printf("Columns : ");
    scanf("%d",&c2);

    int mat2[r2][c2];

    printf("Enter MATRIX 2 (Row-wise) : \n");
    for(int i=0;i<r2;i++)
        for(int j=0;j<c2;j++)
        scanf("%d",&mat2[i][j]);

    int mat[r1][c2];

    printf("Result of MULTIPLICATION\n");
    for(int i=0;i<r1;i++)
    {
        for(int j=0;j<c2;j++)
        {
            int sum=0;
            for(int k=0;k<r2;k++)
            {
                sum+=(mat1[i][k]*mat2[k][j]);
            }
            mat[i][j]=sum;
            printf("%-4d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}