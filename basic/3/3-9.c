#include <stdio.h>

float simulateBudget(float initialBudget, int nDays) {
    float currentBudget = initialBudget ;
    float spent ;

    for (int day = 1 ; day <= nDays ; day++) {
        if (currentBudget >= 500.00) {
            spent = 100.00 ;
        } else if (currentBudget >= 100.00) {
            spent = 50.00 ;
        } else {
            spent = 20.00 ;
        }

        if (spent > currentBudget) {
            spent = currentBudget ;
        }

        currentBudget = currentBudget - spent ;

        printf("Day %d: Spent %.2f, Remaining %.2f\n", day, spent, currentBudget) ;

        if (currentBudget <= 0) {
            break ;
        }
    }
    return currentBudget ;
}

int main() {
    float initialBudget ;
    int nDays ;

    if (scanf("%f %d", &initialBudget, &nDays) != 2) return 0 ;

    printf("------------\n") ;
    float finalBudget = simulateBudget(initialBudget, nDays) ;

    printf("------------\n") ;
    printf("Final Budget: %.2f\n", finalBudget) ;

    return 0 ;
}