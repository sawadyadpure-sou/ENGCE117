#include <stdio.h>

void TowerHanoi( int m, int i, int j ) {
    // m คือจำนวนจาน, i คือเสาต้นทาง, j คือเสาปลายทาง
    // เสาที่เหลือ (auxiliary) สามารถหาได้จาก 6 - i - j (เพราะ 1+2+3 = 6)
    int k ;
    
    if ( m > 0 ) {
        k = 6 - i - j ;
        
        // ย้ายจาน m-1 ใบจากเสา i ไปยังเสา k (พักไว้)
        TowerHanoi( m - 1, i, k ) ;
        
        // พิมพ์การย้ายจานใบที่ m จาก i ไป j
        printf( "Disc %d from %d to %d\n", m, i, j ) ;
        
        // ย้ายจาน m-1 ใบจากเสา k ไปยังเสา j
        TowerHanoi( m - 1, k, j ) ;
    }
}

int main() {
    TowerHanoi( 3, 1, 3 ) ;
    return 0 ;
}