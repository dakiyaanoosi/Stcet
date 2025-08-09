// Program to find the Trace of a Matrix

#include<stdio.h>
int main()
{
    int r,c;
    printf("Rows : ");
    scanf("%d",&r);
    printf("Columns : ");
    scanf("%d",&c);

    if(r!=c) {
        printf("Error: Please enter a square matrix!\n\n");
        return main();
    }

    int mat[r][c];
    int trace=0;
	
    printf("Enter the MATRIX (Row-wise) : \n");
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
	{
            scanf("%d",&mat[i][j]);
	    if(i==j) trace+=mat[i][j];
	}

    printf("\nMATRIX\n");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        printf("%-4d",mat[i][j]);
	
	printf("\n");
    }

    printf("\nTrace of the Matrix : %d\n", trace);
    return 0;
}
