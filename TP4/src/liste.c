#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *l) { l->premier = NULL; }
void insertion(struct couleur *c, struct liste_couleurs *l) {
    struct noeud *n = malloc(sizeof(struct noeud));
    n->data = *c; n->suivant = l->premier; l->premier = n;
}
void parcours(struct liste_couleurs *l) {
    struct noeud *act = l->premier;
    int i = 1;
    while (act) {
        printf(" \x1B[36m●\x1B[0m Couleur %02d | \x1B[31mR:%3d\x1B[0m \x1B[32mG:%3d\x1B[0m \x1B[34mB:%3d\x1B[0m\n", 
                i++, act->data.r, act->data.g, act->data.b);
        act = act->suivant;
    }
}
