#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (!f) {
        printf("Erreur : Impossible d'ouvrir %s\n", nom_de_fichier);
        return;
    }
    char c;
    while ((c = fgetc(f)) != EOF) putchar(c);
    fclose(f);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    FILE *f = fopen(nom_de_fichier, "a");
    if (f) {
        fprintf(f, "%s", message);
        fclose(f);
    }
}
