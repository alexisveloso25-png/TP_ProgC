#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

void exercice_4_1() {
    int n1, n2, res;
    char op;
    
    printf("\n--- Exercice 4.1 : Calcul avec operateurs ---\n");
    
    // 1. Affiche le message PUIS attend le premier nombre
    printf("Entrez num1 : ");
    fflush(stdout); 
    scanf("%d", &n1);
    
    // 2. Affiche le message PUIS attend le deuxieme nombre
    printf("Entrez num2 : ");
    fflush(stdout);
    scanf("%d", &n2);
    
    // 3. Affiche le message PUIS attend le symbole
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    fflush(stdout);
    scanf(" %c", &op); // L'espace avant %c est OBLIGATOIRE

    switch (op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_bit(n1, n2); break;
        case '|': res = ou_bit(n1, n2); break;
        case '~': res = negation_bit(n1); break;
        default: printf("Erreur : symbole invalide.\n"); return;
    }

    // Affiche enfin le résultat sur une nouvelle ligne
    printf("Resultat : %d\n", res);
}

int main() {
    int choix;
    // Ici aussi, on affiche d'abord la question
    printf("Quel exercice souhaitez-vous resoudre ?\n");
    printf("1. Exercice 4.1 (Calculatrice)\n");
    printf("Votre choix : ");
    fflush(stdout);

    if (scanf("%d", &choix) == 1 && choix == 1) {
        exercice_4_1();
    } else {
        printf("Exercice non implemente.\n");
    }
    return 0;
}
