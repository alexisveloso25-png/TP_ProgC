#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes des fonctions definies dans les autres fichiers .c
void exercice_4_3();
int factorielle(int n);
void exercice_4_6(char *f);
void exercice_4_7();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        printf("\n=== MENU TP4 ===\n1. Calculatrice\n2. Fichiers\n3. Etudiants\n5. Factorielle\n7. Liste Couleurs\n0. Quitter\nChoix : ");
        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: {
                int a, b; char op;
                printf("Entrez num1 op num2 (ex: 10 + 5) : ");
                scanf("%d %c %d", &a, &op, &b);
                if (op == '+') printf("Resultat : %d\n", somme(a, b));
                else if (op == '*') printf("Resultat : %d\n", produit(a, b));
                break;
            }
            case 2:
                lire_fichier("test.txt");
                break;
            case 3:
                exercice_4_3();
                break;
            case 5: {
                int n; printf("Nombre : "); scanf("%d", &n);
                printf("Fact(%d) = %d\n", n, factorielle(n));
                break;
            }
            case 7:
                exercice_4_7();
                break;
        }
    }
    return 0;
}
