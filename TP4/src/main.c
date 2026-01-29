#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"
#include "liste.h"

// --- PROTOTYPES DES FONCTIONS EXTERNES ---
// Ces fonctions sont définies dans leurs fichiers .c respectifs
void exercice_4_1();           // Dans main.c (voir bas du fichier)
void exercice_4_2();           // Dans main.c (voir bas du fichier)
void exercice_4_3();           // DÉFINIE DANS etudiant_bd.c
int factorielle(int n);        // DÉFINIE DANS factorielle.c
void exercice_4_6(char *nom);  // DÉFINIE DANS chercherfichier.c
void exercice_4_7();           // DÉFINIE DANS liste.c

// --- FONCTIONS UTILITAIRES ---
void afficher_banniere(char *titre) {
    printf("\n\x1B[36m==============================================\n");
    printf("   %s\n", titre);
    printf("==============================================\x1B[0m\n");
}

int main(int argc, char *argv[]) {
    // Gestion de l'exercice 4.6 via argument de ligne de commande
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        afficher_banniere("MENU TP4 - GROUPE A (Alexis, Salmane, Kais, Mohamed)");
        printf(" 1. Calculatrice Interactive (4.1)\n");
        printf(" 2. Gestion Fichiers Simple (4.2)\n");
        printf(" 3. Base de Donnees Etudiants (4.3)\n");
        printf(" 4. Aide : Calculatrice Ligne de Commande (4.4)\n");
        printf(" 5. Factorielle Recursive (4.5)\n");
        printf(" 6. Recherche de phrase dans fichier (4.6)\n");
        printf(" 7. Liste de couleurs RGB (4.7)\n");
        printf(" 0. Quitter\n");
        printf("\n\x1B[33m> Votre choix : \x1B[0m");
        fflush(stdout);

        if (scanf("%d", &choix) != 1 || choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break; // Appelle la fonction dans etudiant_bd.c
            case 4: 
                printf("\n[INFO] Pour l'exo 4.4, compilez 'calcule.c' et lancez :\n");
                printf("Usage: ./calcule + 10 5\n");
                break;
            case 5: {
                int n; printf("Entrez un nombre : "); scanf("%d", &n);
                if(n >= 0) printf("Resultat de %d! : \x1B[32m%d\x1B[0m\n", n, factorielle(n));
                break;
            }
            case 6: {
                char nom[50]; printf("Nom du fichier source : "); scanf("%s", nom);
                exercice_4_6(nom);
                break;
            }
            case 7: exercice_4_7(); break;
            default: printf("\x1B[31mChoix invalide.\x1B[0m\n");
        }
        printf("\nAppuyez sur Entree pour revenir au menu...");
        getchar(); getchar(); 
    }

    printf("\nAu revoir !\n");
    return 0;
}

// --- IMPLÉMENTATIONS DES EXERCICES INTERACTIFS ---

void exercice_4_1() {
    int n1, n2, res; char op;
    printf("\n--- CALCULATRICE (4.1) ---\n");
    printf("Operation (ex: 10 + 5) : "); fflush(stdout);
    scanf("%d %c %d", &n1, &op, &n2);
    
    if (op == '+') res = somme(n1, n2); 
    else if (op == '-') res = difference(n1, n2);
    else if (op == '*') res = produit(n1, n2);
    else if (op == '/') res = quotient(n1, n2);
    else { printf("Operateur non gere ici.\n"); return; }
    
    printf("\x1B[32m>>> Resultat : %d\x1B[0m\n", res);
}

void exercice_4_2() {
    int mode; char nom[50], msg[100];
    printf("\n--- FICHIERS (4.2) ---\n1. Lire | 2. Ecrire : ");
    scanf("%d", &mode);
    printf("Nom du fichier : "); scanf("%s", nom);
    if (mode == 1) lire_fichier(nom);
    else {
        printf("Message : "); getchar();
        fgets(msg, 100, stdin);
        ecrire_dans_fichier(nom, msg);
    }
}
