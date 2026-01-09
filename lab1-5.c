#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col);

int main() {
    int *data;
    int x, y;
    GetMatrix(&data, &x, &y);
}

void GetMatrix(int **value, int *row, int *col) {

    *value = (int *)malloc((*row) * (*col) * sizeof(int));


}