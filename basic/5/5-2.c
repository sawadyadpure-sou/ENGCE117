#include <stdio.h>

struct Employee {
    int id ;               
    int gross_salary ;     
    int bonus ;            
    int total_income ;     
} ;

int calculate_net_salary(int total_income) {
    int tax_amount ;
    int net_salary ;

    if (total_income > 30000) {
        tax_amount = (int)(total_income * 0.10) ; 
    } else {
        tax_amount = (int)(total_income * 0.05) ; 
    }

    net_salary = total_income - tax_amount ; 
    return net_salary ; 
}

int main() {
    struct Employee emp ; 
    int net_salary_result ;

    scanf("%d", &emp.id) ;
    scanf("%d", &emp.gross_salary) ;
    scanf("%d", &emp.bonus) ;

    emp.total_income = emp.gross_salary + emp.bonus ;

    net_salary_result = calculate_net_salary(emp.total_income) ;

    printf("ID: %d\n", emp.id) ;
    printf("Gross Salary: %d baht\n", emp.gross_salary) ;
    printf("bonus: %d baht\n", emp.bonus) ;
    printf("total income: %d baht\n", emp.total_income) ;
    printf("net salary: %d baht\n", net_salary_result) ;
    printf("----------------------------------\n") ;

    return 0 ;
}