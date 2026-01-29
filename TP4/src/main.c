#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes (On prévient le main que les fonctions sont ailleurs)
void exercice_4_1();
void exercice_4_2();
void exercice_4_3(); // Pas de code ici, juste le nom !
int factorielle(int n);
void exercice_4_6(char *nom);
void exercice_4_7();

int main(int argc, char *argv[]) {
    if (argc == 2) { exercice_4_6(argv[1]); return 0; }

    int choix;
    while (1) {
        printf("\n--- MENU TP4 (Alexis, Salmane, Kais, Mohamed) ---\n");
        printf("1. Calculatrice | 2. Fichiers | 3. Base Etudiants\n");
        printf("5. Factorielle  | 6. Recherche | 7. Liste Couleurs | 0. Quitter\n");
        printf("Choix : "); fflush(stdout);

        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break; // Appelle la fonction de etudiant_bd.c
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
        printf("\nAppuyez sur Entree pour continuer...");
        getchar(); getchar();
    }
    return 0;
}

// --- Garde ici SEULEMENT exercice_4_1 et exercice_4_2 si elles ne sont pas dans d'autres fichiers ---
void exercice_4_1() {
    // Ton code pour la calculatrice interactive...
}

void exercice_4_2() {
    // Ton code pour lire/écrire un fichier...
}
