#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include "repertoire.h"

// --- VERIFICATION EXERCICE 5.1 ---
void lire_dossier(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire); // Tente d'ouvrir le dossier

    if (dossier == NULL) {
        printf("\x1B[31m[ERREUR 5.1]\x1B[0m Impossible d'ouvrir : %s\n", nom_repertoire);
        return;
    }

    printf("\n--- Contenu de '%s' (Exo 5.1) ---\n", nom_repertoire);
    // On parcourt les entrées
    while ((entree = readdir(dossier)) != NULL) {
        printf("  - %s\n", entree->d_name);
    }

    closedir(dossier);
}

// --- VERIFICATION EXERCICE 5.2 ---
void lire_dossier_recursif(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire); //
    char chemin_complet[1024];

    if (dossier == NULL) return;

    while ((entree = readdir(dossier)) != NULL) {
        // Condition pour éviter la boucle infinie sur . et ..
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }

        // Affichage du chemin actuel
        printf("\x1B[32m[RECURSIF]\x1B[0m %s/%s\n", nom_repertoire, entree->d_name);

        // Si c'est un dossier, on relance la fonction (Récursion)
        if (entree->d_type == DT_DIR) {
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", nom_repertoire, entree->d_name);
            lire_dossier_recursif(chemin_complet);
        }
    }
    closedir(dossier);
}
