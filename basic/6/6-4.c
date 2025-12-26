#include <stdio.h>

void calculate_sum_product(int num1, int num2, int *sum_ptr, int *prod_ptr) {
    *sum_ptr = num1 + num2;    
    *prod_ptr = num1 * num2;   
}

int main() {

    int val_A, val_B;
    int result_sum, result_product;

    scanf("%d", &val_A);
    scanf("%d", &val_B);

    calculate_sum_product(val_A, val_B, &result_sum, &result_product);

    printf("Input numbers: %d, %d\n", val_A, val_B);
    printf("Calculated Sum: %d\n", result_sum);
    printf("Calculated Product: %d\n", result_product);

    return 0;
}