#include <stdio.h>

void vending(float totalCost) {
    float paidAmount ;
    printf("Total Cost: %.2f\n", totalCost) ;
    printf("Enter paid amount: ") ;
    scanf("%f", &paidAmount) ;

    if (paidAmount >= totalCost) {
        float change = paidAmount - totalCost ;
        printf("Change: %.2f\n", change) ;
    } else {
        printf("Insufficient payment. Purchase cancelled.\n") ;
    }
}

int main() {
    int choice ;
    float totalCost = 0 ;

    do {
        printf("--- Vending Machine ---\n") ;
        printf("1. Coke (15.00)\n") ;
        printf("2. Water (10.00)\n") ;
        printf("3. Snack (25.00)\n") ;
        printf("4. Exit/Pay\n") ;
        printf("Select choice: ") ;

        scanf("%d", &choice) ;

        switch (choice) {
            case 1:
                totalCost = totalCost + 15.00 ;
                break ;
            case 2:
                totalCost = totalCost + 10.00 ;
                break ;
            case 3:
                totalCost = totalCost + 25.00 ;
                break ;
            case 4:
                break ;
            default:
                printf("Invalid choice!\n") ;
        }
    } while (choice != 4) ;

    vending(totalCost) ;

    return 0 ;
}