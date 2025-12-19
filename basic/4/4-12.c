#include <stdio.h>

void transposeMatrix(int src[2][3], int dst[3][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            dst[j][i] = src[i][j] ; 
        }
    }
}

void multiplyMatrix(int A[2][3], int BT[3][2], int C[2][2]) {
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            C[i][j] = 0 ;
            for (int k = 0; k < 3; k++) {
                C[i][j] += A[i][k] * BT[k][j] ;
            }
        }
    }
}

void printMatrix(int rows, int cols, int mat[rows][cols], char name[]) {
    printf("\nMatrix %s (%dx%d):\n", name, rows, cols) ;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]) ;
        }
        printf("\n") ;
    }
}

int main() {
    int A[2][3], B[2][3], BT[3][2], C[2][2] ;

    printf("--- Input Data ---\n") ;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &A[i][j]) ;
        }
    }
    printf("\n") ;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            scanf("%d", &B[i][j]) ;
        }
    }

    transposeMatrix(B, BT) ;
    multiplyMatrix(A, BT, C) ; 

    printf("\n--- Matrix Display ---\n") ;
    printMatrix(2, 3, A, "A") ; 
    printMatrix(2, 3, B, "B") ; 
    printMatrix(3, 2, BT, "B_Transpose") ; 
    
    printf("\n--------------------------\n") ;
    printMatrix(2, 2, C, "Result C (A * B_T)") ; 

    return 0 ;
}