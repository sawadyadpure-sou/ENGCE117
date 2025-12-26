#include <stdio.h>

void increase_value(int *number_ptr) {
    *number_ptr = *number_ptr + 10;
}

int main() {
    int data;

    scanf("%d", &data);
    printf("before : %d\n", data);
    increase_value(&data);
    printf("after : %d\n", data);

    return 0;
}