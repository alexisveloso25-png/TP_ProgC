#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *l) {
    l->premier = NULL;
}

void insertion(struct couleur *c, struct liste_couleurs *l) {
    struct noeud *nouveau = malloc(sizeof(struct noeud));
    nouveau->data = *c;
    nouveau->suivant = l->premier;
    l->premier = nouveau;
}

void parcours(struct liste_couleurs *l) {
    struct noeud *actuel = l->premier;
    while (actuel) {
        printf("RGB(%d,%d,%d)\n", actuel->data.r, actuel->data.g, actuel->data.b);
        actuel = actuel->suivant;
    }
}

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    struct couleur rouge = {255, 0, 0, 255};
    insertion(&rouge, &ma_liste);
    printf("\n--- LISTE DES COULEURS (4.7) ---\n");
    parcours(&ma_liste);
}
