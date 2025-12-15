#include <stdio.h>

typedef struct {
    int studentId ;
    int score ;
    int totalClasses ;
    int absentClasses ;
    double attendancePercent ;
    char result[50] ; 
} Student ;

double calculateAttendance(int total_classes, int absent_classes) {
    if (total_classes <= 0) {
        return 0.0 ; 
    }
    int present_classes = total_classes - absent_classes ;
    return ((double)present_classes / total_classes) * 100.0 ;
}

void processStudents(int n_students) {
    Student students[n_students] ; 

    int pass_count = 0 ;
    int fail_count = 0 ;

    for (int i = 0 ; i < n_students ; i++) {
        if (scanf("%d %d %d %d", 
                  &students[i].studentId, 
                  &students[i].score, 
                  &students[i].totalClasses, 
                  &students[i].absentClasses) != 4) 
        {
            while (getchar() != '\n') ;
            continue ; 
        }

        students[i].attendancePercent = calculateAttendance(students[i].totalClasses, students[i].absentClasses) ;

        int score_ok = (students[i].score >= 50) ;
        int attendance_ok = (students[i].attendancePercent >= 75.0) ;

        int len = 0 ; 

        if (score_ok && attendance_ok) {
            len = snprintf(students[i].result, sizeof(students[i].result), "PASS") ;
            pass_count++ ;
        } else {
            fail_count++ ;
            
            if (!score_ok && !attendance_ok) {
                len = snprintf(students[i].result, sizeof(students[i].result), "FAIL (Both Score and Attendance)") ;
            } else if (!score_ok) {
                len = snprintf(students[i].result, sizeof(students[i].result), "FAIL (Score)") ;
            } else if (!attendance_ok) {
                len = snprintf(students[i].result, sizeof(students[i].result), "FAIL (Attendance)") ;
            }
        }
    }

    for (int i = 0 ; i < n_students ; i++) {
        printf("%d: %s\n", students[i].studentId, students[i].result) ;
    }
    
    printf("Summary: PASS = %d, FAIL = %d\n", pass_count, fail_count) ;
}

int main() {
    int n_students ;

    if (scanf("%d", &n_students) != 1 || n_students <= 0) {
        return 1 ;
    }
    processStudents(n_students) ;
    return 0 ;
}