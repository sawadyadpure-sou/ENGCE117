#include <stdio.h>
#include <string.h> 
#include <stdlib.h> 

char* reverse (char chr1[]) {
    int len = strlen(chr1) ;
    char *chr2 = (char *)malloc(len + 1) ;
    if (chr2 == NULL) {
        return NULL ;
    }
    int x, y ; 
    for (x = len - 1, y = 0; x >= 0; x--, y++) {
        chr2[y] = chr1[x];
    }
    chr2[y] = '\0';
    return chr2; 
}
int main() {
    char text_in[50] = "I love you" ;
    char *out_rev ; 

    out_rev = reverse(text_in) ;

    printf("%s\n", text_in) ;
    
    if (out_rev != NULL) {
        printf("%s\n", out_rev) ;
        free(out_rev) ; 
    } else {
        printf("Memory allocation failed.\n") ;
    }

    return 0 ;
}