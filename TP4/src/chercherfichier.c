#include <stdio.h>
#include <string.h>

void exercice_4_6(char *nom_f) {
    FILE *f = fopen(nom_f, "r");
    if (!f) {
        printf("\x1B[31m[Erreur] : Impossible d'ouvrir le fichier '%s'. Verifiez qu'il existe.\x1B[0m\n", nom_f);
        return;
    }
    
    char mot[50], ligne[256];
    printf("\n--- RECHERCHE DE MOT DANS %s ---\n", nom_f);
    printf("Tapez le mot exact a rechercher : ");
    fflush(stdout);
    scanf("%s", mot);
    
    int num_ligne = 1;
    int trouve = 0;
    
    while (fgets(ligne, sizeof(ligne), f)) {
        // strstr cherche le mot dans la ligne
        if (strstr(ligne, mot)) {
            printf("\x1B[32m[Trouve]\x1B[0m Ligne %d : %s", num_ligne, ligne);
            trouve = 1;
        }
        num_ligne++;
    }
    
    if (!trouve) {
        printf("\x1B[33mLe mot '%s' n'a pas ete trouve dans le fichier.\x1B[0m\n", mot);
    }
    
    fclose(f);
}
