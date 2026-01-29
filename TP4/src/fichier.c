#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    printf("\n--- GENERATION DE 10 COULEURS (EXO 4.7) ---\n");
    for (int i = 0; i < 10; i++) {
        struct couleur c = {(unsigned char)(i*25), (unsigned char)(255-i*15), (unsigned char)(i*10), 0xFF};
        insertion(&c, &ma_liste);
    }
    parcours(&ma_liste);
}
