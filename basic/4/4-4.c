#include <stdio.h>

void count(int numbers[], int size, int *even, int *odd) {
    *even = 0 ;
    *odd = 0 ;
    for (int i = 0; i < size; i++) {
        if (numbers[i] % 2 == 0) {
            (*even)++ ;
        } else {
            (*odd)++ ;
        }
    }
}

int main() {
    int nums[5] ; 
    int evenCount, oddCount ;

    for (int i = 0; i < 5; i++) {
        printf("Number %d: ", i + 1) ;
        scanf("%d", &nums[i]) ;
    }

    count(nums, 5, &evenCount, &oddCount) ;

    printf("Numbers recorded: ") ;
    for (int i = 0; i < 5; i++) {
        printf("%d ", nums[i]) ;
    }
    
    printf("\nTotal Even numbers: %d\n", evenCount) ;
    printf("Total Odd numbers: %d\n", oddCount) ;

    return 0 ;
}