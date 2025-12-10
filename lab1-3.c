#include <stdio.h>
#include <stdlib.h> 

int *GetSet(int *size_ptr); 

int main() 
{
    int *data;
    int num;   
    int i;
    
    data = GetSet(&num); 
    
    if (data == NULL) {
        return 1;
    }
    
    printf("Number of slots: %d\n", num);
    printf("Slots: ");
    for (i = 0; i < num; i++) 
    {
        printf("%d", data[i]);
        if (i < num - 1) {
            printf(", ");
        }
    }
    // printf("\n");
    
    // free(data); 

    // return 0;
}

int *GetSet(int *size_ptr) 
{
    int set_size;
    int *array_ptr;
    int i;

    printf("Enter the number of slots: ");
    scanf("%d", &set_size); 

    *size_ptr = set_size; 

    array_ptr = (int *)malloc(sizeof(int) * set_size);

    if (array_ptr == NULL) {
        return NULL;
    }

    printf("Enter %d slots:\n", set_size);
    for (i = 0; i < set_size; i++) {
        printf("Slot %d: ", i + 1);
        scanf("%d", &array_ptr[i]);
    }
    
    return array_ptr;
}