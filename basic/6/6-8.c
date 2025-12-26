#include <stdio.h>

int find_and_update(int *arr_ptr, int size, int search_value, int new_value) {
    for (int i = 0 ; i < size ; i++) {
        if (*(arr_ptr + i) == search_value) {
            *(arr_ptr + i) = new_value ;
            return 1 ; 
        }
    }
    return 0 ;
}

int main() {
    int data[5] ;
    int search_val, new_val, status ;

    for (int i = 0 ; i < 5 ; i++) {
        scanf("%d", &data[i]) ;
    }

    scanf("%d", &search_val) ;
    scanf("%d", &new_val) ;

    printf("\nArray before update: ") ;
    for (int i = 0 ; i < 5 ; i++) printf("%d ", data[i]) ;

    status = find_and_update(data, 5, search_val, new_val) ;

    printf("\nArray after update:  ") ;
    for (int i = 0 ; i < 5 ; i++) printf("%d ", data[i]) ;

    if (status == 1) {
        printf("\nStatus: Update Successful (Success)\n") ;
    } else {
        printf("\nStatus: Value not found (Failed)\n") ;
    }
    printf("----------------------------------\n") ;

    return 0 ;
}