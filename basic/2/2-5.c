#include <stdio.h>

void update_counts(int score, int *a, int *b, int *c, int *d, int *f) {
    
    if (score >= 80) { 
        (*a)++ ;
    } else if (score >= 70) { 
        (*b)++ ;
    } else if (score >= 60) { 
        (*c)++ ;
    } else if (score >= 50) { 
        (*d)++ ;
    } else if (score >= 0) {
        (*f)++ ;
    }
}

void display_summary(int a, int b, int c, int d, int f) {
    
    printf("Grade A Count: %d\n", a) ;
    printf("Grade B Count: %d\n", b) ;
    printf("Grade C Count: %d\n", c) ;
    printf("Grade D Count: %d\n", d) ;
    printf("Grade F Count: %d\n", f) ;
}

int main() {
    int score ;
    int countA = 0, countB = 0, countC = 0, countD = 0, countF = 0 ;
    if (scanf("%d", &score) != 1) {
        return 1 ;
    }
    while (score != -1) {
        update_counts(score, &countA, &countB, &countC, &countD, &countF) ;
        if (scanf("%d", &score) != 1) {
            break ; 
        }
    }
    display_summary(countA, countB, countC, countD, countF) ;

    return 0 ;
}