#include <stdio.h>

void loopprint_hello(int n); 


int main() {
    int n;
    
   
    
    scanf("%d", &n);
    
    loopprint_hello(n); 

    return 0;
}

void loopprint_hello(int n){
     for(int i = 0; i < n; i++) {
        printf(" %d hello world\n",i+1);
    }
}
