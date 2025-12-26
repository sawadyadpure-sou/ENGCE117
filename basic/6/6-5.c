#include <stdio.h>

int main() {
    char sentence[100] ;      
    char *char_ptr ;          
    int vowel_count = 0 ;     

    fgets(sentence, sizeof(sentence), stdin) ; 

    char_ptr = sentence ; 

    while (*char_ptr != '\0') {
        if (*char_ptr == 'a' || *char_ptr == 'e' || *char_ptr == 'i' || *char_ptr == 'o' || *char_ptr == 'u' ||
            *char_ptr == 'A' || *char_ptr == 'E' || *char_ptr == 'I' || *char_ptr == 'O' || *char_ptr == 'U') {
            vowel_count++ ; 
        }
        
        char_ptr++ ; 
    }

    printf("\n--- Vowel Count Report ---\n") ;
    printf("Your input: %s", sentence) ;
    printf("Total number of vowels: %d\n", vowel_count) ;
    printf("--------------------------\n") ;

    return 0 ;
}