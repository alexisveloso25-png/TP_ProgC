#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom_de_fichier) {
    FILE *f = fopen(nom_de_fichier, "r");
    if (f == NULL) {
        printf("Erreur : Impossible d'ouvrir %s\n", nom_de_fichier);
        return;
    }
    char c;
    printf("Contenu de %s :\n", nom_de_fichier);
    while ((c = fgetc(f)) != EOF) putchar(c);
    printf("\n");
    fclose(f);
}

void ecrire_dans_fichier(char *nom_de_fichier, char *message) {
    FILE *f = fopen(nom_de_fichier, "w");
    if (f != NULL) {
        fprintf(f, "%s", message);
        fclose(f);
        printf("Message enregistre dans %s\n", nom_de_fichier);
    }
}
