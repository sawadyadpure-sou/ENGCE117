#include <stdio.h>

int loop(int x)
{
    int i ;
    if (scanf("%d", &x) != 1) {
        return 1 ;
    }
    for (i = 0; i < x; i++) {
        printf("Hello Loop!\n") ;
    }

    return 0 ;
}

int main() {
    int x ;
    loop(x) ;
    return 0 ;
}