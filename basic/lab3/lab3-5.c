#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[ 50 ] ;
    int age ;
} ;

// Prototype ตามโจทย์: ฟังก์ชันคืนค่าเป็น Pointer ไปยัง Array ขนาด 10
struct student ( *GetStudent( int *room ) )[ 10 ] ;

int main() {
    struct student ( *children )[ 10 ] ;
    int group ;
    children = GetStudent( &group ) ;

    free( children ) ;
    return 0 ;
}

struct student ( *GetStudent( int *room ) )[ 10 ] {
    printf( "Enter number of rooms: " ) ;
    scanf( "%d", room ) ;

    struct student ( *child )[ 10 ] = malloc( ( *room ) * sizeof( *child ) ) ;

    for ( int i = 0 ; i < *room ; i++ ) {
        printf( "Room %d:\n", i + 1 ) ;
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "  Student %d name: ", j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            printf( "  Student %d age: ", j + 1 ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
        }
    }

    return child ; 
}