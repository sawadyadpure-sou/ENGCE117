#include <stdio.h>

void swap_values(int *a, int *b) {
    int temp ;
    
    temp = *a ;    
    *a = *b ;      
    *b = temp ;    
}

int main() {
    int num1, num2 ;

    scanf("%d", &num1) ;
    scanf("%d", &num2) ;

    printf("\n--- Before Swap ---\n") ;
    printf("num1 = %d, num2 = %d\n", num1, num2) ;

    swap_values(&num1, &num2) ;

    printf("\n--- After Swap (Report) ---\n") ;
    printf("Initial num1 was swapped to: %d %d\n", num1,num2) ;

    return 0 ;
}