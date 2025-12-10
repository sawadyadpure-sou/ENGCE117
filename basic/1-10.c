#include <stdio.h>

int checkAccess(int level, int age, int active) {
    if ((level == 3 && active == 1) || 
        (level == 2 && age >= 25 && active == 1)) {
        return 1 ;
    } 
    else {
        return 0 ;
    }
}

int main() {
    int level, age, active ;
    if (scanf("%d %d %d", &level, &age, &active) != 3) {
        printf("Error reading input.\n") ;
        return 1 ;
    }
    if (checkAccess(level, age, active) == 1) {
        printf("Access Granted\n") ;
    } else {
        printf("Access Denied\n") ;
    }
    return 0 ;
}