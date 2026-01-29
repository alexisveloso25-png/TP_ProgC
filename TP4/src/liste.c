#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

// Affiche le contenu d'un fichier à l'écran
void lire_fichier(char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s.\n", nom_de_fichier);
        return;
    }

    printf("Contenu du fichier %s :\n", nom_de_fichier);
    char c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    printf("\n");
    fclose(f);
}

// Enregistre un message dans un fichier
void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    FILE *f = fopen(nom_de_fichier, "w"); // "w" pour écraser ou créer
    if (f == NULL) {
        printf("Erreur : Impossible de creer le fichier %s.\n", nom_de_fichier);
        return;
    }

    fprintf(f, "%s", message);
    fclose(f);
    printf("Le message a ete ecrit dans le fichier %s.\n", nom_de_fichier);
}
