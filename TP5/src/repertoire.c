#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h> // Fournit les types DIR et struct dirent
#include "repertoire.h"

// --- IMPLÉMENTATION EXERCICE 5.1 (LISTE SIMPLE) ---
void lire_dossier(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire); // Tente d'ouvrir le répertoire

    // Gestion d'erreur si le répertoire est invalide ou inaccessible
    if (dossier == NULL) {
        printf("\x1B[31m[Erreur 5.1]\x1B[0m Impossible d'ouvrir le repertoire : %s\n", nom_repertoire);
        return;
    }

    printf("\n--- Contenu simple de : %s ---\n", nom_repertoire);
    
    // Boucle de lecture : readdir renvoie NULL quand il n'y a plus rien à lire
    while ((entree = readdir(dossier)) != NULL) {
        // Affiche le nom de l'entrée actuelle
        printf("  [Item] %s\n", entree->d_name);
    }

    closedir(dossier); // Fermeture du flux répertoire
}

// --- IMPLÉMENTATION EXERCICE 5.2 (LISTE RÉCURSIVE) ---
void lire_dossier_recursif(char *nom_repertoire) {
    struct dirent *entree;
    DIR *dossier = opendir(nom_repertoire); // Ouverture pour chaque niveau de récursion
    char chemin_complet[1024];

    if (dossier == NULL) {
        return; // Sécurité pour les dossiers protégés ou inexistants
    }

    while ((entree = readdir(dossier)) != NULL) {
        // PROTECTION CONTRE LES BOUCLES INFINIES :
        // On ignore impérativement "." (soi-même) et ".." (parent)
        if (strcmp(entree->d_name, ".") == 0 || strcmp(entree->d_name, "..") == 0) {
            continue;
        }

        // Affichage de l'élément avec son chemin pour plus de clarté
        printf("\x1B[32m[Recurse]\x1B[0m %s/%s\n", nom_repertoire, entree->d_name);

        // Vérification du type : si c'est un répertoire (DT_DIR), on descend
        if (entree->d_type == DT_DIR) {
            // Construction du nouveau chemin pour l'appel suivant
            snprintf(chemin_complet, sizeof(chemin_complet), "%s/%s", nom_repertoire, entree->d_name);
            
            // Appel récursif pour explorer ce sous-dossier
            lire_dossier_recursif(chemin_complet);
        }
    }

    closedir(dossier);
}
