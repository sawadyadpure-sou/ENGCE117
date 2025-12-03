#include <stdio.h>

int main() {
    int dayCode, hour;

    // อ่านค่า dayCode และ hour
    if (scanf("%d %d", &dayCode, &hour) != 2) {
        return 1;
    }
    //ตรวจสอบ dayCode
    switch (dayCode) {
        case 1: // วันจันทร์
        case 2: // วันอังคาร
        case 3: // วันพุธ
        case 4: // วันพฤหัสบดี
        case 5: // วันศุกร์ (1-5 เป็นวันทำการ)
            // ตรวจสอบ hour โดยใช้ if-else ภายใน case
            if (hour >= 8 && hour <= 17) {
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
            // ถ้า dayCode ไม่อยู่ในช่วง 1-7
            printf("Invalid Day Code\n");
            break;
    }

    return 0;
}