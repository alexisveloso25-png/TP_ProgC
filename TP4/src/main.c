#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// --- PROTOTYPES ---
// On déclare les fonctions ici pour que le main puisse les appeler
void exercice_4_1();           // Dans operator.c (ou fichier dédié)
void exercice_4_2();           // Dans fichier.c
void exercice_4_3();           // Dans etudiant_bd.c
int factorielle(int n);        // Dans factorielle.c
void exercice_4_6(char *nom);  // Dans chercherfichier.c
void exercice_4_7();           // Dans liste.c

int main(int argc, char *argv[]) {
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        printf("\n\x1B[36m==============================================\n");
        printf("   MENU TP4 - GROUPE MASTER (Visuel Corrigé)\n");
        printf("==============================================\x1B[0m\n");
        printf("1. Calculatrice Interactive\n");
        printf("2. Gestion Fichiers Simple\n");
        printf("3. Base Donnees Etudiants\n");
        printf("5. Factorielle Recursive\n");
        printf("6. Recherche dans un Fichier\n");
        printf("7. Liste Couleurs RGB\n");
        printf("0. Quitter\n");
        printf("\n\x1B[33m> Choix : \x1B[0m"); fflush(stdout);

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
            default: printf("Choix invalide.\n");
        }
        printf("\nAppuyez sur Entree pour continuer...");
        getchar(); getchar(); 
    }
    return 0;
}
