#include <stdio.h>

int countFrequency(int numbers[], int n, int searchValue) {
    int count = 0 ; 

    for (int i = 0; i < n; i++) {
        if (numbers[i] == searchValue) {
            count++ ; 
        }
    }
    return count ;
}

int main() {
    int N, searchValue, frequency ;
    int data[10] ;

    scanf("%d", &N) ;

    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]) ;
    }

    printf("Enter Search Value: ") ;
    scanf("%d", &searchValue) ;

    frequency = countFrequency(data, N, searchValue) ;

    printf("\n--- Search Report ---\n") ;
    printf("Recorded data: ") ;
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]) ; 
    }
    
    printf("\nSearch Value: %d\n", searchValue) ; 
    printf("Frequency of found: %d\n", frequency) ; 

    return 0 ;
}