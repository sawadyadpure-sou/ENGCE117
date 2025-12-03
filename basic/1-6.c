#include <stdio.h>

int main() {
    int number;

    do {
        printf("Enter a number (1-10): ");

        if (scanf("%d", &number) == 1) 
        {
            
            if (number >= 1 && number <= 10) 
            {
                break; 
            } 
        } 

    } while (1); 

    printf("Input accepted: %d\n", number);
    
    return 0;
}