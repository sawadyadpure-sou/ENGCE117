#include <stdio.h>

void evaluateAttack(int attackerLevel, int opponentLevel, int opponentArmor) {
    
    float baseAttack = attackerLevel * 10.0 ;
    float damageReduction ;

    if (opponentArmor < 50) {
        damageReduction = 0.20 ; 
    } else {
        damageReduction = 0.40 ; 
    }

    float netDamage = baseAttack * (1.0 - damageReduction) ;

    if (netDamage >= 150.0) {
        printf("SUCCESS! Net Damage: %.2f\n", netDamage) ;
    } else {
        float deficit = 150.0 - netDamage ;
        printf("FAIL. Deficit: %.2f\n", deficit) ;
    }
}

int main() {
    int nCalculations ;

    if (scanf("%d", &nCalculations) != 1) return 0 ;

    for (int i = 0 ; i < nCalculations ; i++) {
        int atkLvl, oppLvl, oppArm ;

        if (scanf("%d %d %d", &atkLvl, &oppLvl, &oppArm) == 3) {
            evaluateAttack(atkLvl, oppLvl, oppArm) ;
        }
    }

    return 0 ;
}