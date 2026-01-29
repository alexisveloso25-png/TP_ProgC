#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int tableau[100];
    int n = 100;
    int cible, i, j, temp;
    int gauche, droite, milieu;
    int indice_trouve = -1;
    int compteur = 0;

    srand(time(NULL));

    // 1. Génération de valeurs (Plage réduite à 50 pour avoir plus de doublons)
    for (i = 0; i < n; i++) {
        tableau[i] = (rand() % 51) - 10; // Valeurs entre -10 et 40
    }

    // 2. Tri à bulles
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (tableau[j] > tableau[j + 1]) {
                temp = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = temp;
            }
        }
    }

    // 3. Affichage
    printf("--- Recherche Groupée (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Tableau trie :\n");
    for (i = 0; i < n; i++) {
        printf("%d ", tableau[i]);
    }
    printf("\n\n");

    // 4. Saisie
    printf("Entrez l'entier que vous souhaitez chercher : ");
    fflush(stdout);
    scanf("%d", &cible);

    // 5. Recherche dichotomique pour trouver UN indice
    gauche = 0;
    droite = n - 1;
    while (gauche <= droite) {
        milieu = gauche + (droite - gauche) / 2;
        if (tableau[milieu] == cible) {
            indice_trouve = milieu;
            break;
        }
        if (tableau[milieu] < cible) gauche = milieu + 1;
        else droite = milieu - 1;
    }

    // 6. Si trouvé, on compte les répétitions autour de l'indice
    if (indice_trouve != -1) {
        compteur = 1;
        // Regarder à gauche
        int k = indice_trouve - 1;
        while (k >= 0 && tableau[k] == cible) {
            compteur++;
            k--;
        }
        // Regarder à droite
        k = indice_trouve + 1;
        while (k < n && tableau[k] == cible) {
            compteur++;
            k++;
        }
        printf("\nResultat : L'entier %d est present %d fois.\n", cible, compteur);
    } else {
        printf("\nResultat : entier absent.\n");
    }

    return 0;
}
