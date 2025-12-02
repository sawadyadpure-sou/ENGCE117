#include <stdio.h>

void updateSums(int currentNumber, int *evenTotal, int *oddTotal) 
{

    if (currentNumber == 0) {
        return; 
    }

    if (currentNumber % 2 == 0) 
    {
        *evenTotal += currentNumber; 
    } 

    else 
    {
        *oddTotal += currentNumber; 
    }
}

int main() 
{
    int inputValue;       // ตัวเลขที่ป้อน
    int totalEvenSum = 0; // เลขคู่
    int totalOddSum = 0;  // เลขคี่

    if (scanf("%d", &inputValue) != 1) 
    {
        return 1; 
    }

    while (inputValue != 0) 
    {
        updateSums(inputValue, &totalEvenSum, &totalOddSum);

        if (scanf("%d", &inputValue) != 1) 
        {
            break; 
        }
    }

    printf("\nEven Sum: %d\n", totalEvenSum);
    printf("Odd Sum: %d\n", totalOddSum);

    return 0;
}