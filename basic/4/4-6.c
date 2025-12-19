#include <stdio.h>

float grade(int scores[], int size, int *aboveCount) {
    int sum = 0 ;
    *aboveCount = 0 ;
    
    for (int i = 0; i < size; i++) sum += scores[i] ; 
    
    float avg = (float)sum / size ; 
    
    for (int i = 0; i < size; i++) {
        if (scores[i] > avg) (*aboveCount)++ ; 
    }
    return avg ;
}

int main() {
    int scores[5] ; 
    int count ;

    for (int i = 0; i < 5; i++) {
        scanf("%d", &scores[i]) ;
    }

    float avg = grade(scores, 5, &count) ;

    printf("\nAverage: %.2f\n", avg) ; 
    printf("Students above average: %d\n", count) ; 

    return 0 ;
}