#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "repertoire.h"

// --- EXERCICE 5.1 : SIMPLE ---
void lire_dossier(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire);
    if (dossier == NULL) return;

    printf("\n--- 5.1 : Liste simple de %s ---\n", nom_repertoire);
    while ((entree = readdir(dossier)) != NULL) {
        printf("  %s\n", entree->d_name);
    }
    closedir(dossier);
}

// --- EXERCICE 5.2 : RÉCURSIF ---
void lire_dossier_recursif(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire);
    char chemin[1024];

    if (dossier == NULL) return;

    while ((entree = readdir(dossier)) != NULL) {
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) continue;

        printf("\x1B[32m[Rec]\x1B[0m %s/%s\n", nom_repertoire, entree->d_name);

        if (entree->d_type == DT_DIR) {
            snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
            lire_dossier_recursif(chemin);
        }
    }
    closedir(dossier);
}

// --- EXERCICE 5.3 : ITÉRATIF (AVEC PILE) ---
void lire_dossier_iteratif(char *nom_repertoire) {
    char pile[100][1024]; // Une pile pouvant stocker 100 chemins de dossiers
    int sommet = 0;

    // On commence par mettre le dossier de départ dans la pile
    strncpy(pile[sommet++], nom_repertoire, 1024);

    printf("\n--- 5.3 : Exploration Iterative ---\n");
    fflush(stdout);

    // Tant qu'il reste des dossiers à explorer dans la pile
    while (sommet > 0) {
        char dossier_actuel[1024];
        strncpy(dossier_actuel, pile[--sommet], 1024); // On récupère le dernier dossier ajouté

        DIR *d = opendir(dossier_actuel);
        if (d == NULL) continue;

        struct dirent *entree;
        while ((entree = readdir(d)) != NULL) {
            // Ignorer les dossiers spéciaux
            if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) continue;

            printf("\x1B[33m[Iter]\x1B[0m %s/%s\n", dossier_actuel, entree->d_name);

            // Si c'est un dossier, on l'ajoute à la pile pour le traiter plus tard
            if (entree->d_type == DT_DIR) {
                if (sommet < 100) {
                    snprintf(pile[sommet++], 1024, "%s/%s", dossier_actuel, entree->d_name);
                }
            }
        }
        closedir(d);
    }
}
