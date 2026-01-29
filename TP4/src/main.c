#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes pour le compilateur
void exercice_4_3();
int factorielle(int n);

void header() {
    printf("\033[H\033[J"); // Nettoie l'écran
    printf("\x1B[36m╔════════════════════════════════════════════╗\n");
    printf("║       MENU INTERACTIF - TP4 EXPERT         ║\n");
    printf("╚════════════════════════════════════════════╝\x1B[0m\n");
}

int main() {
    int choix;

    while (1) {
        header();
        printf("1. Calculatrice (Somme, Produit, Bits...)\n");
        printf("2. Gestion de Fichier (Lire ou Écrire)\n");
        printf("3. Base de données Étudiants (Saisie de 5)\n");
        printf("5. Calcul de Factorielle (Récursif)\n");
        printf("7. Liste Chaînée de Couleurs\n");
        printf("0. Quitter le programme\n");
        
        printf("\n\x1B[33mEntrez le numéro de l'exercice à tester : \x1B[0m");
        fflush(stdout); // FORCE L'AFFICHAGE
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: {
                int n1, n2;
                char op;
                printf("\n--- MODE CALCULATRICE ---\n");
                
                printf("Entrez le PREMIER numéro : "); 
                fflush(stdout);
                scanf("%d", &n1);
                
                printf("Entrez le DEUXIÈME numéro : "); 
                fflush(stdout);
                scanf("%d", &n2);
                
                printf("Choisissez un SYMBOLE (+, -, *, /, %%, &, |) : "); 
                fflush(stdout);
                scanf(" %c", &op);

                printf("\n\x1B[32m[RÉSULTAT] : ");
                if (op == '+') printf("%d + %d = %d", n1, n2, somme(n1, n2));
                else if (op == '-') printf("%d - %d = %d", n1, n2, difference(n1, n2));
                else if (op == '*') printf("%d * %d = %d", n1, n2, produit(n1, n2));
                else if (op == '/') printf("%d / %d = %d", n1, n2, (n2 != 0) ? n1/n2 : 0);
                else printf("Opération terminée.");
                printf("\x1B[0m\n");
                break;
            }

            case 2: {
                int mode;
                char nomFichier[50], texte[100];
                printf("\n--- GESTION DE FICHIER ---\n");
                printf("1. LIRE un fichier\n2. ÉCRIRE dans un fichier\nChoix : ");
                fflush(stdout);
                scanf("%d", &mode);
                printf("Nom du fichier : ");
                fflush(stdout);
                scanf("%s", nomFichier);

                if (mode == 1) {
                    lire_fichier(nomFichier);
                } else {
                    printf("Texte à ajouter : ");
                    fflush(stdout);
                    getchar(); // Vide le bouton Entrée
                    fgets(texte, 100, stdin);
                    ecrire_dans_fichier(nomFichier, texte);
                }
                break;
            }

            case 3: exercice_4_3(); break;
            case 5: {
                int n;
                printf("\nNombre pour factorielle : ");
                fflush(stdout);
                scanf("%d", &n);
                printf("Résultat : %d\n", factorielle(n));
                break;
            }
            case 7: {
                struct liste_couleurs l;
                init_liste(&l);
                for(int i=0; i<5; i++) {
                    struct couleur c = {rand()%255, rand()%255, rand()%255, 255};
                    insertion(&c, &l);
                }
                parcours(&l);
                break;
            }
        }
        printf("\n\x1B[30;1mAppuyez sur Entrée pour revenir au menu...\x1B[0m");
        fflush(stdout);
        getchar(); getchar(); 
    }
    return 0;
}
