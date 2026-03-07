#include <stdio.h>
#include <stdlib.h>

int *KnapsackGreedy( int *w, int *v, int n, int wx ) ;

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x = KnapsackGreedy( w, v, n, wx ) ;
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;
    return 0 ;
}

int *KnapsackGreedy( int *w, int *v, int n, int wx ) {
    int *x = ( int * ) calloc( n, sizeof( int ) ) ;
    int current_w = 0 ;
    for ( int i = n - 1 ; i >= 0 ; i-- ) {
        if ( current_w + w[ i ] <= wx ) {
            x[ i ] = 1 ;
            current_w += w[ i ] ;
        }
    }
    return x ;
}