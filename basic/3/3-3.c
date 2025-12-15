#include <stdio.h>
#include <string.h> 

typedef struct {
    char name[50] ;     
    int studentId ;     
    float score ;      
} Student ;

void calculateAverageScore() {
    int n_students ; 
    float total_score = 0.0 ;

    if (scanf("%d", &n_students) != 1 || n_students <= 0) {
        printf("Error: Invalid number of students.\n") ;
        return ; 
    }

    Student students[n_students] ; 

    for (int i = 0 ; i < n_students ; i++) {
        if (scanf("%d %f", &students[i].studentId, &students[i].score) != 2) {
            printf("Error reading ID and Score for student %d\n", i + 1) ;
            while (getchar() != '\n') ;
            continue ;
        }

        total_score += students[i].score ; 
        
        while (getchar() != '\n') ; 

        if (fgets(students[i].name, sizeof(students[i].name), stdin) == NULL) {
            printf("Error reading Name for student %d\n", i + 1) ;
            continue ;
        }

        size_t len = strlen(students[i].name) ;
        if (len > 0 && students[i].name[len - 1] == '\n') {
            students[i].name[len - 1] = '\0' ;
        }
    }
    float average_score = 0.0 ;
    if (n_students > 0) {
        average_score = total_score / n_students ;
    }
    printf("Average Score: %.2f\n", average_score) ;
}

int main() {

    calculateAverageScore() ;
    
    return 0 ;
}