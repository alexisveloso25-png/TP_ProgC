#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Prototypes des fonctions externes
void exercice_4_3();
int factorielle(int n);
void exercice_4_6(char *f);

int main() {
    int choix;
    while (1) {
        printf("\n\x1B[36m╔════════════════════════════════════════════╗\n");
        printf("║                  MENU     TP4          ║\n");
        printf("╚════════════════════════════════════════════╝\x1B[0m\n");
        printf("1. Calculatrice (Somme, Produit, etc.)\n");
        printf("2. Gestion de Fichier (Lire/Ecrire)\n");
        printf("3. Base de donnees Etudiants (5 personnes)\n");
        printf("5. Calcul de Factorielle (Recursif)\n");
        printf("7. Liste Chainee de Couleurs\n");
        printf("0. Quitter le programme\n");
        printf("\n\x1B[33mEntrez le numero de l'exercice a tester : \x1B[0m");
        
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) { printf("Fin du programme.\n"); break; }

        switch (choix) {
            case 1: {
                int a, b; char op;
                printf("\n--- CALCULETTE ---\n");
                printf("Tapez le premier nombre entier : "); scanf("%d", &a);
                printf("Tapez le deuxieme nombre entier : "); scanf("%d", &b);
                printf("Choisissez un symbole (+, -, *, /, %%, &, |) : "); scanf(" %c", &op);
                printf("\x1B[32mResultat : ");
                if (op == '+') printf("%d + %d = %d", a, b, somme(a, b));
                else if (op == '-') printf("%d - %d = %d", a, b, difference(a, b));
                else if (op == '*') printf("%d * %d = %d", a, b, produit(a, b));
                else if (op == '/') printf("%d / %d = %d", a, b, quotient(a, b));
                else if (op == '%') printf("%d %% %d = %d", a, b, modulo(a, b));
                else if (op == '&') printf("%d & %d = %d", a, b, et_bit(a, b));
                else if (op == '|') printf("%d | %d = %d", a, b, ou_bit(a, b));
                printf("\x1B[0m\n");
                break;
            }
            case 2: {
                int mode; char nom[50], msg[100];
                printf("\n--- FICHIERS ---\n");
                printf("Voulez-vous (1) Lire ou (2) Ecrire dans un fichier ? Choix : "); scanf("%d", &mode);
                printf("Entrez le nom du fichier (exemple: test.txt) : "); scanf("%s", nom);
                if (mode == 1) {
                    printf("\nContenu du fichier %s :\n", nom);
                    lire_fichier(nom);
                } else {
                    printf("Tapez le message a ajouter au fichier : ");
                    getchar(); // Nettoyer buffer
                    fgets(msg, 100, stdin);
                    ecrire_dans_fichier(nom, msg);
                    printf("\x1B[32mMessage ajoute avec succes.\x1B[0m\n");
                }
                break;
            }
            case 3:
                exercice_4_3();
                break;
            case 5: {
                int n;
                printf("\n--- FACTORIELLE ---\n");
                printf("Tapez le nombre entier pour calculer sa factorielle : "); scanf("%d", &n);
                if (n < 0) printf("\x1B[31mErreur : Pas de factorielle pour les nombres negatifs.\x1B[0m\n");
                else printf("\x1B[32mLe resultat de %d! est : %d\x1B[0m\n", n, factorielle(n));
                break;
            }
            case 7: {
                struct liste_couleurs l;
                init_liste(&l);
                printf("\n--- LISTE DE COULEURS ---\n");
                printf("Generation automatique de 10 couleurs dans la liste...\n");
                for (int i = 0; i < 10; i++) {
                    struct couleur c = {(i*25), (255-i*20), (i*10), 255};
                    insertion(&c, &l);
                }
                printf("\x1B[32mParcours de la liste creee :\x1B[0m\n");
                parcours(&l);
                break;
            }
            default:
                printf("\x1B[31mNumero invalide, essayez encore.\x1B[0m\n");
        }
        printf("\nAppuyez sur une touche pour revenir au menu principal...");
        getchar(); getchar();
    }
    return 0;
}

// Fonctions manquantes pour la compilation
int factorielle(int n) { return (n <= 1) ? 1 : n * factorielle(n - 1); }
void exercice_4_6(char *f) { printf("Fonction de recherche dans %s\n", f); }
