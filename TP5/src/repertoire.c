#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "repertoire.h"

// --- Exercice 5.1 ---
void lire_dossier(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire);

    if (dossier == NULL) {
        printf("Erreur : Impossible d'ouvrir %s\n", nom_repertoire);
        return;
    }

    printf("\n\x1B[36m--- CONTENU SIMPLE DE %s ---\x1B[0m\n", nom_repertoire);
    while ((entree = readdir(dossier)) != NULL) {
        printf("  [+] %s\n", entree->d_name);
    }
    closedir(dossier);
}

// --- Exercice 5.2 ---
void lire_dossier_recursif(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire);
    char chemin[1024];

    if (dossier == NULL) return;

    while ((entree = readdir(dossier)) != NULL) {
        // On ignore . et .. pour éviter de boucler à l'infini
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }

        printf("\x1B[32m[Trouve]\x1B[0m %s/%s\n", nom_repertoire, entree->d_name);

        // Si c'est un dossier, on rentre dedans
        if (entree->d_type == DT_DIR) {
            snprintf(chemin, sizeof(chemin), "%s/%s", nom_repertoire, entree->d_name);
            lire_dossier_recursif(chemin);
        }
    }
    closedir(dossier);
}
