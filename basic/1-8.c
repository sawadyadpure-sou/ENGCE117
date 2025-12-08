#include <stdio.h>

void check_system_status(int day_of_week_code, int current_hour) {
    switch (day_of_week_code) {
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
            if (current_hour >= 8 && current_hour < 17) {
                printf("System Running (Workday)\n") ;
            } 
            else if (current_hour >= 0 && current_hour <= 23) {
                printf("System Idle (Off-hours)\n") ;
            } 
            else {
                printf("Invalid Hour Range\n") ;
            }
            break;

        case 7:
        case 1: 
            printf("Weekend Relax Mode\n") ;
            break ;

        default:
            printf("Invalid Day Code\n") ;
            break ;
    }
}

int main() {
    int day_of_week_code;
    int current_hour;

    if (scanf("%d %d", &day_of_week_code, &current_hour) != 2) 
    {
        printf("Error: Invalid input format.\n") ;
        return 1;
    }

    check_system_status(day_of_week_code, current_hour) ;

    return 0 ;
}