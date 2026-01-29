#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// --- PROTOTYPES (Déclarations uniquement) ---
// On indique au compilateur que ces fonctions existent dans d'autres fichiers
void exercice_4_1();
void exercice_4_2();
void exercice_4_3(); // Implémentée dans etudiant_bd.c
int factorielle(int n); // Implémentée dans factorielle.c
void exercice_4_6(char *nom); // Implémentée dans chercherfichier.c
void exercice_4_7(); // Implémentée dans liste.c

void afficher_titre(char *texte) {
    printf("\n\x1B[36m>>> %s <<<\x1B[0m\n", texte);
    printf("------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    // Mode recherche directe (Exo 4.6)
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        printf("\n\x1B[33m==============================================\n");
        printf("       TP4 PROGC - MENU PRINCIPAL\n");
        printf("==============================================\x1B[0m\n");
        printf("1. Calculatrice Interactive (4.1)\n");
        printf("2. Gestion Fichiers Simple (4.2)\n");
        printf("3. Base Etudiants (4.3)\n");
        printf("5. Factorielle Recursive (4.5)\n");
        printf("6. Recherche dans un Fichier (4.6)\n");
        printf("7. Liste Couleurs RGB (4.7)\n");
        printf("0. Quitter\n");
        printf("\nChoix : "); fflush(stdout);

        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break; // Plus de conflit ici
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
            default: printf("Choix invalide.\n");
        }
        printf("\nAppuyez sur Entree pour continuer...");
        getchar(); getchar();
    }
    return 0;
}
