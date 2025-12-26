#include <stdio.h>

float calculate_win_odds(int outs) {
    float win_probability = (float)outs * 4 ;
    return win_probability ;
}

int main() {
    int outs = 9 ;
    float win_percent ;

    win_percent = calculate_win_odds(outs) ;

    printf("--- Poker Win Odds Report ---\n") ;
    printf("Number of Outs used for calculation: %d\n", outs) ;

    printf("Calculated Win Probability: %.2f%%\n", win_percent) ;

    if (win_percent >= 30.0) {
        printf("Assessment: HIGH Win Probability\n") ;
    } else {
        printf("Assessment: LOW Win Probability\n") ;
    }
    
    printf("-----------------------------\n") ;

    return 0 ;
}