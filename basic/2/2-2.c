#include <stdio.h>

#define DISCOUNT_THRESHOLD 1000.00
#define DISCOUNT_RATE 0.10

double cal(double Price, int number) {
    
    double itemTotal ;
    double discount ;
    double netItemPrice ;

    itemTotal = Price * number ;
    discount = 0.0 ;

    if (Price >= DISCOUNT_THRESHOLD) {
        discount = itemTotal * DISCOUNT_RATE ;
    } 
    netItemPrice = itemTotal - discount ;
    return netItemPrice ;
}

int main() {
    int N ;            
    int i ;

    double Price ;      
    int number ; 
    double grandTotal = 0.0 ;

    if (scanf("%d", &N) != 1 || N <= 0) {
        printf("Invalid input for N.\n") ;
        return 1 ;
    }

    for (i = 1 ; i <= N ; i++) {
        if (scanf("%lf", &Price) != 1 || Price < 0) {
            printf("Invalid input for Unit Price. Skipping item.\n") ;
            continue ;
        }

        if (scanf("%d", &number) != 1 || number < 0) {
            printf("Invalid input for Quantity. Skipping item.\n") ;
            continue ;
        }
        grandTotal += cal(Price, number) ;
    }

    printf("Grand Total:%.2f \n", grandTotal) ;

    return 0 ;
}