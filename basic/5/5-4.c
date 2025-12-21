#include <stdio.h>

struct Student {
    int id ;         
    int score ;      
} ;

int find_max_score_id(struct Student students[], int size) {
    int max_score = students[0].score ;
    int max_id = students[0].id ;

    for (int i = 1 ; i < size ; i++) {
        if (students[i].score > max_score) {
            max_score = students[i].score ;
            max_id = students[i].id ;
        }
    }
    return max_id ;
}

int main() {
    struct Student class_list[3] ;

    for (int i = 0 ; i < 3 ; i++) {
        scanf("%d", &class_list[i].id) ;
        scanf("%d", &class_list[i].score) ;
        printf("--------------------\n") ;
    }

    int top_student_id = find_max_score_id(class_list, 3) ;

    printf("----------------------------\n") ;
    printf("ID\tScore\n") ;
    for (int i = 0 ; i < 3 ; i++) {
        printf("%d\t%d\n", class_list[i].id, class_list[i].score) ;
    }

    printf("Top performer ID: %d\n", top_student_id) ;
    printf("----------------------------\n") ;

    return 0 ;
}