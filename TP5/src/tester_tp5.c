#include <stdio.h>
#include "repertoire.h"

int main(int argc, char *argv[]) {
    // Vérification que l'utilisateur a donné un dossier en argument
    if (argc < 2) {
        printf("\x1B[31mUsage: %s <nom_du_repertoire>\x1B[0m\n", argv[0]);
        printf("Exemple: %s .\n", argv[0]);
        return 1;
    }

    char *cible = argv[1];

    printf("\n\x1B[36m=== TEST EXERCICE 5.1 (LISTE SIMPLE) ===\x1B[0m\n");
    lire_dossier(cible);

    printf("\n\x1B[36m=== TEST EXERCICE 5.2 (LISTE RECURSIVE) ===\x1B[0m\n");
    lire_dossier_recursif(cible);

    return 0;
}
