#include <stdio.h>

struct Student {
    int id ;
    int math_score ;
    int science_score ;
    int english_score ;
    int total_score ;
} ;

char calculate_grade(int total_score) {
    if (total_score >= 250) {
        return 'A' ;
    } else if (total_score >= 200) {
        return 'B' ;
    } else {
        return 'C' ;
    }
}

void calculate_average(int total_score, float *avg) {
    *avg = (float)total_score / 3 ;
}

int main() {
    struct Student s ;
    char grade ;
    float average_result ;

    printf("Student ID: ") ;
    scanf("%d", &s.id) ;
    printf("Math Score: ") ;
    scanf("%d", &s.math_score) ;
    printf("Science Score: ") ;
    scanf("%d", &s.science_score) ;
    printf("English Score: ") ;
    scanf("%d", &s.english_score) ;

    s.total_score = s.math_score + s.science_score + s.english_score ;

    grade = calculate_grade(s.total_score) ;

    calculate_average(s.total_score, &average_result) ;

    printf("-------------------------------\n") ;
    printf("Student ID: %d\n", s.id) ;
    printf("Math: %d | Science: %d | English: %d\n", s.math_score, s.science_score, s.english_score) ;
    printf("Total Score: %d\n", s.total_score) ;
    printf("Grade: %c\n", grade) ;
    printf("Average Score: %.2f\n", average_result) ;
    printf("-------------------------------\n") ;

    return 0 ;
}