#include <stdio.h>
#include <string.h>

void explode(char chr1[], char splitter, char chr2[][10], int *count) {
    char delim[2] = {splitter, '\0'} ; 
    char *token ;
    int i = 0 ;

    token = strtok(chr1, delim) ; 
    while (token != NULL) {
        if (i < 20) { 
            strcpy(chr2[i], token) ; 
        }
        i++ ;
        token = strtok(NULL, delim) ; 
    }
    *count = i ; 
}

int main() {
    char text[] = "I/Love/you" ;
    char out[20][10] ;
    int num ;
    char splitter_char = '/' ;
    explode(text, splitter_char, out, &num) ;
    for (int i = 0; i < num; i++) {
        printf("[%d] = %s\n", i, out[i]) ;
    }
    printf("count = %d\n", num) ;
    return 0 ;
}