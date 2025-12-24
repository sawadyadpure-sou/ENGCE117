#include <stdio.h>
#include <string.h>
#include <stdlib.h> // จำเป็นสำหรับการใช้ malloc

struct studentNode {
    char name[ 20 ] ;
    int age ;
    char sex ;
    float gpa ;
    struct studentNode *next ;
} ;

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) ;
void GoNext2( struct studentNode ***walk ) ;

int main() {
    struct studentNode *start, *now1, **now2 ;

    // ใช้ malloc ในการจองหน่วยความจำแทน new
    start = ( struct studentNode* )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start, "one", 6, 'M', 3.11 ) ;

    start->next = ( struct studentNode* )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next, "two", 8, 'F', 3.22 ) ;

    start->next->next = ( struct studentNode* )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next->next, "three", 10, 'M', 3.33 ) ;

    start->next->next->next = ( struct studentNode* )malloc( sizeof( struct studentNode ) ) ;
    SaveNode( start->next->next->next, "four", 12, 'F', 3.44 ) ;

    now1 = start ;
    now2 = &start ; // กำหนดให้ now2 เก็บที่อยู่ของพอยท์เตอร์ start

    // เรียกใช้ GoNext2 โดยส่งที่อยู่ของ now2 (&now2) เข้าไปเพื่อให้จัดการระดับพอยท์เตอร์ที่เหมาะสม
    GoNext2( &now2 ) ;
    printf( "Now - 1 %s ", ( *now2 )->name ) ;

    return 0 ;
}

void SaveNode( struct studentNode *child, char n[], int a, char s, float g ) {
    strcpy( child->name, n ) ;
    child->age = a ;
    child->sex = s ;
    child->gpa = g ;
    child->next = NULL ; // กำหนดค่าเริ่มต้นให้พอยท์เตอร์ถัดไป
}

void GoNext2( struct studentNode ***walk ) {
    // ใช้ dereference 2 ชั้น ( **walk ) เพื่อเข้าถึงและแก้ไขตัวแปร now2 ใน main
    if ( *walk != NULL && ( **walk ) != NULL && ( **walk )->next != NULL ) {
        **walk = ( **walk )->next ;
    }
}