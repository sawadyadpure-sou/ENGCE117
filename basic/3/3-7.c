#include <stdio.h>
#include <string.h>
#include <math.h> 

typedef struct {
    char name[50] ;    
    float target ;      
    float actual ;       
} SalesRecord ;

void cal() {
    int n_records ; 
    double grand_total_commission = 0.0 ;

    if (scanf("%d", &n_records) != 1 || n_records <= 0) {
        return ; 
    }

    SalesRecord records[n_records] ; 

    for (int i = 0 ; i < n_records ; i++) {
        if (scanf("%f %f", &records[i].target, &records[i].actual) != 2) {
            while (getchar() != '\n') ;
            continue ;
        }
        while (getchar() != '\n') ; 
        if (fgets(records[i].name, sizeof(records[i].name), stdin) == NULL) {
            continue ;
        }
        size_t len = strlen(records[i].name) ;

        if (len > 0 && records[i].name[len - 1] == '\n') {

            records[i].name[len - 1] = '\0' ;
        }

        double base_commission = records[i].actual * 0.10 ; 

        if (records[i].actual >= records[i].target * 1.20) {
            base_commission += 200.0 ;
        } 

        else if (records[i].actual >= records[i].target) {
            base_commission += 50.0 ;
        }

        else if (records[i].actual < records[i].target * 0.90) {
            base_commission -= 100.0 ; 
        }

        grand_total_commission += base_commission ;
    }
    
    printf("Grand Total Commission: %.2f\n", grand_total_commission) ;
}

int main() {
    cal() ;
    return 0 ;
}