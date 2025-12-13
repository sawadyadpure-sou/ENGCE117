#include <stdio.h>

int APR_calculation(int code, double amount) {
    
    double APR = 0.0 ; 
    double earn ;

    switch (code) {
        case 1: 
            if (amount < 5000.0) {
                APR = 0.030 ; 
            } else { 
                APR = 0.040 ; 
            }
            break ;

        case 2: 
            if (amount < 10000.0) {
                APR = 0.050 ; 
            } else { 
                APR = 0.065 ; 
            }
            break ;

        case 3: 
            APR = 0.080 ; 
            break ;

        default: 
            return 1 ;
    }

    if (APR > 0.0) {
        earn = amount * APR ;
        printf(" %.2f \n", earn) ;
    }

    return 0 ;
}

int main() {
    int code ;
    double amount ;
    if (scanf("%d", &code) != 1) {
        printf("Invalid input for Term Code.\n") ;
        return 1 ;
    }
    if (scanf("%lf", &amount) != 1 || amount < 0) {
        printf("Invalid input for Investment Amount.\n") ;
        return 1 ;
    }

    return APR_calculation(code, amount) ;
}