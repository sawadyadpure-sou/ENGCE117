#include <stdio.h>

int main() {
    int code;
    float data;
    float bill = 0.0;
    
    if (scanf("%d %f", &code, &data) != 2) {
        return 1 ;
    }
    if (code == 1) { 
        bill = 299.0 ;
        if (data > 10.0) {
            bill = 299.0 + 10.0 * (data - 10.0) ;
        }

        printf("%.2f\n", bill) ;
    } else if (code == 2) { 
        bill = 599.0 ;
        if (data > 20.0) {
            float extra_charge_base = 5.0 * (data - 20.0) ;
            bill = 599.0 + 50.0 + 5.0 * (data - 20.0) ;
        }
        
        printf("%.2f\n", bill) ;

    } else {
        printf("Invalid Plan Code\n");
    }
    return 0;
}