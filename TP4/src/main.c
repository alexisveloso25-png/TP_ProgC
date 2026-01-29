#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "fichier.h"

// Prototypes des fonctions des exercices
void exercice_4_1();
void exercice_4_2();
void exercice_4_3();

// Fonction pour faire une jolie banniere
void banniere(char *titre) {
    printf("\n==============================================\n");
    printf("   %s\n", titre);
    printf("==============================================\n");
}

int main() {
    int choix;

    while (1) {
        banniere("MENU PRINCIPAL - TP4 PROGC");
        printf(" 1. Calculatrice avec operateurs (Exo 4.1)\n");
        printf(" 2. Lecture / Ecriture de fichier (Exo 4.2)\n");
        printf(" 3. Base de donnees Etudiante (Exo 4.3)\n");
        printf(" 0. Quitter\n");
        printf("\n > Votre choix : ");
        fflush(stdout);

        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            default: printf("\n[!] Choix invalide.\n");
        }
        
        printf("\nAppuyez sur Entree pour revenir au menu...");
        getchar(); getchar(); // Attend que l'utilisateur lise le resultat
    }

    printf("\nAu revoir !\n");
    return 0;
}

// --- Implementation de l'Exo 4.1 (Calculatrice) ---
void exercice_4_1() {
    int n1, n2, res;
    char op;
    banniere("EXO 4.1 : CALCULATRICE");

    printf("Entrez num1 : "); fflush(stdout);
    scanf("%d", &n1);
    printf("Entrez num2 : "); fflush(stdout);
    scanf("%d", &n2);
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
        default: printf("Operateur inconnu.\n"); return;
    }
    printf("\n>>> RESULTAT : %d\n", res);
}

// --- Implementation de l'Exo 4.2 (Fichiers) ---
void exercice_4_2() {
    int choix;
    char nom[50], msg[100];
    banniere("EXO 4.2 : GESTION FICHIERS");

    printf("1. Lire un fichier\n2. Ecrire dans un fichier\nChoix : "); fflush(stdout);
    scanf("%d", &choix);

    if (choix == 1) {
        printf("Nom du fichier a lire : "); fflush(stdout);
        scanf("%s", nom);
        lire_fichier(nom);
    } else {
        printf("Nom du fichier : "); fflush(stdout);
        scanf("%s", nom);
        printf("Message : "); fflush(stdout);
        getchar(); // Nettoyage buffer
        fgets(msg, 100, stdin);
        ecrire_dans_fichier(nom, msg);
    }
}

// --- Implementation de l'Exo 4.3 (Base Etudiante) ---
// Note: Cette fonction peut aussi etre mise dans etudiant_bd.c
void exercice_4_3() {
    // Structure locale (reutilise etudiant2.c)
    typedef struct {
        char nom[50], prenom[50], adresse[100];
        int n1, n2;
    } Etudiant;

    Etudiant promo[5]; // Tableau de taille 5
    char buffer[400];
    banniere("EXO 4.3 : BASE ETUDIANTE");

    for (int i = 0; i < 5; i++) {
        printf("\n--- Etudiant.e %d ---\n", i + 1);
        printf("Nom : "); fflush(stdout); scanf("%s", promo[i].nom);
        printf("Prenom : "); fflush(stdout); scanf("%s", promo[i].prenom);
        printf("Adresse : "); fflush(stdout); getchar();
        fgets(promo[i].adresse, 100, stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0;
        printf("Note 1 : "); fflush(stdout); scanf("%d", &promo[i].n1);
        printf("Note 2 : "); fflush(stdout); scanf("%d", &promo[i].n2);

        sprintf(buffer, "Nom: %s, Prenom: %s, Adresse: %s, Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].n1, promo[i].n2);
        
        // Ecriture : 'w' pour le premier (reset), 'a' pour les suivants
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", buffer); fclose(f); }
    }
    printf("\n[OK] Base enregistree dans etudiant.txt\n");
}
