#include <stdio.h>
#include <stdlib.h>

void go(int ***p, int **z) {
    
    *p = z;
 }

void go(int ***p, int **z);
int main() {

    int *x = (int *)malloc(sizeof(int));
    int *y = (int *)malloc(sizeof(int));

    *x = 10;
    *y = 20;

    int **a;
    printf("\n");
    go(&a, &x);
    printf("%d %p %p \n", **a,*a,&a);
    go(&a, &y);
    printf("%d %p %p \n", **a,*a,&a);

    return 0;
}

