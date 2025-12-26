#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fptr;
    int num1, num2, num3, num4, num5;
    int total_sum;

    fptr = fopen("input_data.csv", "r");

    if (fptr == NULL) {
        printf("[Error] no file name 'input_data.csv' or can't open!\n");
        return 1; 
    }

    if (fscanf(fptr, "%d,%d,%d,%d,%d", &num1, &num2, &num3, &num4, &num5) == 5) {

        total_sum = num1 + num2 + num3 + num4 + num5;

        printf("--- CSV File Reading Report ---\n");
        printf("Data read from file: %d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);
        printf("Calculated Total Sum: %d\n", total_sum);
        printf("-------------------------------\n");
    } else {
        printf("[Error] wrong format!\n");
    }

    fclose(fptr);

    return 0;
}