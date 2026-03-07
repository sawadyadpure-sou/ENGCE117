#include <stdio.h>
#include <stdlib.h>

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) ;

int max_val = 0 ;
int *best_x ;

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x, vx ;

    x = ( int * ) calloc( n, sizeof( int ) ) ;
    best_x = ( int * ) calloc( n, sizeof( int ) ) ;
    
    vx = KnapsackBT( w, v, n, wx, 0, x ) ;
    
    printf( "Value = %d\n", vx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", best_x[ i ] ) ;
    
    free( x ) ;
    free( best_x ) ;
    
    return 0 ;
}

int KnapsackBT( int *w, int *v, int n, int wx, int i, int *x ) {
    if ( i == n ) {
        int current_val = 0 ;
        int current_w = 0 ;
        
        for ( int j = 0 ; j < n ; j++ ) {
            if ( x[ j ] == 1 ) {
                current_w += w[ j ] ;
                current_val += v[ j ] ;
            }
        }

        if ( current_w <= wx && current_val > max_val ) {
            max_val = current_val ;
            for ( int j = 0 ; j < n ; j++ ) best_x[ j ] = x[ j ] ;
        }
        return max_val ;
    }

    x[ i ] = 1 ;
    KnapsackBT( w, v, n, wx, i + 1, x ) ;

    x[ i ] = 0 ;
    KnapsackBT( w, v, n, wx, i + 1, x ) ;

    return max_val ;
}