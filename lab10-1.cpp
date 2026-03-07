#include <stdio.h>

long SumLoop(int x) ;
long SumRecur(int x) ;

int main() {
    int n = 0 ;
    printf("Enter N number for function: ") ;
    scanf("%d", &n) ;

    printf("Do function 1 to %d\n", n) ;
    printf("SumLoop(n) = %d\n", SumLoop(n)) ;
    printf("SumRecur(n) = %d", SumRecur(n)) ;

    return 0 ;
}

long SumLoop(int x) {
    long sum = 0 ;
    for (int i = 1 ; i <= x ; i++) {
        sum = sum + i ;
    }
    return sum ;
}

long SumRecur(int x) {
    if (x == 1) {
        return 1 ;
    } else {
        return x + SumRecur(x - 1) ;
    }
}