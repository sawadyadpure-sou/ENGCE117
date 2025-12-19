#include <stdio.h>

void newana(int arr[], int n) {
    int visited[10] ; 
    
    for (int i = 0; i < n; i++) {
        visited[i] = 0 ;
    }

    printf("Number | Frequency\n") ;
    printf("-------|----------\n") ;

    for (int i = 0; i < n; i++) {
        if (visited[i] == 0) {
            int count = 1 ;
            for (int j = i + 1; j < n; j++) {
                if (arr[i] == arr[j]) {
                    count++ ;
                    visited[j] = 1 ; 
                }
            }
            printf("%-6d | %d\n", arr[i], count) ;
        }
    }
}

int main() {
    int N ;
    int data[10] ; 

    scanf("%d", &N) ;

    for (int i = 0; i < N; i++) {
        scanf("%d", &data[i]) ;
    }

    printf("\nRecorded data: ") ;
    for (int i = 0; i < N; i++) {
        printf("%d ", data[i]) ; 
    }
    printf("\n") ;

    newana(data, N) ;

    return 0 ;
}