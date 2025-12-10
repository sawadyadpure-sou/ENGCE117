#include <stdio.h>

int main() {
    int code;
    float b_vat;
    float bill = 0.0;
    float vat = 0.0;
    if (scanf("%f %d", &b_vat, &code) != 2) {
        return 1 ;
    }
    if (code == 1) { //(7%)
        bill = b_vat * 1.07;
    } else if (code == 2) { //(0%)
        bill = b_vat;
    } else if (code == 3) { //(15%)
        bill = b_vat * 1.15;
    } else { // invalid
        printf("invalid Category\n") ;
        printf("VAT Amount: %.2f\n", 0.00) ;
        printf("Total Price: %.2f\n", 0.00) ;
        return 0 ;
    }

    vat = bill - b_vat ;

    printf("VAT Amount: %.2f\n", vat) ;
    printf("Total Price: %.2f\n", bill) ;
    return 0 ;

}