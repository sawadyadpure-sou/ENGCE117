#include <stdio.h>

void countCharacterTypes(char str[]) {
    int countUpper = 0 ;
    int countLower = 0 ;
    int countDigit = 0 ;
    int countOther = 0 ;

    for (int i = 0 ; str[i] != '\0' ; i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            countUpper++ ;
        } else if (str[i] >= 'a' && str[i] <= 'z') {
            countLower++ ;
        } else if (str[i] >= '0' && str[i] <= '9') {
            countDigit++ ;
        } else {
            countOther++ ;
        }
    }

    printf("Uppercase Letters: %d\n", countUpper) ;
    printf("Lowercase Letters: %d\n", countLower) ;
    printf("Digits: %d\n", countDigit) ;
    printf("Special Characters and Spaces: %d\n", countOther) ;
}

int main() {
    char text[101] ;

    if (scanf("%[^\n]", text) != 1) return 0 ;

    countCharacterTypes(text) ;

    return 0 ;
}