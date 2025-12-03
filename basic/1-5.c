#include <stdio.h>

void update_sums(int current_number, int *even_total, int *odd_total); 

int main() 
{
    int number;
    int even_sum = 0;
    int odd_sum = 0;

    printf("Enter integers (0 to stop):\n");

    while (scanf("%d", &number) == 1 && number != 0) 
    {
        update_sums(number, &even_sum, &odd_sum);
    }
    
    printf("\nEven Sum: %d\n", even_sum);
    printf("Odd Sum: %d\n", odd_sum);
    
    return 0;
}

void update_sums(int current_number, int *even_total, int *odd_total) 
{
    if (current_number % 2 == 0) 
    {
        *even_total += current_number;
    } 
    else 
    {
        *odd_total += current_number;
    }
}