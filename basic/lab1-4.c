#include <stdio.h>
#include <stdlib.h>

void GetMatrix(int **value, int *row, int *col);

int main() 
{
    int *data;
    int m, n;

    GetMatrix(&data, &m, &n);

    for (int i = 0; i < m; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            printf("%d ", data[i * n + j]);
        }
        printf("\n");
    }

    return 0;
}

void GetMatrix(int **value, int *row, int *col) 
{
    printf("Enter rows: ");
    scanf("%d", row);
    printf("Enter cols: ");
    scanf("%d", col);

    *value = (int *)malloc((*row) * (*col) * sizeof(int));

    printf("Enter %d elements:\n", (*row) * (*col));
    for (int i = 0; i < *row; i++) {
        for (int j = 0; j < *col; j++) 
        {
            scanf("%d", &(*value)[i * (*col) + j]);
        }
    }
}