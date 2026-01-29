#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *l) {
    l->premier = NULL;
}

void insertion(struct couleur *c, struct liste_couleurs *l) {
    struct noeud *nouveau = malloc(sizeof(struct noeud));
    if (nouveau == NULL) return;

    nouveau->data = *c;
    nouveau->suivant = l->premier; // On insère au début
    l->premier = nouveau;
}

void parcours(struct liste_couleurs *l) {
    struct noeud *actuel = l->premier;
    int i = 1;
    while (actuel != NULL) {
        printf("Couleur %d : R=0x%02X, G=0x%02X, B=0x%02X, A=0x%02X\n", 
                i++, actuel->data.r, actuel->data.g, actuel->data.b, actuel->data.a);
        actuel = actuel->suivant;
    }
}
