#include <stdio.h>

#define MONTHLY_RATE 0.01
#define FINE_AMOUNT 10.00

int input(double *debt_ptr, double *payment_ptr) {
    
    if (scanf("%lf", debt_ptr) != 1 || *debt_ptr <= 0) {
        printf("Invalid Debt amount.\n") ;
        return 1 ;
    }

    if (scanf("%lf", payment_ptr) != 1 || *payment_ptr <= 0) {
        printf("Invalid Monthly Payment.\n") ;
        return 1 ;
    }
    
    return 0 ;
}

int repay(double debt, double payment) {
    
    double interest ;
    int month = 0 ;
    int max_months = 1000 ;

    while (debt > 0) {
        month++ ;
        
        if (month > max_months) { 
             printf("ERROR\n") ;
             return 1 ;
        }
        
        interest = debt * MONTHLY_RATE ;

        debt = debt + interest ;
        
        if (payment < interest) {
            debt = debt + FINE_AMOUNT ;
        }
        
        debt = debt - payment ;
        
        if (debt > 0) {
            printf("Month %d: Remaining: %.2f\n", month, debt) ;
        } else {
            double overpayment = debt * (-1.0) ;
            printf("Month %d: Remaining: 0.00\n", month) ; 
            debt = 0.0 ; 
        }
    }

    printf("Complete in %d months\n", month) ;

    return 0 ;
}


int main() {
    double debt = 0.0 ; 
    double payment = 0.0 ;

    if (input(&debt, &payment) != 0) {
        return 1 ; 
    }

    return repay(debt, payment) ;
}