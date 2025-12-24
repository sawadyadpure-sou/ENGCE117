#include <stdio.h>

struct student {
    char name[ 50 ] ;
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
        for ( int j = 0 ; j < 10 ; j++ ) {
            printf( "Room %d, Student %d name: ", i + 1, j + 1 ) ;
            scanf( "%s", child[ i ][ j ].name ) ;
            printf( "Room %d, Student %d age: ", i + 1, j + 1 ) ;
            scanf( "%d", &child[ i ][ j ].age ) ;
        }
    }
}