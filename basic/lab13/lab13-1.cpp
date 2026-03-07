#include <stdio.h>
#include <stdlib.h>

int *KnapsackDP( int *w, int *v, int n, int wx ) ;

int main() {
    int n = 5, wx = 11 ;
    int w[ 5 ] = { 1, 2, 5, 6, 7 } ;
    int v[ 5 ] = { 1, 6, 18, 22, 28 } ;
    int *x ;
    
    x = KnapsackDP( w, v, n, wx ) ;
    
    for( int i = 0 ; i < n ; i++ ) printf( "%d ", x[ i ] ) ;

    free( x ) ;
    
    return 0 ;
}

int *KnapsackDP( int *w, int *v, int n, int wx ) {
    int i, j ;
    int **dp = ( int ** ) malloc( ( n + 1 ) * sizeof( int * ) ) ;
    for ( i = 0 ; i <= n ; i++ ) {
        dp[ i ] = ( int * ) malloc( ( wx + 1 ) * sizeof( int ) ) ;
    }

    for ( i = 0 ; i <= n ; i++ ) {
        for ( j = 0 ; j <= wx ; j++ ) {
            if ( i == 0 || j == 0 ) {
                dp[ i ][ j ] = 0 ;
            } else if ( w[ i - 1 ] <= j ) {
                int val1 = v[ i - 1 ] + dp[ i - 1 ][ j - w[ i - 1 ] ] ;
                int val2 = dp[ i - 1 ][ j ] ;
                dp[ i ][ j ] = ( val1 > val2 ) ? val1 : val2 ;
            } else {
                dp[ i ][ j ] = dp[ i - 1 ][ j ] ;
            }
        }
    }

    int *x = ( int * ) calloc( n, sizeof( int ) ) ;
    int res = dp[ n ][ wx ] ;
    int temp_w = wx ;

    for ( i = n ; i > 0 && res > 0 ; i-- ) {
        if ( res != dp[ i - 1 ][ temp_w ] ) {
            x[ i - 1 ] = 1 ;
            res -= v[ i - 1 ] ;
            temp_w -= w[ i - 1 ] ;
        }
    }

    for ( i = 0 ; i <= n ; i++ ) free( dp[ i ] ) ;
    free( dp ) ;

    return x ;
}