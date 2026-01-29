#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes des fonctions définies dans d'autres fichiers .c
void exercice_4_1(); 
void exercice_4_2();
void exercice_4_3(); 
int factorielle(int n);
void exercice_4_6(char *nom);
void exercice_4_7();

int main(int argc, char *argv[]) {
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        printf("\n\x1B[36m=== MENU TP4 - GROUPE MASTER ===\x1B[0m\n");
        printf("1. Calculatrice | 2. Fichiers | 3. Etudiants\n");
        printf("5. Factorielle  | 6. Recherche | 7. Liste Couleurs | 0. Quitter\n");
        printf("Choix : "); fflush(stdout);

        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            case 5: {
                int n; printf("Nombre : "); scanf("%d", &n);
                if(n >= 0) printf("Resultat : %d\n", factorielle(n));
                break;
            }
            case 6: {
                char f[50]; printf("Fichier : "); scanf("%s", f);
                exercice_4_6(f); break;
            }
            case 7: exercice_4_7(); break;
        }
    }
    return 0;
}

// Implémentations locales simples
void exercice_4_1() {
    int a, b; printf("Somme de deux nombres : "); scanf("%d %d", &a, &b);
    printf("Resultat : %d\n", somme(a, b));
}

void exercice_4_2() {
    char nom[50]; printf("Lire quel fichier ? "); scanf("%s", nom);
    lire_fichier(nom);
}
