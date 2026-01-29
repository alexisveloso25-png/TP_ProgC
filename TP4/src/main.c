#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes des fonctions externes
void exercice_4_3();
int factorielle(int n);
void exercice_4_6(char *nom_f);

int main() {
    int choix;
    while (1) {
        printf("\n\x1B[36m╔════════════════════════════════════════════╗\n");
        printf("║          CONSOLES   DE  TP4 - COMPLET      ║\n");
        printf("╚════════════════════════════════════════════╝\x1B[0m\n");
        printf(" 1. Calculatrice Arithmetique\n 2. Lecture d'un Fichier texte\n 3. Saisie Base Etudiants\n 4. Sauvegarde des Etudiants\n 5. Calcul Factorielle (Recursif)\n 6. Recherche de mots (chercherfichier)\n 7. Liste de Couleurs (Chainee)\n 0. Quitter\n");
        
        printf("\n\x1B[33mEntrez le numero de l'exercice (0 a 7) : \x1B[0m");
        fflush(stdout);

        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: {
                int n1, n2; char op;
                printf("\n--- CALCULATRICE ---\n");
                printf("Entrez le numero 1 : "); fflush(stdout); scanf("%d", &n1);
                printf("Entrez le numero 2 : "); fflush(stdout); scanf("%d", &n2);
                printf("Entrez le symbole (+, -, *, /) : "); fflush(stdout); scanf(" %c", &op);
                printf("\x1B[32mResultat : %d %c %d = %d\x1B[0m\n", n1, op, n2, somme(n1, n2));
                break;
            }
            case 2: {
                char nf[50];
                printf("\nTapez le nom du fichier a lire (ex: test.txt) : "); fflush(stdout);
                scanf("%s", nf);
                lire_fichier(nf);
                break;
            }
            case 3:
            case 4:
                // L'exercice 3 (structure) et 4 (fichier) se font ensemble
                exercice_4_3();
                break;
            case 5: {
                int val;
                printf("\nTapez un nombre pour la factorielle : "); fflush(stdout);
                scanf("%d", &val);
                printf("\x1B[32mResultat : %d! = %d\x1B[0m\n", val, factorielle(val));
                break;
            }
            case 6: {
                char nf[50];
                printf("\nTapez le nom du fichier ou chercher : "); fflush(stdout);
                scanf("%s", nf);
                exercice_4_6(nf);
                break;
            }
            case 7: {
                struct liste_couleurs lc;
                init_liste(&lc);
                printf("\n--- GENERATION DE COULEURS ---\n");
                for(int i=0; i<3; i++) {
                    struct couleur c = {rand()%256, rand()%256, rand()%256, 255};
                    insertion(&c, &lc);
                }
                parcours(&lc);
                break;
            }
            default: printf("Choix invalide.\n");
        }
        printf("\nAppuyez sur une touche pour continuer...");
        fflush(stdout); getchar(); getchar();
    }
    return 0;
}
