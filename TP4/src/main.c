#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes
void exercice_4_3();
int factorielle(int n);
void exercice_4_6(char *f);

void header() {
    printf("\033[H\033[J"); // Clear screen
    printf("\x1B[36m╔══════════════════════════════════════════════════════╗\n");
    printf("║          CONSOLE MULTI-SERVICES TP4 EXPERT           ║\n");
    printf("╚══════════════════════════════════════════════════════╝\x1B[0m\n");
}

int main(int argc, char *argv[]) {
    if (argc == 2) { exercice_4_6(argv[1]); return 0; }

    int choix;
    while (1) {
        header();
        printf("\x1B[37m 1 \x1B[36m▶\x1B[0m Calculatrice Arithmétique\n");
        printf("\x1B[37m 2 \x1B[36m▶\x1B[0m Gestionnaire de Fichiers\n");
        printf("\x1B[37m 3 \x1B[36m▶\x1B[0m Base de Données Étudiants\n");
        printf("\x1B[37m 5 \x1B[36m▶\x1B[0m Calcul Factorielle Récursive\n");
        printf("\x1B[37m 7 \x1B[36m▶\x1B[0m Gestion Liste de Couleurs (RGB)\n");
        printf("\x1B[31m 0 \x1B[36m▶\x1B[31m Quitter le programme\x1B[0m\n");
        printf("\x1B[33m\nSélectionnez une option : \x1B[0m");
        
        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: {
                int a, b; char op;
                printf("Entrez l'opération (ex: 12 * 4) : "); scanf("%d %c %d", &a, &op, &b);
                int r = (op == '+') ? somme(a,b) : (op == '*') ? produit(a,b) : difference(a,b);
                printf("\x1B[32m✔ Résultat : %d\x1B[0m\n", r);
                break;
            }
            case 2: lire_fichier("test.txt"); break;
            case 3: exercice_4_3(); break;
            case 5: {
                int n; printf("Entrez un entier : "); scanf("%d", &n);
                printf("\x1B[32m✔ Résultat final : %d! = %d\x1B[0m\n", n, factorielle(n));
                break;
            }
            case 7: {
                struct liste_couleurs l; init_liste(&l);
                for(int i=0; i<10; i++) { 
                    struct couleur c = {rand()%256, rand()%256, rand()%256, 255}; 
                    insertion(&c, &l); 
                }
                parcours(&l); break;
            }
        }
        printf("\n\x1B[30;1mAppuyez sur Entrée pour continuer...\x1B[0m");
        getchar(); getchar();
    }
    return 0;
}
