#include <stdio.h>
#include <stdlib.h>

int *GetMatrix(int *row, int *col);

int main() 
{
    int *data;
    int x, y; 

    data = GetMatrix(&x, &y);

    
    for (int i = 0; i < x; i++) 
    {
        for (int j = 0; j < y; j++) 
        {
            printf("%d ", data[i * y + j]);
        }
        printf("\n");
    }

    return 0;
}

 
int *GetMatrix(int *row, int *col) 
{
    int *value;

    printf("Enter rows: ");
    scanf("%d", row);
    printf("Enter cols: ");
    scanf("%d", col);

    value = (int *)malloc((*row) * (*col) * sizeof(int));

    printf("Enter %d elements:\n", (*row) * (*col));
    for (int i = 0; i < *row; i++) 
    {
        for (int j = 0; j < *col; j++) {
            scanf("%d", &value[i * (*col) + j]);
        }
    }

    return value;
}