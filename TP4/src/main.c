#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"

// Prototypes des fonctions
void exercice_4_1();
void exercice_4_2();
void exercice_4_3();

void afficher_menu() {
    printf("\n==============================================\n");
    printf("   MENU GENERAL - TP4 (Alexis, Salmane, Kais, Mohamed)\n");
    printf("==============================================\n");
    printf(" 1. Calculatrice Interactive (Exo 4.1)\n");
    printf(" 2. Lecture / Ecriture de fichier (Exo 4.2)\n");
    printf(" 3. Base de donnees Etudiante (Exo 4.3)\n");
    printf(" 0. Quitter\n");
    printf("----------------------------------------------\n");
    printf(" > Votre choix : ");
    fflush(stdout);
}

int main() {
    int choix;

    while (1) {
        afficher_menu();
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            default: printf("\n[!] Choix invalide.\n");
        }
        printf("\nAppuyez sur une touche pour continuer...");
        getchar(); getchar(); 
    }
    printf("\nFin du programme. Au revoir !\n");
    return 0;
}

// --- EXO 4.1 : CALCULATRICE INTERACTIVE ---
void exercice_4_1() {
    int n1, n2, res;
    char op;
    printf("\n--- CALCULATRICE ---\n");
    printf("Entrez num1 : "); fflush(stdout); scanf("%d", &n1);
    printf("Entrez num2 : "); fflush(stdout); scanf("%d", &n2);
    printf("Operateur (+, -, *, /, %%, &, |, ~) : "); fflush(stdout);
    scanf(" %c", &op);

    switch (op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        case '*': res = produit(n1, n2); break;
        case '/': res = quotient(n1, n2); break;
        case '%': res = modulo(n1, n2); break;
        case '&': res = et_bit(n1, n2); break;
        case '|': res = ou_bit(n1, n2); break;
        case '~': res = negation_bit(n1); break;
        default: printf("Erreur : Operateur inconnu.\n"); return;
    }
    printf(">>> RESULTAT : %d\n", res);
}

// --- EXO 4.2 : GESTION FICHIERS SIMPLES ---
void exercice_4_2() {
    int choix;
    char nom[50], msg[100];
    printf("\n--- GESTION FICHIERS ---\n");
    printf("1. Lire | 2. Ecrire : "); fflush(stdout);
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Fichier a lire : "); fflush(stdout); scanf("%s", nom);
        lire_fichier(nom);
    } else {
        printf("Fichier a creer : "); fflush(stdout); scanf("%s", nom);
        printf("Message : "); fflush(stdout); getchar();
        fgets(msg, 100, stdin);
        ecrire_dans_fichier(nom, msg);
    }
}

// --- EXO 4.3 : BASE DE DONNEES ETUDIANTE (Tableau de 5) ---
void exercice_4_3() {
    typedef struct { char nom[50], prenom[50], adresse[100]; int n1, n2; } Etudiant;
    Etudiant promo[5];
    char buf[400];
    printf("\n--- BASE ETUDIANTE (5 SAISIES) ---\n");

    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant %d/%d\n", i+1, 5);
        printf("Nom : "); fflush(stdout); scanf("%s", promo[i].nom);
        printf("Prenom : "); fflush(stdout); scanf("%s", promo[i].prenom);
        printf("Adresse : "); fflush(stdout); getchar();
        fgets(promo[i].adresse, 100, stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0;
        printf("Notes (1 et 2) : "); fflush(stdout);
        scanf("%d %d", &promo[i].n1, &promo[i].n2);

        sprintf(buf, "Etudiant: %s %s | Adresse: %s | Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].n1, promo[i].n2);
        
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", buf); fclose(f); }
    }
    printf("\n[OK] Sauvegarde dans etudiant.txt terminee.\n");
}
