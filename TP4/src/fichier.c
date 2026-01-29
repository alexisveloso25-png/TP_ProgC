#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir le fichier %s\n", nom_de_fichier);
        return;
    }
    printf("Contenu de %s :\n", nom_de_fichier);
    char c;
    while ((c = fgetc(f)) != EOF) {
        putchar(c);
    }
    printf("\n");
    fclose(f);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    FILE *f = fopen(nom_de_fichier, "a"); // 'a' pour ajouter sans ecraser
    if (f == NULL) {
        printf("Erreur d'ecriture.\n");
        return;
    }
    fprintf(f, "%s", message);
    fclose(f);
}
