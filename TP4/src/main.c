#include <stdio.h>
#include "operator.h"

int main() {
    int n1, n2, resultat;
    char op;

    printf("--- Calculatrice de Groupe ---\n");
    printf("Entrez num1 : ");
    scanf("%d", &n1);
    printf("Entrez num2 : ");
    scanf("%d", &n2);
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
    scanf(" %c", &op); // L'espace avant %c est crucial pour ignorer l'Entrée précédente

    switch (op) {
        case '+': resultat = somme(n1, n2); break;
        case '-': resultat = difference(n1, n2); break;
        case '*': resultat = produit(n1, n2); break;
        case '/': resultat = quotient(n1, n2); break;
        case '%': resultat = modulo(n1, n2); break;
        case '&': resultat = et_bit(n1, n2); break;
        case '|': resultat = ou_bit(n1, n2); break;
        case '~': 
            resultat = negation_bit(n1); 
            printf("Note : La negation (~) s'applique uniquement sur num1 (%d).\n", n1);
            break;
        default:
            printf("Operateur inconnu !\n");
            return 1;
    }

    printf("Resultat : %d\n", resultat);

    return 0;
}
