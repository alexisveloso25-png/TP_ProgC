#include <stdio.h>

int main() {
    int num1 = 10;
    int num2 = 3;
    char op = '&'; // Changez ce caractère pour tester d'autres opérations

    printf("Opération demandée : %d %c %d\n", num1, op, num2);

    switch (op) {
        // --- Opérateurs Arithmétiques ---
        case '+':
            printf("Résultat : %d\n", num1 + num2);
            break;
        case '-':
            printf("Résultat : %d\n", num1 - num2);
            break;
        case '*':
            printf("Résultat : %d\n", num1 * num2);
            break;
        case '/':
            if (num2 != 0)
                printf("Résultat : %d\n", num1 / num2);
            else
                printf("Erreur : Division par zéro !\n");
            break;
        case '%':
            if (num2 != 0)
                printf("Résultat : %d\n", num1 % num2);
            else
                printf("Erreur : Modulo par zéro !\n");
            break;

        // --- Opérateurs de Bits (Bitwise) ---
        case '&':
            printf("Résultat (ET bit à bit) : %d\n", num1 & num2);
            break;
        case '|':
            printf("Résultat (OU bit à bit) : %d\n", num1 | num2);
            break;
        case '~':
            // L'opérateur NOT est unitaire (il ne s'applique qu'à un seul nombre)
            printf("Résultat (NON bit à bit sur num1) : %d\n", ~num1);
            break;

        // Cas par défaut si l'opérateur n'est pas reconnu
        default:
            printf("Erreur : Opérateur '%c' non reconnu.\n", op);
            break;
    }

    return 0;
}
