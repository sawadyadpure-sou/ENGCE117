#include <stdio.h>

void countFizzBuzz(int n_limit) {
    int countFizzBuzz = 0 ; 
    int countFizz = 0 ;     
    int countBuzz = 0 ;     
    int countOther = 0 ;    

    for (int i = 1 ; i <= n_limit ; i++) {
        if ((i % 3 == 0) && (i % 5 == 0)) {
            countFizzBuzz++ ;
        } 
        else if (i % 3 == 0) {
            countFizz++ ;
        } 
        else if (i % 5 == 0) {
            countBuzz++ ;
        } 
        else {
            countOther++ ;
        }
    }
    printf("Count FizzBuzz: %d\n", countFizzBuzz) ;
    printf("Count Fizz: %d\n", countFizz) ;
    printf("Count Buzz: %d\n", countBuzz) ;
    printf("Count Other: %d\n", countOther) ;
}
int main() {
    int n_limit ;

    if (scanf("%d", &n_limit) != 1 || n_limit <= 0) {
        return 1 ; 
    }
    countFizzBuzz(n_limit) ;
    return 0 ;
}