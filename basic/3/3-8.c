#include <stdio.h>

struct Campaign {
    char name[50] ;
    float productPrice ;
    int salesCount ;
    float adSpend ;
} ;

void calculateAndPrint(struct Campaign c) {
    float commissionRate ;
    int ratePercent ;

    if (c.salesCount >= 20) {
        commissionRate = 0.20 ;
        ratePercent = 20 ;
    } else if (c.salesCount >= 10) {
        commissionRate = 0.15 ;
        ratePercent = 15 ;
    } else {
        commissionRate = 0.10 ;
        ratePercent = 10 ;
    }

    float totalRevenue = c.salesCount * c.productPrice ;
    float totalCommission = totalRevenue * commissionRate ;
    float netResult = totalCommission - c.adSpend ;

    printf("--- Campaign: %s ---\n", c.name) ;
    printf("Sales: %d, Ad Spend: %.2f\n", c.salesCount, c.adSpend) ;
    printf("Rate Used: %d%%\n", ratePercent) ;
    printf("Calculation: (%.2f * %d%%) - %.2f = %.2f\n", totalRevenue, ratePercent, c.adSpend, netResult) ;
    printf("Net Result: %.2f\n", netResult) ;
}

int main() {
    int N ;
    if (scanf("%d", &N) != 1) return 0 ;

    struct Campaign camp[N] ;

    for (int i = 0 ; i < N ; i++) {
        scanf("%s %f %d %f", camp[i].name, &camp[i].productPrice, &camp[i].salesCount, &camp[i].adSpend) ;
    }

    for (int i = 0 ; i < N ; i++) {
        calculateAndPrint(camp[i]) ;
    }

    return 0 ;
}