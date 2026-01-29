#include "operator.h"
#include <stdio.h>

int somme(int num1, int num2) { return num1 + num2; }
int difference(int num1, int num2) { return num1 - num2; }
int produit(int num1, int num2) { return num1 * num2; }

int quotient(int num1, int num2) {
    if (num2 == 0) {
        printf("Erreur : Division par zéro ! ");
        return 0;
    }
    return num1 / num2;
}

int modulo(int num1, int num2) {
    return (num2 != 0) ? (num1 % num2) : 0;
}

int et_bit(int num1, int num2) { return num1 & num2; }
int ou_bit(int num1, int num2) { return num1 | num2; }
int negation_bit(int num1) { return ~num1; }
