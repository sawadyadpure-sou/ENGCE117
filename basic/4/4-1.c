#include <stdio.h>

void rev(int arr[], int n) {
    for (int i = n - 1 ; i >= 0 ; i--) {
        printf("%d ", arr[i]) ;
    }
    printf("\n") ;
}

int main() {
    int N ;

    if (scanf("%d", &N) != 1) return 0 ;

    int numbers[N] ;

    for (int i = 0 ; i < N ; i++) {
        scanf("%d", &numbers[i]) ;
    }

    rev(numbers, N) ;

    return 0 ;
}