#include <stdio.h>

void save(int n_months, double *total_deposit, int *success_count) {
    *total_deposit = 0.0 ;
    *success_count = 0 ;

    for (int month = 1 ; month <= n_months ; month++) {
        double monthly_total = 0.0 ; 

        while (1) {
            double daily_deposit ;
            
            if (scanf("%lf", &daily_deposit) != 1) {
                while (getchar() != '\n') ;
                continue ;
            }

            if (daily_deposit <= 0.0) {
                break ; 
            }

            monthly_total += daily_deposit ;
        }

        printf("Month %d Total: %.2f\n", month, monthly_total) ;

        if (monthly_total >= 500.00) {
            (*success_count)++ ;
        }

        *total_deposit += monthly_total ;
    }
}

int main() {
    int n_months ; 

    if (scanf("%d", &n_months) != 1 || n_months <= 0) {
        return 1 ; 
    }

    double total_deposit ;
    int success_count ;

    save(n_months, &total_deposit, &success_count) ;

    printf("Success Count: %d\n", success_count) ;

    return 0 ;
}