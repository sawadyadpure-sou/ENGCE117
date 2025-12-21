#include <stdio.h>

int calculate_sum(int array[], int size) {
    int sum = 0 ;
    for (int i = 0 ; i < size ; i++) {
        sum += array[i] ;
    }
    return sum ;
}

int main() {
    int numbers[5] ; 
    int total_sum ;
    float average ;

    for (int i = 0 ; i < 5 ; i++) {
        scanf("%d", &numbers[i]) ;
    }

    total_sum = calculate_sum(numbers, 5) ;

    average = (float)total_sum / 5 ;

    printf("----------------------------------\n") ;
    printf("number: ") ;
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d ", numbers[i]) ;
    }
    printf("\nTotal Sum: %d\n", total_sum) ;
    printf("Average: %.2f\n", average) ;
    printf("----------------------------------\n") ;

    return 0 ;
}