#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int i, j, temp;

    srand(time(NULL));

    // 1. Remplissage aléatoire entre -100 et 100
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 201) - 100; 
    }

    printf("--- SYSTEME DE CLASSEMENT (Alexis, Salmane, Kais, Mohamed) ---\n\n");

    // 2. AFFICHAGE DU TABLEAU DE BASE (NON TRIÉ)
    printf("TABLEAU DE BASE (Valeurs generees) :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n------------------------------------------------------------\n\n");

    // 3. TRI CROISSANT (Petit -> Grand)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("TABLEAU TRIE PAR ORDRE CROISSANT :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n------------------------------------------------------------\n\n");

    // 4. TRI DÉCROISSANT (Grand -> Petit)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] < tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("TABLEAU TRIE PAR ORDRE DECROISSANT :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
