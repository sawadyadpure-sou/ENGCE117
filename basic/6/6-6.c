#include <stdio.h>

int calculate_net_balance(int *trans_array, int size, int *status_ptr) {
    int net_balance = 0 ;

    for (int i = 0 ; i < size ; i++) {
        net_balance += *(trans_array + i) ;
    }

    if (net_balance >= 0) {
        *status_ptr = 1 ; 
    } else {
        *status_ptr = 0 ; 
    }

    return net_balance ; 
}

int main() {
    int transactions[5] ; 
    int finance_status ;   
    int total_balance ;

    for (int i = 0 ; i < 5 ; i++) {
        printf("Transaction %d: ", i + 1) ;
        scanf("%d", &transactions[i]) ;
    }

    total_balance = calculate_net_balance(transactions, 5, &finance_status) ;

    printf("\n--- Financial Report ---\n") ;
    printf("All Transactions: ") ;
    for (int i = 0 ; i < 5 ; i++) {
        printf("%d ", transactions[i]) ;
    }
    
    printf("\nNet Balance: %d\n", total_balance) ;

    if (finance_status == 1) {
        printf("Financial Status: PROFIT\n") ;
    } else {
        printf("Financial Status: LOSS\n") ;
    }
    printf("------------------------\n") ;

    return 0 ;
}