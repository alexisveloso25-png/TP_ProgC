#include <stdio.h>
#include "operator.h"

// Fonctions de base
int somme(int a, int b) { return a + b; }
int difference(int a, int b) { return a - b; }
int produit(int a, int b) { return a * b; }
int quotient(int a, int b) { return (b != 0) ? a / b : 0; }

void exercice_4_1() {
    int n1, n2; char op;
    printf("\n--- CALCULATRICE 4.1 ---\nEntrez op (ex: 10 + 5) : ");
    scanf("%d %c %d", &n1, &op, &n2);
    if (op == '+') printf("Res : %d\n", somme(n1, n2));
    else if (op == '*') printf("Res : %d\n", produit(n1, n2));
    // Ajoute les autres cas ici...
}
