#include <stdio.h>

#define SIZE 3

int main() {

    int data[SIZE] ; 
    int *ptr ;      

    for (int i = 0 ; i < SIZE ; i++) {
        scanf("%d", &data[i]) ;
    }

    ptr = data ; 

    printf("\n--- Array & Pointer Report ---\n") ;
    printf("%-7s %-12s %-15s %-15s\n", "Index", "Direct(data[i])", "Pointer(*(ptr+i))", "Address(ptr+i)") ;
    
    for (int i = 0 ; i < SIZE ; i++) {
        printf("[%d] %-15d %-18d %-15p\n", 
               i, 
               data[i],        
               *(ptr + i),     
               (ptr + i)) ;    
    }
    printf("------------------------------\n") ;

    return 0 ;
}