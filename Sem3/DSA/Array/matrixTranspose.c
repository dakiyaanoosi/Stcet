#include<stdio.h>
int main()
{
    int r,c;
    printf("Rows : ");
    scanf("%d",&r);
    printf("Columns : ");
    scanf("%d",&c);

    int mat1[r][c];
    int mat2[c][r];
	
    printf("Enter the MATRIX (Row-wise) : \n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
	{
            scanf("%d",&mat1[i][j]);
	    mat2[j][i]=mat1[i][j];
	}

    printf("\nMATRIX\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%-4d",mat1[i][j]);
	
	printf("\n");
    }

    printf("\nTranspose MATRIX : \n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%-4d",mat2[i][j]);
        printf("\n");
    }
    
    return 0;
}
