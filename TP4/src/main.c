#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

void exercice_4_1() {
    int n1, n2, res;
    char op;
    
    printf("\n--- Exercice 4.1 : Calcul avec operateurs ---\n");
    
    // Affichage AVANT la saisie pour guider Alexis, Salmane, Kais et Mohamed
    printf("Entrez num1 : ");
    fflush(stdout); 
    scanf("%d", &n1);
    
    printf("Entrez num2 : ");
    fflush(stdout);
    scanf("%d", &n2);
    
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    fflush(stdout);
    scanf(" %c", &op); // L'espace avant %c est vital pour eviter de sauter l'entree

    switch (op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_bit(n1, n2); break;
        case '|': res = ou_bit(n1, n2); break;
        case '~': res = negation_bit(n1); break;
        default: printf("Erreur : Operateur non reconnu.\n"); return;
    }

    printf("Resultat : %d\n", res);
}

int main() {
    int choix;
    printf("Choisissez l'exercice (1 pour la calculatrice) : ");
    scanf("%d", &choix);

    if (choix == 1) {
        exercice_4_1();
    } else {
        printf("Exercice non implemente.\n");
    }

    return 0;
}
