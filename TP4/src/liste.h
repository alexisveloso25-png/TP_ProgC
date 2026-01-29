#ifndef LISTE_H
#define LISTE_H

struct couleur {
    unsigned char r, g, b, a;
};

struct noeud {
    struct couleur data;
    struct noeud *suivant;
};

struct liste_couleurs {
    struct noeud *premier;
};

void init_liste(struct liste_couleurs *l);
void insertion(struct couleur *c, struct liste_couleurs *l);
void parcours(struct liste_couleurs *l);

#endif
