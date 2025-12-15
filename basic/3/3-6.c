#include <stdio.h>
#include <string.h> 
#include <math.h>  

typedef struct {
    char description[50] ; 
    float amount ;      
} Transaction ;

void transaction() {
    int n_transactions ; 
    double total_income = 0.0 ;  
    double total_expense = 0.0 ;

    if (scanf("%d", &n_transactions) != 1 || n_transactions <= 0) {
        printf("Error: Invalid number of transactions.\n") ;
        return ; 
    }

    Transaction transactions[n_transactions] ; 


    for (int i = 0 ; i < n_transactions ; i++) {

        if (scanf("%f", &transactions[i].amount) != 1) {
            printf("Error reading amount for transaction %d\n", i + 1) ;
            while (getchar() != '\n') ;
            continue ;
        }

        while (getchar() != '\n') ; 

        if (fgets(transactions[i].description, sizeof(transactions[i].description), stdin) == NULL) {
            printf("Error reading description for transaction %d\n", i + 1) ;
            continue ;
        }

        size_t len = strlen(transactions[i].description) ;
        if (len > 0 && transactions[i].description[len - 1] == '\n') {
            transactions[i].description[len - 1] = '\0' ;
        }
        
        if (transactions[i].amount >= 0.0) {
            total_income += transactions[i].amount ;
        } else {
            total_expense += fabs(transactions[i].amount) ;
        }
    }
    
    double net_balance = total_income - total_expense ;

    printf("Total Income: %.2f\n", total_income) ;
    printf("Total Expense: %.2f\n", total_expense) ;
    printf("Net Balance: %.2f\n", net_balance) ;
}

int main() {

    transaction() ;
    
    return 0 ;
}