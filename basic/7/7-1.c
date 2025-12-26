#include <stdio.h>

int main() {
    FILE *fptr ;
    char text[] = "Hello, C File Handling is easy." ;
    int year = 2025 ;

    fptr = fopen("output_data.txt", "w") ;

    if (fptr == NULL) {
        printf("[Error] Could not open or create the file!\n") ;
        return 1 ; 
    }

    fprintf(fptr, "%s\n", text) ;

    fprintf(fptr, "%d\n", year) ;


    fclose(fptr) ;

    printf("--- File Operations Report ---\n") ;
    printf("Writing the following data to 'output_data.txt':\n") ;
    printf("Line 1: %s\n", text) ; 
    printf("Line 2: %d\n", year) ;
    printf("------------------------------\n") ;
    printf("Status: Process completed successfully.\n") ;

    return 0 ;
}