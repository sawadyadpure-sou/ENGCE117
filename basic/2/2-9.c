#include <stdio.h>

void processInventory(int n_transactions, double penalty_fee, int *current_stock, double *total_penalties) {

    for (int i = 0 ; i < n_transactions ; i++) {
        int cmdCode ;
        int quantity ;
        
        if (scanf("%d %d", &cmdCode, &quantity) != 2) {
            while (getchar() != '\n') ;
            continue ; 
        }

        switch (cmdCode) {
            case 1: 
                *current_stock += quantity ;
                printf("Received %d units.\n", quantity) ;
                break ;

            case 2: 
                if (quantity <= 0) {
                    printf("Error: Quantity must be positive.\n") ;
                } 
                else if (quantity <= *current_stock) {
                    *current_stock -= quantity ;
                    printf("Shipped %d units.\n", quantity) ;
                } 
                else {
                    *total_penalties += penalty_fee ;
                    printf("FAILURE: Insufficient stock. PENALTY %.2f added.\n", penalty_fee) ;
                }
                break ;

            case 3: 
                printf("STATUS: Stock = %d, Total Penalties = %.2f\n", *current_stock, *total_penalties) ;
                break ;

            default: 
                printf("Error: Invalid Command.\n") ;
                break ;
        }
    }
}

int main() {
    int initial_stock ; 
    double penalty_fee ; 
    int n_transactions ; 
    
    if (scanf("%d %lf %d", &initial_stock, &penalty_fee, &n_transactions) != 3) {
        return 1 ; 
    }

    int current_stock = initial_stock ;
    double total_penalties = 0.0 ;

    processInventory(n_transactions, penalty_fee, &current_stock, &total_penalties) ;

    return 0 ;
}