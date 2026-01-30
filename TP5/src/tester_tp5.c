#include <stdio.h>
#include "repertoire.h"

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Utilisation : %s <nom_du_repertoire>\n", argv[0]);
        return 1;
    }

    char *nom_repertoire = argv[1];

    printf("\n>>> Lancement de l'exercice 5.3 (Iteratif) <<<\n");
    lire_dossier_iteratif(nom_repertoire);

    return 0;
}
