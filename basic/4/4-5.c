#include <stdio.h>

int calculateTotalSum(int data[], int size) {
    int sum = 0 ; 
    for (int i = 0; i < size; i++) {
        sum += data[i] ; 
    }
    return sum ;
}

int main() {
    int values[6] ; 
    int total ;

    for (int i = 0; i < 6; i++) {
        scanf("%d", &values[i]) ;
    }

    total = calculateTotalSum(values, 6) ;

    printf("Data: ") ;
    for (int i = 0; i < 6; i++) printf("%d ", values[i]) ; 
    
    printf("\nTotal Sum: %d\n", total) ; 

    return 0 ;
}