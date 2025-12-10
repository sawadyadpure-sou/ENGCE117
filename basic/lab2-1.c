#include <stdio.h>
#include <string.h> 

void reverse (char chr1[], char chr2[]) {
    int len = strlen(chr1) ; 
    int x, y ;

    for (x = len - 1, y = 0; x >= 0; x--, y++) {
        chr2[y] = chr1[x] ;
    }
    chr2[y] = '\0' ; 
}

int main() {
    char text[50] = "I love you"; 
    char out[50];                 

    reverse(text, out);

    printf("chr1: \"%s\"\n", text);
    printf("chr2: \"%s\"\n", out); 

    return 0;
}