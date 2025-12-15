#include <stdio.h>

double calculateAPR(double balance) {
    if (balance < 1000.00) {
        return 0.01 ; 
    } else { 
        return 0.025 ; 
    }
}

void processSavingsAccount(int n_periods, double penalty_fee, double *current_balance, double *total_penalties) {

    for (int month = 1 ; month <= n_periods ; month++) {
        int cmdCode ;
        double amount ;
        
        printf("--- Month %d ---\n", month) ;
        if (scanf("%d %lf", &cmdCode, &amount) != 2) {
            while (getchar() != '\n') ;
            continue ; 
        }

        switch (cmdCode) {
            case 1: 
                *current_balance += amount ;
                printf("Deposit: %.2f\n", amount) ;
                break ;

            case 2: 
                if (amount <= *current_balance) {

                    *current_balance -= amount ;
                    printf("Withdrawal: %.2f\n", amount) ;
                } 
                else {
                    *total_penalties += penalty_fee ;
                    printf("WITHDRAWAL FAILED. Penalty %.2f applied.\n", penalty_fee) ;
                }
                break ;

            case 3: { 
                double apr = calculateAPR(*current_balance) ;
                double rate_percent = apr * 100.0 ; 
                double interest = (*current_balance) * (apr / 12.0) ;
                *current_balance += interest ;
                printf("Interest: %.2f (Rate: %.2f%%)\n", interest, rate_percent) ;
                break ;
            }
            default: 
                printf("Error: Invalid Command.\n") ;
                break ;
        }
    }
}

int main() {
    double initial_balance ; 
    double penalty_fee ; 
    int n_periods ; 
    
    if (scanf("%lf %lf %d", &initial_balance, &penalty_fee, &n_periods) != 3) {
        return 1 ; 
    }

    double current_balance = initial_balance ;
    double total_penalties = 0.0 ;

    printf("Starting Balance: %.2f\n", initial_balance) ;

    processSavingsAccount(n_periods, penalty_fee, &current_balance, &total_penalties) ;

    printf("Final Balance: %.2f\n", current_balance) ;
    printf("Total Penalties: %.2f\n", total_penalties) ;

    return 0 ;
}