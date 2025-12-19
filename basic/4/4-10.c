#include <stdio.h>

void displayTable(int data[3][3]) {
    printf("\n--- Array Table Report ---\n") ;

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            printf("%d\t", data[i][j]) ; 
        }
        printf("\n") ; 
    }
}

int main() {
    int data[3][3] ;

    for (int i = 0; i < 3; i++) { 
        for (int j = 0; j < 3; j++) { 
            scanf("%d", &data[i][j]) ; 
        }
    }

    displayTable(data) ;

    return 0 ;
}