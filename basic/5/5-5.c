#include <stdio.h>

struct Student {
    int id ;        
} ;

int check_id_existence(struct Student students[], int size, int search_id) {
    for (int i = 0 ; i < size ; i++) {
        if (students[i].id == search_id) {
            return 1 ; 
        }
    }
    return 0 ; 
}

int main() {
    struct Student class_list[4] ; 
    int search_id ;
    int result ;

    for (int i = 0 ; i < 4 ; i++) {
        printf("Student %d ID: ", i + 1) ;
        scanf("%d", &class_list[i].id) ;
    }

    printf("\nsearch id: ") ;
    scanf("%d", &search_id) ;

    result = check_id_existence(class_list, 4, search_id) ;

    printf("------------------------------\n") ;
    printf("system IDs: ") ;
    for (int i = 0 ; i < 4 ; i++) {
        printf("%d ", class_list[i].id) ;
    }
    
    printf("\nSearch ID Target: %d\n", search_id) ;

    if (result == 1) {
        printf("Result: ID FOUND in the system.\n") ;
    } else {
        printf("Result: ID NOT FOUND in the system.\n") ;
    }
    printf("------------------------------\n") ;

    return 0 ;
}