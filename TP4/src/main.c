#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"

// Prototypes des fonctions externes
int factorielle(int num);                 // factorielle.c
void exercice_4_6(char *nom_fichier);    // chercherfichier.c
void exercice_4_1(); 
void exercice_4_2();
void exercice_4_3();

void afficher_menu() {
    printf("\n==============================================\n");
    printf("   MENU GENERAL TP4 - PROGC (Alexis, Salmane, Kais, Mohamed)\n");
    printf("==============================================\n");
    printf(" 1. Calculatrice Interactive (Exo 4.1)\n");
    printf(" 2. Lecture / Ecriture de fichier (Exo 4.2)\n");
    printf(" 3. Base de donnees Etudiante (Exo 4.3)\n");
    printf(" 4. Aide : Calculatrice Ligne de Commande (Exo 4.4)\n");
    printf(" 5. Calcul de Factorielle (Exo 4.5)\n");
    printf(" 6. Recherche de phrase dans un fichier (Exo 4.6)\n");
    printf(" 0. Quitter\n");
    printf("----------------------------------------------\n");
    printf(" > Votre choix : ");
    fflush(stdout);
}

int main(int argc, char *argv[]) {
    int choix;

    // --- GESTION SPECIFIQUE DE L'EXO 4.6 VIA ARGUMENT ---
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    while (1) {
        afficher_menu();
        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            case 4: 
                printf("\n--- INFO EXO 4.4 ---\n");
                printf("Pour utiliser la calculatrice en ligne de commande :\n");
                printf("1. Compilez : gcc calcule.c operator.c -o calcule\n");
                printf("2. Lancez : ./calcule + 10 5\n");
                break;
            case 5: {
                int n;
                printf("\nEntrez un nombre : "); fflush(stdout);
                scanf("%d", &n);
                if(n >= 0) printf("Resultat : %d\n", factorielle(n));
                break;
            }
            case 6: {
                char nom[50];
                printf("\nFichier pour la recherche : "); fflush(stdout);
                scanf("%s", nom);
                exercice_4_6(nom);
                break;
            }
            default: printf("\n[!] Choix invalide.\n");
        }
        printf("\nAppuyez sur Entree pour continuer...");
        getchar(); getchar(); 
    }
    return 0;
}

// --- CONTENU DES EXERCICES 4.1, 4.2, 4.3 ---
void exercice_4_1() {
    int n1, n2, res; char op;
    printf("\nnum1 : "); fflush(stdout); scanf("%d", &n1);
    printf("num2 : "); fflush(stdout); scanf("%d", &n2);
    printf("Op (+,-,*,/,%%,&,|,~) : "); fflush(stdout); scanf(" %c", &op);
    if (op == '+') res = somme(n1, n2); 
    else if (op == '-') res = difference(n1, n2);
    else if (op == '*') res = produit(n1, n2);
    else if (op == '/') res = quotient(n1, n2);
    else if (op == '%') res = modulo(n1, n2);
    else if (op == '&') res = et_bit(n1, n2);
    else if (op == '|') res = ou_bit(n1, n2);
    else if (op == '~') res = negation_bit(n1);
    printf(">>> Resultat : %d\n", res);
}

void exercice_4_2() {
    int c; char nom[50], msg[100];
    printf("\n1.Lire 2.Ecrire : "); fflush(stdout); scanf("%d", &c);
    if (c == 1) { printf("Nom du fichier : "); scanf("%s", nom); lire_fichier(nom); }
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
        sprintf(b, "Etudiant: %s %s | Adresse: %s | Notes: %d, %d\n", e.n, e.p, e.a, e.n1, e.n2);
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", b); fclose(f); }
    }
}
