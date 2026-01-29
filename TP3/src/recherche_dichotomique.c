#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int cible, i, j, temp;
    int gauche, droite, milieu;
    int trouve = 0;

    srand(time(NULL));

    // 1. Génération et Tri (nécessaire pour la recherche dichotomique)
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 200) - 50; // Valeurs entre -50 et 149
    }

    // Tri à bulles pour garantir l'ordre croissant
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    // 2. Affichage du tableau trié
    printf("--- Recherche de scores (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Tableau trie :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 3. Entrée utilisateur
    printf("Entrez l'entier que vous souhaitez chercher : ");
    if (scanf("%d", &cible) != 1) {
        printf("Entree invalide.\n");
        return 1;
    }

    // 4. Algorithme de RECHERCHE DICHOTOMIQUE
    gauche = 0;
    droite = n - 1;

    while (gauche <= droite) {
        milieu = gauche + (droite - gauche) / 2;

        // Si la cible est au milieu
        if (tableau[milieu] == cible) {
            trouve = 1;
            break;
        }
        // Si la cible est plus grande, on ignore la moitié gauche
        if (tableau[milieu] < cible) {
            gauche = milieu + 1;
        }
        // Si la cible est plus petite, on ignore la moitié droite
        else {
            droite = milieu - 1;
        }
    }

    // 5. Résultat
    if (trouve) {
        printf("Resultat : entier present\n");
    } else {
        printf("Resultat : entier absent\n");
    }

    return 0;
}
