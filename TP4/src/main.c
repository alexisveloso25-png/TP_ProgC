#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"

void exercice_4_1() {
    int n1, n2, res;
    char op;
    printf("\n--- Calcul avec operateurs ---\n");
    printf("Entrez num1 : "); fflush(stdout); scanf("%d", &n1);
    printf("Entrez num2 : "); fflush(stdout); scanf("%d", &n2);
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : "); fflush(stdout);
    scanf(" %c", &op);

    switch (op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_bit(n1, n2); break;
        case '|': res = ou_bit(n1, n2); break;
        case '~': res = negation_bit(n1); break;
        default: printf("Erreur operateur\n"); return;
    }
    printf("Resultat : %d\n", res);
}

void exercice_4_2() {
    int choix;
    char nom[50], msg[100];
    printf("\n1. Lire\n2. Ecrire\nVotre choix : "); fflush(stdout);
    scanf("%d", &choix);
    if (choix == 1) {
        printf("Nom du fichier : "); fflush(stdout); scanf("%s", nom);
        lire_fichier(nom);
    } else {
        printf("Nom du fichier : "); fflush(stdout); scanf("%s", nom);
        printf("Message : "); fflush(stdout); getchar(); fgets(msg, 100, stdin);
        ecrire_dans_fichier(nom, msg);
    }
}

int main() {
    int choix;
    printf("Choisir exercice (1: Calcul, 2: Fichier) : "); fflush(stdout);
    scanf("%d", &choix);
    if (choix == 1) exercice_4_1();
    else if (choix == 2) exercice_4_2();
    return 0;
}
