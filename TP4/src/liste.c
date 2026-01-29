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
    int rang = 1;
    while (act) {
        printf("Couleur n°%d -> R:%d G:%d B:%d A:%d\n", rang++, act->data.r, act->data.g, act->data.b, act->data.a);
        act = act->suivant;
    }
}
