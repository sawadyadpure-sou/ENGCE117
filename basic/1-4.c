#include <stdio.h>

int calculateSum(int N) 
{
    int sum = 0; 
    int i;       


    if (N < 1) 
    {
        return 0; 
    }


    for (i = 1; i <= N; i++) 
    {
        sum = sum + i; 
    }

    return sum; 
}


int main() 
{
    int N;       
    int result;  




    if (scanf("%d", &N) != 1) 
    {
        return 1; 
    }

    result = calculateSum(N);

    printf("%d", result);

    return 0;
}