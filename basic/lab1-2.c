#include <stdio.h>
#include <stdlib.h>

void GetSet(int **data, int *slot) 
{

    printf("slot: ");
    scanf("%d", slot);

    *data = (int *)malloc((*slot) * sizeof(int));

    for (int i = 0; i < *slot; i++) 
    {
        printf("position %d: ", i + 1);
        if (scanf("%d", &((*data)[i])) != 1) 
        {

            *slot = i; 
            return;

        }
    }
}

int main() 
{
    int *data = NULL; 
    int slot;          
    GetSet(&data, &slot);
}