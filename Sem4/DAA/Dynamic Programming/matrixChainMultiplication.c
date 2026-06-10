#include<stdio.h>
#include<limits.h>

void printOrder(int n, int s[n][n], int i, int j) {
    if(i == j) {
        printf("%c", 'A' + i);
        return;
    }

    printf("(");
    printOrder(n, s, i, s[i][j]);
    printOrder(n, s, s[i][j] + 1, j);
    printf(")");
}

int matrixChain(int p[], int n) {
    int m[n][n];
    int s[n][n];

    for(int i=0; i<n; i++)
        m[i][i] = 0;
    
    for(int L=2; L<=n; L++) {
        for(int i=0; i <= n-L; i++) {
            int j=i+L-1;
            m[i][j] = INT_MAX;

            for(int k=i; k<j; k++) {
                int cost  = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(cost < m[i][j]) {
                    m[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("Optimal Parenthesization: ");
    printOrder(n, s, 0, n-1);
    printf("\n");
    return m[0][n-1];
}

int main() {
    int n;
    printf("Number of matrices: ");
    scanf("%d", &n);

    int p[n+1];
    printf("Enter the dimension array (%d elements): ", n+1);
    for(int i=0; i<=n; i++)
        scanf("%d", &p[i]);
    
    printf("Minimum number of Scalar Multiplications: %d\n", matrixChain(p, n));

    return 0;
}