#include <stdio.h>

int main() 
{
    int number;      // เก็บ เต็ม
    int evenSum = 0; // เก็บ คู่
    int oddSum = 0;  // เก็บ คี่



    if (scanf("%d", &number) != 1) // ถ้าได้รับค่าที่ไม่ใช่ตัวเลข จะ จบการทำงานทันที
    {
        return 1;
    }

    while (number != 0)  // ถ้าเลขไม่เท่ากับ 0 ให้ทำงาน ต่อไปเรื่อยๆ
    {
        
        if (number % 2 == 0)  // ถ้าเลขเป็นเลขคู่ให้เอาไป + เลขกับตัวแปร evensum 
        {
            evenSum += number; 
        } 

        else 

        {
            oddSum += number; // ถ้าเลขเป็นเลขคี่ให้เอาไป + เลขกับตัวแปร oddsum
        }

        if (scanf("%d", &number) != 1) // ถ้ารับค่าที่ไม่ใช่ตัวเลขหรือ 0 จะจบ loop
        {
            break; 
        }

    }

    printf("\nEven Sum: %d\n", evenSum);
    printf("Odd Sum: %d\n", oddSum);

    return 0;
}