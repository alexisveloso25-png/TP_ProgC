#include <stdio.h>
#include <stdlib.h>
#include "operator.h"

int main(int argc, char *argv[]) {
    // argc est le nombre d'arguments. On attend : ./calcule <op> <n1> <n2>
    // Donc argc doit etre egal a 4 (le nom du programme + 3 arguments)
    if (argc < 2) {
        printf("Usage: %s <operateur> <num1> <num2>\n", argv[0]);
        return 1;
    }

    // Le premier argument apres le nom est l'operateur
    char op = argv[1][0];
    int n1, n2, res;

    // Pour la negation (~), il n'y a qu'un seul nombre
    if (op == '~') {
        if (argc != 3) {
            printf("Usage pour ~ : %s ~ <num1>\n", argv[0]);
            return 1;
        }
        n1 = atoi(argv[2]); // atoi convertit une chaine "10" en entier 10
        res = negation_bit(n1);
        printf("Resultat : %d\n", res);
        return 0;
    }

    // Pour les autres operations, il faut 2 nombres
    if (argc != 4) {
        printf("Usage: %s <operateur> <num1> <num2>\n", argv[0]);
        return 1;
    }

    n1 = atoi(argv[2]);
    n2 = atoi(argv[3]);

    switch (op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_bit(n1, n2); break;
        case '|': res = ou_bit(n1, n2); break;
        default:
            printf("Erreur : Operateur '%c' inconnu.\n", op);
            return 1;
    }

    printf("Resultat : %d\n", res);
    return 0;
}
