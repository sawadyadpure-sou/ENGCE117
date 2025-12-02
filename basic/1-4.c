#include <stdio.h>

int main() 

{

    int x; //รับจากผู้ใช้
    int result = 0; // คำตอบ
    int i; // ไว้นับจำนวนครั้ง
    
    if (scanf("%d", &x) >= 1) 

    {

        for (i = 1; i <= x; i++)

        {
            result = result + i;
        }
    }

    printf("%d\n", result);

    return 0;

}