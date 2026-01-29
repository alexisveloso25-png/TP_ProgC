#include <stdio.h>

int main() {
    int n = 7; // Valeur fixe pour tester sans saisie clavier
    long long u0 = 0;
    long long u1 = 1;
    long long suivant;

    printf("Suite de Fibonacci jusqu'a U%d :\n", n);

    for (int i = 0; i <= n; i++) {
        if (i == 0) {
            printf("U0 = %lld\n", u0);
        } 
        else if (i == 1) {
            printf("U1 = %lld\n", u1);
        } 
        else {
            suivant = u0 + u1;
            printf("U%d = %lld\n", i, suivant);
            
            // On décale les valeurs
            u0 = u1;
            u1 = suivant;
        }
    }

    return 0;
}
