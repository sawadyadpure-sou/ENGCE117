#include <stdio.h>

int main() {
    int number1, number2, operation, equal_to;

    if (scanf("%d %d %d", &number1, &number2, &operation) != 3 ) {
        return 1;
    };

    switch (operation) {
    case 1:
        equal_to = number1 + number2;
        printf("%d", equal_to);
        break;
    case 2:
        equal_to = number1 - number2;
        printf("%d", equal_to);
        break;
    case 3:
        equal_to = number1 * number2;
        printf("%d", equal_to);
        break;
    case 4:
        equal_to = number1 / number2;
        printf("%d", equal_to);
        break;
    default :
        printf("Invalid Operation");
        break;
    }

    return 0;
}