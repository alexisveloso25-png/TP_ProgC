#include <stdio.h>
#include "liste.h"

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    printf("\n--- LISTE COULEURS 4.7 ---\n");
    // Exemple d'insertion
    struct couleur rouge = {255, 0, 0, 255};
    insertion(&rouge, &ma_liste);
    parcours(&ma_liste);
}
