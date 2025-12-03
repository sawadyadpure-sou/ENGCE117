#include <stdio.h>

int main() {
    int วัน, ชั่วโมง;

    // อ่านค่า วัน และ ชั่วโมง
    if (scanf("%d %d", &วัน, &ชั่วโมง) != 2) {
        return 1;
    }

    // ใช้ switch ในการตรวจสอบ วัน
    switch (วัน) {
        case 1: // วันจันทร์
        case 2: // วันอังคาร
        case 3: // วันพุธ
        case 4: // วันพฤหัสบดี
        case 5: // วันศุกร์ (1-5 เป็นวันทำการ)
            // ตรวจสอบ ชั่วโมง โดยใช้ if-else ภายใน case
            if (ชั่วโมง >= 8 && ชั่วโมง <= 17) {
                printf("System Running (Workday)\n");
            } else {
                printf("System Idle (Off-hours)\n");
            }
            break;

        case 6: // วันเสาร์
        case 7: // วันอาทิตย์ (6-7 เป็นวันหยุดสุดสัปดาห์)
            // แสดงผลลัพธ์เดียวเสมอสำหรับวันหยุด
            printf("Weekend Relax Mode\n");
            break;

        default:
            // ถ้า วัน ไม่อยู่ในช่วง 1-7
            printf("Invalid Day Code\n");
            break;
    }

    return 0;
}