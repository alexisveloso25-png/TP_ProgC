#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"

// Prototypes des fonctions externes
int factorielle(int num); // Vient de factorielle.c
void exercice_4_1();      // Vient de main.c (plus bas)
void exercice_4_2();
void exercice_4_3();

void afficher_menu() {
    printf("\n==============================================\n");
    printf("   MENU GENERAL TP4 - (Alexis, Salmane, Kais, Mohamed)\n");
    printf("==============================================\n");
    printf(" 1. Calculatrice Interactive (Exo 4.1)\n");
    printf(" 2. Lecture / Ecriture de fichier (Exo 4.2)\n");
    printf(" 3. Base de donnees Etudiante (Exo 4.3)\n");
    printf(" 5. Calcul de Factorielle Recursive (Exo 4.5)\n");
    printf(" 0. Quitter\n");
    printf("----------------------------------------------\n");
    printf(" > Votre choix : ");
    fflush(stdout);
}

int main() {
    int choix, n;

    while (1) {
        afficher_menu();
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            case 5: 
                printf("\n--- EXO 4.5 : FACTORIELLE ---\n");
                printf("Entrez un entier naturel : "); fflush(stdout);
                scanf("%d", &n);
                if (n < 0) {
                    printf("Erreur : La factorielle n'est pas definie pour les nombres negatifs.\n");
                } else {
                    int resultat = factorielle(n);
                    printf("Resultat final de %d! = %d\n", n, resultat);
                }
                break;
            default: printf("\n[!] Choix invalide.\n");
        }
        printf("\nAppuyez sur Entree pour continuer...");
        getchar(); getchar(); 
    }
    return 0;
}

// --- Fonctions 4.1, 4.2, 4.3 (Contenu identique aux etapes precedentes) ---
void exercice_4_1() {
    int n1, n2, res; char op;
    printf("\n--- CALCULATRICE ---\n");
    printf("num1 : "); fflush(stdout); scanf("%d", &n1);
    printf("num2 : "); fflush(stdout); scanf("%d", &n2);
    printf("Operateur : "); fflush(stdout); scanf(" %c", &op);
    switch(op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        default: printf("Erreur op\n"); return;
    }
    printf("Resultat : %d\n", res);
}

void exercice_4_2() {
    int c; char nom[50], msg[100];
    printf("\n1. Lire | 2. Ecrire : "); fflush(stdout); scanf("%d", &c);
    if (c == 1) { printf("Nom : "); scanf("%s", nom); lire_fichier(nom); }
    else { printf("Nom : "); scanf("%s", nom); getchar(); printf("Message : "); fgets(msg, 100, stdin); ecrire_dans_fichier(nom, msg); }
}

void exercice_4_3() {
    typedef struct { char n[50], p[50], a[100]; int n1, n2; } Etudiant;
    Etudiant e; char b[400];
    for (int i = 0; i < 5; i++) {
        printf("\nSaisie %d/5\nNom : ", i+1); scanf("%s", e.n);
        printf("Prenom : "); scanf("%s", e.p);
        printf("Adresse : "); getchar(); fgets(e.a, 100, stdin);
        e.a[strcspn(e.a, "\n")] = 0;
        printf("Notes (1 et 2) : "); scanf("%d %d", &e.n1, &e.n2);
        sprintf(b, "Nom: %s, Prenom: %s, Adresse: %s, Notes: %d, %d\n", e.n, e.p, e.a, e.n1, e.n2);
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", b); fclose(f); }
    }
}
