#include <stdio.h>

float cal(int code, int kg) {
    float cost = 0.0 ;
    switch (code) {
        case 1: 
            if (kg <= 5) {
                cost = 50.0 ; 
            } else { 
                cost = 80.0 ;
            }
            break ;
        case 2: 
            if (kg < 10) {
                cost = 150.0 ; 
            } else { 
                cost = 250.0 ; 
            }
            break ;
        case 3: 
            cost = 500.0 ; 
            break ;
        default: 
            cost = -1.0 ; 
            break ;
    }
    return cost ;
}
int main() {
    int code ;
    int kg ;
    float cost = 0.0;
    if (scanf("%d %d", &code, &kg) != 2) {
        return 1 ;
    }
    cost = cal(code, kg) ;
    if (cost >= 0.0) {
        printf("%.2f\n", cost);
    } else {
        printf("Invalid Zone Code\n") ;
    }
    return 0 ;
}