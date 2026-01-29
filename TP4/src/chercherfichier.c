#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void exercice_4_6(char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nom_fichier);
        return;
    }

    char phrase[100];
    char ligne[1024];
    int num_ligne = 0;

    printf("Entrez la phrase que vous souhaitez rechercher : ");
    fflush(stdout);
    getchar(); // Nettoie le buffer du scanf précédent
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = 0; // Supprime le \n à la fin

    printf("\nResultats de la recherche :\n");

    while (fgets(ligne, sizeof(ligne), f)) {
        num_ligne++;
        int compteur = 0;
        char *ptr = ligne;

        // Recherche de toutes les occurrences de la phrase dans la ligne actuelle
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            compteur++;
            ptr += strlen(phrase); // Avance le pointeur pour trouver la suivante
        }

        if (compteur > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, compteur);
        }
    }

    fclose(f);
}
