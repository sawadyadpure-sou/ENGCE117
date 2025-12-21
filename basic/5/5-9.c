#include <stdio.h>

struct Product {
    int item_id ;
    float cost_price ;
    float sell_price ;
    int stock_quantity ;
} ;

float calculate_total_profit(float cost, float sell, int qty) {
    float unit_profit = sell - cost ;
    return unit_profit * qty ;
}

float calculate_profit_percentage(float cost, float sell) {
    float unit_profit = sell - cost ;
    return (unit_profit / cost) * 100 ;
}

int main() {
    struct Product p ;
    float total_profit ;
    float profit_percent ;

    printf("Item ID: ") ;
    scanf("%d", &p.item_id) ;
    printf("Cost Price per unit: ") ;
    scanf("%f", &p.cost_price) ;
    printf("Selling Price per unit: ") ;
    scanf("%f", &p.sell_price) ;
    printf("Stock Quantity: ") ;
    scanf("%d", &p.stock_quantity) ;

    total_profit = calculate_total_profit(p.cost_price, p.sell_price, p.stock_quantity) ;
    profit_percent = calculate_profit_percentage(p.cost_price, p.sell_price) ;

    printf("------------------------------------\n") ;
    printf("Item ID: %d\n", p.item_id) ;
    printf("Cost: %.2f | Sell: %.2f | Stock: %d\n", p.cost_price, p.sell_price, p.stock_quantity) ;
    printf("Total Net Profit: %.2f\n", total_profit) ;
    printf("Profit Percentage: %.2f%%\n", profit_percent) ;

    printf("Status: ") ;
    if (total_profit > 0) {
        printf("PROFIT!\n") ;
    } else if (total_profit < 0) {
        printf("LOSS!\n") ;
    } else {
        printf("BREAK EVEN\n") ;
    }
    printf("------------------------------------\n") ;

    return 0 ;
}