#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

// --- Entrée pour l'exercice 4.1 ---
void exercice_4_1() {
    int n1, n2, res;
    char op;
    printf("\n--- Exercice 4.1 : Calcul avec opérateurs ---\n");
    printf("Entrez num1 : ");
    scanf("%d", &n1);
    printf("Entrez num2 : ");
    scanf("%d", &n2);
    printf("Entrez l'operateur (+, -, *, /, %%, &, |, ~) : ");
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
        default: printf("Operateur invalide.\n"); return;
    }
    printf("Resultat : %d\n", res);
}

// --- Placeholders pour les exercices futurs ---
void exercice_4_2() { printf("\nExercice 4.2 non encore implemente.\n"); }
void exercice_4_7() { printf("\nExercice 4.7 non encore implemente.\n"); }

int main() {
    int choix;

    printf("Quel exercice souhaitez-vous resoudre ?\n");
    printf("1. Exercice 4.1 (Calculatrice)\n");
    printf("2. Exercice 4.2\n");
    printf("3. Exercice 4.7\n");
    printf("Votre choix : ");
    scanf("%d", &choix);

    switch (choix) {
        case 1: exercice_4_1(); break;
        case 2: exercice_4_2(); break;
        case 3: exercice_4_7(); break;
        default: printf("Choix indisponible.\n"); break;
    }

    return 0;
}
