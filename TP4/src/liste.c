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
    if (!actuel) printf("Liste vide.\n");
    while (actuel) {
        printf("RGB: (%d, %d, %d, %d)\n", 
                actuel->data.r, actuel->data.g, actuel->data.b, actuel->data.a);
        actuel = actuel->suivant;
    }
}
