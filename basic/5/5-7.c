#include <stdio.h>

void sort_array_ascending(int array[], int size) {
    int temp ; 
    for (int i = 0 ; i < size - 1 ; i++) {
        for (int j = 0 ; j < size - i - 1 ; j++) {
            if (array[j] > array[j + 1]) {
                temp = array[j] ;
                array[j] = array[j + 1] ;
                array[j + 1] = temp ;
            }
        }
    }
}

int main() {
    int numbers[5] ; 
    
    for (int i = 0 ; i < 5 ; i++) {
        printf("Number %d: ", i + 1) ;
        scanf("%d", &numbers[i]) ;
    }

    printf("\n---------------------------\n") ;
    printf("Original Array: ") ;
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d ", numbers[i]) ;
    }
    printf("\n") ;
    sort_array_ascending(numbers, 5) ;

    printf("Sorted Array : ") ;
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d ", numbers[i]) ;
    }
    printf("\n---------------------------\n") ;

    return 0 ;
}