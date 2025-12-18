#include <stdio.h>

struct Item {
    char name[50] ;
    float unitPrice ;
    int quantity ;
} ;

void receipt(struct Item items[], int n) {
    float subTotal = 0 ;
    float vatRate = 0.07 ;

    printf("--- RECEIPT ---\n") ;

    for (int i = 0 ; i < n ; i++) {
        float itemCost = items[i].unitPrice * items[i].quantity ;
        printf("%s x %d = %.2f\n", items[i].name, items[i].quantity, itemCost) ;
        subTotal = subTotal + itemCost ;
    }

    float totalVAT = subTotal * vatRate ;
    float grandTotal = subTotal + totalVAT ;

    printf("------------\n") ;
    printf("Subtotal: %.2f\n", subTotal) ;
    printf("VAT (7%%): %.2f\n", totalVAT) ;
    printf("Grand Total: %.2f\n", grandTotal) ;
}

int main() {
    int N ;

    if (scanf("%d", &N) != 1) return 0 ;

    struct Item items[N] ;

    for (int i = 0 ; i < N ; i++) {
        scanf("%s %f %d", items[i].name, &items[i].unitPrice, &items[i].quantity) ;
    }

    receipt(items, N) ;

    return 0 ;
}