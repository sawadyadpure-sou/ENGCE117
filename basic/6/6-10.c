#include <stdio.h>

struct Student {
    int student_id ;
    int score ;
    char grade ;
} ;

void calculate_grade(struct Student *s_ptr) {
    if (s_ptr->score >= 80) {
        s_ptr->grade = 'A' ;
    } else if (s_ptr->score >= 70) {
        s_ptr->grade = 'B' ;
    } else if (s_ptr->score >= 60) {
        s_ptr->grade = 'C' ;
    } else if (s_ptr->score >= 50) {
        s_ptr->grade = 'D' ;
    } else {
        s_ptr->grade = 'F' ;
    }
}

int main() {
    struct Student s ; 
    int choice ;
    int has_data = 0 ; 

    do {
        printf("\n--- Student Management System ---\n") ;
        printf("1. INPUT DATA\n") ;
        printf("2. VIEW REPORT\n") ;
        printf("3. EXIT\n") ;
        printf("Select choice: ") ;
        scanf("%d", &choice) ;

        switch (choice) {
            case 1:
                printf("Enter Student ID: ") ;
                scanf("%d", &s.student_id) ;
                printf("Enter Score (0-100): ") ;
                scanf("%d", &s.score) ;
                calculate_grade(&s) ;
                has_data = 1 ;
                printf("Data updated successfully!\n") ;
                break ;

            case 2:
                if (has_data) {
                    printf("\n--- Student Report ---\n") ;
                    printf("Student ID: %d\n", s.student_id) ;
                    printf("Score:      %d\n", s.score) ;
                    printf("Grade:      %c\n", s.grade) ;
                    printf("----------------------\n") ;
                } else {
                    printf("\n[Error] No data available. Please input data first.\n") ;
                }
                break ;

            case 3:
                printf("Exiting program. Goodbye!\n") ;
                break ;

            default:
                printf("Invalid choice! Please try again.\n") ;
        }
    } while (choice != 3) ;

    return 0 ;
}