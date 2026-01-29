#include <stdio.h>
#include "fichier.h"
void lire_fichier(char *nom) {
    FILE *f = fopen(nom, "r");
    if (!f) { printf("\x1B[31mErreur: Impossible d'ouvrir le fichier '%s'\x1B[0m\n", nom); return; }
    char c;
    while ((c = fgetc(f)) != EOF) putchar(c);
    fclose(f);
}
void ecrire_dans_fichier(char *nom, char *msg) {
    FILE *f = fopen(nom, "a");
    if (f) { fprintf(f, "%s", msg); fclose(f); }
}
