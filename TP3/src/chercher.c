#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int cible, i;
    int compteur = 0;

    srand(time(NULL));

    // 1. Remplissage aléatoire du tableau (entre -10 et 50 pour avoir des doublons)
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 61) - 10;
    }

    // 2. Affichage du tableau initial
    printf("--- Tableau de scores (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Tableau :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
        // Retour à la ligne tous les 10 nombres pour la lisibilité
        if ((i + 1) % 10 == 0) printf("\n");
    }
    printf("\n");

    // 3. Entree de l'utilisateur
    printf("Entrez l'entier que vous souhaitez chercher : ");
    fflush(stdout);
    if (scanf("%d", &cible) != 1) {
        printf("Erreur de saisie.\n");
        return 1;
    }

    // 4. Logique de recherche sequentielle et comptage
    for (i = 0; i < n; i++) {
        if (tableau[i] == cible) {
            compteur++;
        }
    }

    // 5. Affichage du resultat
    if (compteur > 0) {
        printf("\nResultat : entier present\n");
        printf("On le voit %d fois dans le tableau.\n", compteur);
    } else {
        printf("\nResultat : entier absent\n");
    }

    return 0;
}
