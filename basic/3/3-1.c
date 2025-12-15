#include <stdio.h>
#include <string.h> 

typedef struct {
    char name[50] ;   
    int productId ;    
    float price ;     
} Product ;

void readAndDisplayProduct() {
    Product item1 ;

    if (scanf("%d", &item1.productId) != 1) {
        printf("Error reading Product ID.\n") ;
        return ;
    }

    if (scanf("%f", &item1.price) != 1) {
        printf("Error reading Price.\n") ;
        return ;
    }

    while (getchar() != '\n') ; 

    if (fgets(item1.name, sizeof(item1.name), stdin) == NULL) {
        printf("Error reading Product Name.\n") ;
        return ;
    }

    size_t len = strlen(item1.name) ;
    if (len > 0 && item1.name[len - 1] == '\n') {
        item1.name[len - 1] = '\0' ;
    }

    printf("ID: %d\n", item1.productId) ;
    printf("Price: %.2f\n", item1.price) ;
    printf("Name: %s\n", item1.name) ;
}

int main() {
    
    readAndDisplayProduct() ;
    return 0 ;
}