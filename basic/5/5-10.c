#include <stdio.h>

int calculate_change_amount(int total_cost, int amount_paid) {
    if (amount_paid < total_cost) {
        return -1 ; 
    }
    return amount_paid - total_cost ;
}

int count_denomination(int *change_remaining, int denomination) {
    int count = *change_remaining / denomination ;    
    *change_remaining = *change_remaining % denomination ; 
    return count ;
}

int main() {
    int total_cost, amount_paid, change ;

    printf("---------------------\n") ;
    printf("Enter Total Cost: ") ;
    scanf("%d", &total_cost) ;
    printf("Enter Amount Paid: ") ;
    scanf("%d", &amount_paid) ;

    change = calculate_change_amount(total_cost, amount_paid) ;

    if (change == -1) {
        printf("\nError: Insufficient funds provided!\n") ;
    } else if (change == 0) {
        printf("\nNo change required.\n") ;
    } else {
        int remaining = change ;
        printf("---------------------\n") ;
        printf("Total Change: %d Baht\n", change) ;
        printf("---------------------\n") ;

        int bills[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1} ;
        int num_denominations = 9 ;

        for (int i = 0 ; i < num_denominations ; i++) {
            int count = count_denomination(&remaining, bills[i]) ;
            if (count > 0) {
                if (bills[i] >= 20) {
                    printf("%d Baht: %d\n", bills[i], count) ;
                } else {
                    printf("%d Baht: %d\n", bills[i], count) ;
                }
            }
        }
        printf("---------------------\n") ;
    }

    return 0 ;
}