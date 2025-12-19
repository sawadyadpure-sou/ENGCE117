#include <stdio.h>

int findMax(int temps[], int size) {
    int max = temps[0] ;
    for (int i = 1; i < size; i++) {
        if (temps[i] > max) {
            max = temps[i] ;
        }
    }
    return max ;
}

int main() {
    int temperatures[7] ;
    int maxTemp ;

    printf("Enter average temperature for 7 days (Celsius):\n") ;
    for (int i = 0; i < 7; i++) {
        printf("Day %d: ", i + 1) ;
        scanf("%d", &temperatures[i]) ;
    }

    maxTemp = findMax(temperatures, 7) ;

    printf("\n--- Weather Report ---\n") ;

    printf("Recorded temperatures: ") ;
    for (int i = 0; i < 7; i++) {
        printf("%d ", temperatures[i]) ;
    }

    printf("\nMaximum Temperature: %d Celsius\n", maxTemp) ;

    if (maxTemp >= 35) {
        printf("Conclusion: Weather is HOT!\n") ;
    } else {
        printf("Conclusion: Weather is MODERATE.\n") ;
    }

    return 0 ;
}