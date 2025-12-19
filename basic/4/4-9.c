#include <stdio.h>

void calculateNetSalary(int grossSalary, float *taxRate, float *taxAmount, float *netSalary) {
    if (grossSalary < 20000) {
        *taxRate = 0.0 ; 
    } else if (grossSalary >= 20000 && grossSalary < 50000) {
        *taxRate = 0.05 ; 
    } else {
        *taxRate = 0.10 ; 
    }

    *taxAmount = grossSalary * (*taxRate) ;
    *netSalary = grossSalary - (*taxAmount) ;
}

int main() {
    int grossSalary ;
    float taxRate, taxAmount, netSalary ;

    printf("Enter Gross Salary (Baht/Month): ") ;
    scanf("%d", &grossSalary) ;

    calculateNetSalary(grossSalary, &taxRate, &taxAmount, &netSalary) ;

    printf("\n--- Salary Report ---\n") ;
    printf("Gross Salary: %d Baht\n", grossSalary) ;
    printf("Tax Rate: %.0f%%\n", taxRate * 100) ; 
    printf("Tax Amount: %.2f Baht\n", taxAmount) ; 
    printf("Net Salary: %.2f Baht\n", netSalary) ; 

    return 0 ;
}