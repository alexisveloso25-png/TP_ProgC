#include <stdio.h>
#include "fichier.h"

void lire_fichier(char *nom) {
    FILE *f = fopen(nom, "r");
    if (!f) { printf("\x1B[31m[!] Erreur: Fichier '%s' introuvable.\x1B[0m\n", nom); return; }
    char c;
    printf("\n\x1B[33m--- CONTENU DU FICHIER ---\x1B[0m\n");
    while ((c = fgetc(f)) != EOF) putchar(c);
    printf("\n\x1B[33m--------------------------\x1B[0m\n");
    fclose(f);
}

void ecrire_dans_fichier(char *nom, char *msg) {
    FILE *f = fopen(nom, "a");
    if (f) { fprintf(f, "%s", msg); fclose(f); }
}
