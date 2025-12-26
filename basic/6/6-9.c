#include <stdio.h>

#define MONTHS 3

int analyze_profitability(int *rev_ptr, int *exp_ptr, int size, int *status_ptr, int *total_rev, int *total_exp) {
    *total_rev = 0 ;
    *total_exp = 0 ;
    int net_profit ;

    for (int i = 0 ; i < size ; i++) {
        *total_rev += *(rev_ptr + i) ; 
        *total_exp += *(exp_ptr + i) ; 
    }

    net_profit = *total_rev - *total_exp ;

    if (net_profit >= 0) {
        *status_ptr = 1 ;
    } else {
        *status_ptr = 0 ; 
    }

    return net_profit ; 
}

int main() {
    int monthly_revenue[MONTHS] ;
    int monthly_expense[MONTHS] ;
    int business_status ; 
    int total_rev_sum, total_exp_sum, net_profit_sum ;

    printf("--- Business Data Entry ---\n") ;
    printf("Step 1: Enter Revenue for %d months\n", MONTHS) ;
    for (int i = 0 ; i < MONTHS ; i++) {
        printf("  Month %d Revenue: ", i + 1) ;
        scanf("%d", &monthly_revenue[i]) ;
    }
    printf("\nStep 2: Enter Expense for %d months\n", MONTHS) ;
    for (int i = 0 ; i < MONTHS ; i++) {
        printf("  Month %d Expense: ", i + 1) ;
        scanf("%d", &monthly_expense[i]) ;
    }

    net_profit_sum = analyze_profitability(monthly_revenue, monthly_expense, MONTHS, &business_status, &total_rev_sum, &total_exp_sum) ;

    printf("\n--- 3 Month Financial Report ---\n") ;
    printf("Total Revenue:     %d\n", total_rev_sum) ; 
    printf("Total Expense:     %d\n", total_exp_sum) ;
    printf("---------------------------\n") ;
    printf("Net Profit:        %d\n", net_profit_sum) ;

    if (business_status == 1) {
        printf("Analysis: PROJECT IS PROFITABLE\n") ;
    } else {
        printf("Analysis: PROJECT IS UNPROFITABLE\n") ;
    }
    printf("-------------------------------------\n") ;

    return 0 ;
}