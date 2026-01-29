#include <stdio.h>

int main() {
    int compteur = 5; // Modifiez cette valeur (doit être < 10)

    if (compteur >= 10) {
        printf("Erreur : le compteur doit être inférieur à 10.\n");
        return 1;
    }

    printf("--- Triangle avec boucle FOR ---\n");
    for (int i = 1; i <= compteur; i++) {
        for (int j = 1; j <= i; j++) {
            // Conditions pour afficher une étoile :
            // 1. Première colonne (j == 1)
            // 2. Dernière colonne de la ligne (j == i)
            // 3. Dernière ligne du triangle (i == compteur)
            if (j == 1 || j == i || i == compteur) {
                printf("* ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }

    return 0;
}
