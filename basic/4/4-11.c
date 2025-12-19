#include <stdio.h>

int calculateMatrixSum(int matrix[2][4]) {
    int sum = 0 ; 

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            sum += matrix[i][j] ; 
        }
    }
    return sum ;
}

int main() {
    int matrix[2][4] ;
    int totalSum ;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            scanf("%d", &matrix[i][j]) ;
        }
    }

    totalSum = calculateMatrixSum(matrix) ;

    printf("\n--- Matrix Report ---\n") ;
    printf("Matrix Data:\n") ;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", matrix[i][j]) ;
        }
        printf("\n") ; 
    }

    printf("\nTotal Sum of all elements: %d\n", totalSum) ;

    return 0 ;
}