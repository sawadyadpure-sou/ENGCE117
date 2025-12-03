#include <stdio.h>

int main() 
{
    int customerType;
    float consumption_kwh;
    float totalBill = 0.0;

    if (scanf("%d %f", &customerType, &consumption_kwh) != 2) 
    {
        return 1; // เกิดข้อผิดพลาดในการอ่านข้อมูล
    }

    if (customerType == 1) 
    {
        if (consumption_kwh >= 0 && consumption_kwh <= 100) 
        {
            totalBill = consumption_kwh * 3.0;
        } else if (consumption_kwh > 100) 
        {
            totalBill = consumption_kwh * 4.0;
        }
    } else if (customerType == 2) 
    {
        if (consumption_kwh >= 0 && consumption_kwh <= 500) 
        {
            totalBill = consumption_kwh * 5.0;
        } else if (consumption_kwh > 500) 
        {
            totalBill = consumption_kwh * 6.5;
        }
    } else
    {
        printf("Invalid Customer Type\n");
    }

    if (customerType == 1 || customerType == 2) 
    {
        printf("%.2f\n", totalBill);
    }

    return 0;
}