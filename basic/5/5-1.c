#include <stdio.h>

int calculate_area(int length, int width) {
    int area = length * width ;
    return area ;
}

int main() {
    int length, width, result ;

    scanf("%d", &length) ;
    scanf("%d", &width) ;

    result = calculate_area(length, width) ;

    printf("length: %d\n", length) ;
    printf("width: %d\n", width) ;
    printf("area: %d\n", result) ;

    return 0 ;
}