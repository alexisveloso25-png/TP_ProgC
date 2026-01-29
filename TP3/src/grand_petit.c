#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

int main() {
    int tableau[100];
    int i;
    int plus_grand, plus_petit;

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // 1. Remplissage du tableau avec des valeurs entre 1 et 1000
    for (i = 0; i < 100; i++) {
        tableau[i] = (rand() % 1000) + 1;
    }

    // 2. Initialisation du plus grand et du plus petit avec le premier élément
    plus_grand = tableau[0];
    plus_petit = tableau[0];

    // 3. Parcours du tableau pour trouver les extrêmes
    for (i = 1; i < 100; i++) {
        if (tableau[i] > plus_grand) {
            plus_grand = tableau[i];
        }
        if (tableau[i] < plus_petit) {
            plus_petit = tableau[i];
        }
    }

    // 4. Affichage des résultats (Exemple personnalisé)
    printf("--- Statistiques du groupe (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Tableau de 100 scores genere avec succes.\n\n");
    
    printf("Le score le plus eleve (Maximum) est : %d\n", plus_grand);
    printf("Le score le plus bas (Minimum) est : %d\n", plus_petit);

    return 0;
}
