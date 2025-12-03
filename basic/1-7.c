#include <stdio.h>

float calculate_bill(int type, float consumption);

int main() {
    int customer_type;
    float kwh_consumed;
    float total_bill = 0.0;

    if (scanf("%d %f", &customer_type, &kwh_consumed) != 2) {
        return 1;
    }

    if (customer_type == 1 || customer_type == 2) {
        total_bill = calculate_bill(customer_type, kwh_consumed);
        printf("%.2f\n", total_bill);
    } else {
        printf("Invalid Customer Type\n");
    }

    return 0;
}

float calculate_bill(int type, float consumption) {
    float bill = 0.0;

    if (type == 1) {
        if (consumption >= 0 && consumption <= 100) {
            bill = consumption * 3.0;
        } else if (consumption > 100) {
            bill = consumption * 4.0;
        }
    } else if (type == 2) {
        if (consumption >= 0 && consumption <= 500) {
            bill = consumption * 5.0;
        } else if (consumption > 500) {
            bill = consumption * 6.5;
        }
    }
    
    return bill;
}