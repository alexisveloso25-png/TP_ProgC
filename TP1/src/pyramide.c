#include <stdio.h>

int main() {
    // Déclaration et initialisation
    int n = 10; 
    int i, j;

    printf("--- Génération de la pyramide (hauteur : %d) ---\n\n", n);

    // Boucle principale pour chaque ligne (de 1 à n)
    for (i = 1; i <= n; i++) {
        
        // 1. Boucle pour les espaces (centrage)
        // Il faut afficher (n - i) espaces pour que la pointe soit au centre
        for (j = 1; j <= n - i; j++) {
            printf(" ");
        }

        // 2. Boucle pour les nombres croissants (de 1 à i)
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }

        // 3. Boucle pour les nombres décroissants (de i-1 à 1)
        for (j = i - 1; j >= 1; j--) {
            printf("%d", j);
        }

        // Passage à la ligne suivante après chaque niveau
        printf("\n");
    }

    printf("\nGénération de la pyramide terminée.\n");

    return 0;
}
