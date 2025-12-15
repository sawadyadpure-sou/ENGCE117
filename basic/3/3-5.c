#include <stdio.h>

#define SHIPPING_FEE 50.0

typedef struct {
    int itemId ;       
    float unitPrice ;    
    int quantity ;       
} Order ;

void order() {
    int n_orders ; 
    double grand_total = 0.0 ; 

    if (scanf("%d", &n_orders) != 1 || n_orders <= 0) {
        return ; 
    }

    for (int i = 0 ; i < n_orders ; i++) {
        Order current_order ;

        if (scanf("%d %f %d", 
                  &current_order.itemId, 
                  &current_order.unitPrice, 
                  &current_order.quantity) != 3) 
        {
            while (getchar() != '\n') ;
            continue ;
        }
        
        double item_total = (current_order.unitPrice * current_order.quantity) + SHIPPING_FEE ;
        
        double discount = 0.0 ;

        if (item_total >= 300.00) {
            discount = item_total * 0.10 ; 
        } 
        
        double net_price = item_total - discount ;

        grand_total += net_price ;
    }

    printf("Grand Total: %.2f\n", grand_total) ;
}

int main() {

    order() ;
    
    return 0 ;
}