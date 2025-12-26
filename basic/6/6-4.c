#include <stdio.h>

// 1. การสร้าง Function: รับตัวเลข 2 ตัว และ Pointer สำหรับเก็บผลลัพธ์ 2 ตัว
void calculate_sum_product(int num1, int num2, int *sum_ptr, int *prod_ptr) {
    // ใช้ Dereference Operator (*) เพื่อแก้ไขค่าในที่อยู่หน่วยความจำที่ส่งมา
    *sum_ptr = num1 + num2;    // เก็บผลรวม
    *prod_ptr = num1 * num2;   // เก็บผลคูณ
}

int main() {
    // 2. การดำเนินการใน main: ประกาศตัวแปรสำหรับรับค่าและเตรียมรับผลลัพธ์
    int val_A, val_B;
    int result_sum, result_product;

    // รับค่าเริ่มต้นจากผู้ใช้
    printf("Enter first number (val_A): ");
    scanf("%d", &val_A);
    printf("Enter second number (val_B): ");
    scanf("%d", &val_B);

    // เรียกใช้ Function โดยส่งค่าตัวแปร และ "ที่อยู่" ของตัวแปรผลลัพธ์เข้าไป
    calculate_sum_product(val_A, val_B, &result_sum, &result_product);

    // 3. การแสดงผลลัพธ์ (Report)
    printf("\n--- Calculation Report ---\n");
    printf("Input Numbers: %d and %d\n", val_A, val_B);
    printf("Calculated Sum: %d\n", result_sum);
    printf("Calculated Product: %d\n", result_product);
    printf("--------------------------\n");

    return 0;
}