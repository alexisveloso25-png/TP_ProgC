#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int i, j, temp;

    srand(time(NULL));

    // 1. Remplissage aléatoire du tableau (entre -100 et 100)
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 201) - 100; 
    }

    // 2. Affichage du tableau non trié
    printf("--- Tableau de scores (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Tableau non trie :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 3. Algorithme de Tri à Bulles
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            // Si l'élément actuel est plus grand que le suivant, on échange
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    // 4. Affichage du tableau trié
    printf("Tableau trie par ordre croissant :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n");

    return 0;
}
