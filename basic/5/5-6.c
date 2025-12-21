#include <stdio.h>

struct Employee {
    int id ;      
    int salary ;  
} ;

void find_min_max_salary(struct Employee emps[], int size, int *max, int *min) {
    *max = emps[0].salary ;
    *min = emps[0].salary ;

    for (int i = 1 ; i < size ; i++) {
        if (emps[i].salary > *max) {
            *max = emps[i].salary ;
        }
        if (emps[i].salary < *min) {
            *min = emps[i].salary ;
        }
    }
}

int main() {

    struct Employee employee_list[4] ;
    int max_salary ; 
    int min_salary ;

    for (int i = 0 ; i < 4 ; i++) {
        scanf("%d", &employee_list[i].id) ;
        scanf("%d", &employee_list[i].salary) ;
        printf("--------------------\n") ;
    }

    find_min_max_salary(employee_list, 4, &max_salary, &min_salary) ;

    printf("--------------------------------------\n") ;
    printf("ID\tSalary\n") ;
    for (int i = 0 ; i < 4 ; i++) {
        printf("%d\t%d\n", employee_list[i].id, employee_list[i].salary) ;
    }

    printf("Maximum Salary: %d\n", max_salary) ;
    printf("Minimum Salary: %d\n", min_salary) ;
    printf("--------------------------------------\n") ;

    return 0 ;
}