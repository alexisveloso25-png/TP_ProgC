#include <stdio.h>

int main() {
    int n, i;
    // On utilise long long pour éviter les dépassements de capacité sur les grands n
    long long u0 = 0, u1 = 1, suivant;

    printf("Entrez la valeur de n pour la suite de Fibonacci : ");
    if (scanf("%d", &n) != 1 || n < 0) {
        printf("Veuillez entrer un entier positif.\n");
        return 1;
    }

    printf("Suite de Fibonacci jusqu'a U%d :\n", n);

    for (i = 0; i <= n; i++) {
        if (i == 0) {
            printf("%lld", u0);
        } else if (i == 1) {
            printf(", %lld", u1);
        } else {
            // Calcul du terme actuel : Un = Un-1 + Un-2
            suivant = u0 + u1;
            printf(", %lld", suivant);

            // Mise à jour des variables pour l'itération suivante
            u0 = u1;      // L'ancien U(n-1) devient U(n-2)
            u1 = suivant; // Le terme actuel devient U(n-1)
        }
    }

    printf("\n");
    return 0;
}
