#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    // ./calcule <op> <n1> <n2>
    if (argc < 3) {
        printf("Usage: %s <op> <n1> [n2]\n", argv[0]);
        return 1;
    }

    char op = argv[1][0];
    int n1 = atoi(argv[2]);
    int res;

    if (op == '~') {
        res = negation_bit(n1);
    } else {
        if (argc < 4) { printf("Erreur : Deuxieme nombre requis.\n"); return 1; }
        int n2 = atoi(argv[3]);
        switch (op) {
            case '+': res = somme(n1, n2); break;
            case '-': res = difference(n1, n2); break;
            case '*': res = produit(n1, n2); break;
            case '/': res = quotient(n1, n2); break;
            case '%': res = modulo(n1, n2); break;
            case '&': res = et_bit(n1, n2); break;
            case '|': res = ou_bit(n1, n2); break;
            default: printf("Operateur inconnu.\n"); return 1;
        }
    }

    printf("Resultat : %d\n", res);
    return 0;
}
