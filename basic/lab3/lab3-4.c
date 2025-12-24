#include <stdio.h>

// สมมติโครงสร้าง struct student (เพื่อให้ code คอมไพล์ผ่าน)
struct student {
    char name[50] ;
    int age ;
} ;

void GetStudent( struct student child[][ 10 ], int *room ) ;

int main() {
    struct student children[ 20 ][ 10 ] ;
    int group ;
    GetStudent( children, &group ) ;
    return 0 ;
}

void GetStudent( struct student child[][ 10 ], int *room ) {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;

    for ( int i = 0 ; i < *room ; i++ ) {
        printf( "Room %d:\n", i + 1 ) ;
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "  Student %d name: ", j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            printf( "  Student %d age: ", j + 1 ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
        }
    }
}