#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Déclarations pour éviter les erreurs "undefined reference"
void exercice_4_3();
int factorielle(int n);
void exercice_4_6(char *f);

int main(int argc, char *argv[]) {
    int choix;

    while (1) {
        printf("\n\x1B[36m╔════════════════════════════════════════════╗\n");
        printf("║       MENU INTERACTIF - TP4 EXPERT         ║\n");
        printf("╚════════════════════════════════════════════╝\x1B[0m\n");
        printf("1. Calculatrice (Somme, Produit, Bits...)\n");
        printf("2. Gestion de Fichier (Lire ou Écrire)\n");
        printf("3. Base de données Étudiants (Saisie de 5)\n");
        printf("5. Calcul de Factorielle (Récursif)\n");
        printf("7. Liste Chaînée de Couleurs\n");
        printf("0. Quitter le programme\n");
        
        printf("\n\x1B[33mEntrez le numéro de l'exercice à tester : \x1B[0m");
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: {
                int n1, n2;
                char op;
                printf("\n--- MODE CALCULATRICE ---\n");
                printf("Entrez le PREMIER numéro : "); 
                scanf("%d", &n1);
                printf("Entrez le DEUXIÈME numéro : "); 
                scanf("%d", &n2);
                printf("Choisissez un SYMBOLE (+, -, *, /, %%, &, |) : "); 
                scanf(" %c", &op);

                printf("\n\x1B[32m[RÉSULTAT] : ");
                if (op == '+') printf("%d + %d = %d", n1, n2, somme(n1, n2));
                else if (op == '-') printf("%d - %d = %d", n1, n2, difference(n1, n2));
                else if (op == '*') printf("%d * %d = %d", n1, n2, produit(n1, n2));
                else if (op == '/') printf("%d / %d = %d", n1, n2, quotient(n1, n2));
                else if (op == '%') printf("%d %% %d = %d", n1, n2, modulo(n1, n2));
                else if (op == '&') printf("%d & %d = %d", n1, n2, et_bit(n1, n2));
                else if (op == '|') printf("%d | %d = %d", n1, n2, ou_bit(n1, n2));
                else printf("Symbole non valide !");
                printf("\x1B[0m\n");
                break;
            }

            case 2: {
                int mode;
                char nomFichier[50], texte[100];
                printf("\n--- GESTION DE FICHIER ---\n");
                printf("1. LIRE un fichier\n2. ÉCRIRE dans un fichier\nVotre choix : ");
                scanf("%d", &mode);
                printf("Entrez le NOM du fichier (ex: test.txt) : ");
                scanf("%s", nomFichier);

                if (mode == 1) {
                    printf("\nAffichage du contenu :\n");
                    lire_fichier(nomFichier);
                } else {
                    printf("Tapez la PHRASE à ajouter : ");
                    getchar(); // Pour vider le buffer
                    fgets(texte, 100, stdin);
                    ecrire_dans_fichier(nomFichier, texte);
                    printf("\x1B[32mPhrase enregistrée !\x1B[0m\n");
                }
                break;
            }

            case 3:
                exercice_4_3(); // Appelle la saisie des 5 étudiants
                break;

            case 5: {
                int n;
                printf("\n--- FACTORIELLE ---\n");
                printf("Entrez le nombre à calculer : ");
                scanf("%d", &n);
                if (n < 0) printf("Erreur : Entrez un nombre positif.\n");
                else printf("\x1B[32mRésultat : %d! = %d\x1B[0m\n", n, factorielle(n));
                break;
            }

            case 7: {
                struct liste_couleurs l;
                init_liste(&l);
                printf("\n--- LISTE CHAÎNÉE ---\n");
                printf("Génération de 10 couleurs test...\n");
                for (int i = 0; i < 10; i++) {
                    struct couleur c = {(i*20), (i*10), (255-i*10), 255};
                    insertion(&c, &l);
                }
                parcours(&l);
                break;
            }

            default:
                printf("\x1B[31mOption invalide !\x1B[0m\n");
        }
        printf("\n\x1B[30;1mAppuyez sur ENTRÉE pour continuer...\x1B[0m");
        getchar(); getchar(); 
    }
    return 0;
}
