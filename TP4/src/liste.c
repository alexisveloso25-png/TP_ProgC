#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

void init_liste(struct liste_couleurs *l) { l->premier = NULL; }

void insertion(struct couleur *c, struct liste_couleurs *l) {
    struct noeud *n = malloc(sizeof(struct noeud));
    n->data = *c;
    n->suivant = l->premier;
    l->premier = n;
}

void parcours(struct liste_couleurs *l) {
    struct noeud *a = l->premier;
    while (a) {
        printf("Couleur RGB: (%d, %d, %d)\n", a->data.r, a->data.g, a->data.b);
        a = a->suivant;
    }
}

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    for(int i=0; i<10; i++) {
        struct couleur c = {(unsigned char)(i*20), 0, (unsigned char)(255-i*20), 255};
        insertion(&c, &ma_liste);
    }
    parcours(&ma_liste);
}
