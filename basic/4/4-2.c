#include <stdio.h>

void point(int n, int scores[], int *passSum, int *failCount) {
    *passSum = 0 ;
    *failCount = 0 ;
    
    for (int i = 0; i < n; i++) {
        if (scores[i] >= 50) {
            *passSum += scores[i] ; 
        } else {
            (*failCount)++ ; 
        }
    }
}

int main() {
    int N ;

    scanf("%d", &N) ;

    int scores[N] ;
    int passSum = 0 ;
    int failCount = 0 ;

    for (int i = 0; i < N; i++) {
        scanf("%d", &scores[i]) ;
    }

    point(N, scores, &passSum, &failCount) ;

    printf("passSum : %d\n", passSum) ;
    printf("failCount : %d\n", failCount) ;

    return 0 ;
}