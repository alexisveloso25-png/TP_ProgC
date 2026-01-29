#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int i, j, temp;

    srand(time(NULL));

    // 1. Remplissage aléatoire
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 201) - 100; 
    }

    printf("--- Système de classement (Alexis, Salmane, Kais, Mohamed) ---\n\n");

    // 2. TRI CROISSANT (Petit -> Grand)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) { // Signe '>' pour croissant
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("Tableau trie par ordre CROISSANT :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 3. TRI DÉCROISSANT (Grand -> Petit)
    // On reprend le tableau déjà trié et on ré-applique l'algorithme inverse
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] < tableau[j + 1]) { // Signe '<' pour décroissant
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    printf("Tableau trie par ordre DECROISSANT :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
