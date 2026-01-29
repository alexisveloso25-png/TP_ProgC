#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // Pour usleep (effet de chargement)

#include "operator.h"
#include "fichier.h"
#include "liste.h"

// Couleurs pour le terminal
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define CYN   "\x1B[36m"
#define RESET "\x1B[0m"

// Prototypes des fonctions externes
int factorielle(int num);
void exercice_4_1(); 
void exercice_4_2();
void exercice_4_3();
void exercice_4_6(char *nom_fichier);
void exercice_4_7();

void effacer_ecran() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void titre(char *txt) {
    printf("\n" CYN ">>> %s <<<" RESET "\n", txt);
    printf("------------------------------------------\n");
}

int main(int argc, char *argv[]) {
    // Gestion automatique du mode argument (Exo 4.6)
    if (argc == 2) {
        exercice_4_6(argv[1]);
        return 0;
    }

    int choix;
    while (1) {
        effacer_ecran();
        printf(YEL "==============================================\n");
        printf("       SUPER PROGRAMME TP4 - GROUPE A\n");
        printf("   (Alexis, Salmane, Kais & Mohamed)\n");
        printf("==============================================\x1B[0m\n");
        printf(GRN " 1." RESET " Calculatrice Interactive      (4.1)\n");
        printf(GRN " 2." RESET " Gestion Fichiers Simple       (4.2)\n");
        printf(GRN " 3." RESET " Base de Donnees Etudiants     (4.3)\n");
        printf(GRN " 4." RESET " Info Calculatrice CLI         (4.4)\n");
        printf(GRN " 5." RESET " Factorielle Recursive         (4.5)\n");
        printf(GRN " 6." RESET " Recherche dans un Fichier     (4.6)\n");
        printf(GRN " 7." RESET " Liste Chainee de Couleurs     (4.7)\n");
        printf(RED " 0. Quitter le programme" RESET "\n");
        printf("\n" YEL "> Votre choix : " RESET);
        fflush(stdout);

        if (scanf("%d", &choix) != 1) break;
        if (choix == 0) break;

        effacer_ecran();
        switch (choix) {
            case 1: exercice_4_1(); break;
            case 2: exercice_4_2(); break;
            case 3: exercice_4_3(); break;
            case 4: 
                titre("INFO EXO 4.4");
                printf("Usage terminal : " GRN "./calcule + 10 5" RESET "\n");
                printf("Opérateurs supportés : +, -, *, /, %%, &, |, ~\n");
                break;
            case 5: {
                int n; titre("FACTORIELLE");
                printf("Entrez un nombre : "); fflush(stdout); scanf("%d", &n);
                if(n >= 0) printf("\n" GRN "Resultat final : %d" RESET "\n", factorielle(n));
                else printf(RED "Erreur : Nombre négatif !" RESET "\n");
                break;
            }
            case 6: {
                char nom[50]; titre("RECHERCHE TEXTUELLE");
                printf("Nom du fichier source : "); fflush(stdout); scanf("%s", nom);
                exercice_4_6(nom);
                break;
            }
            case 7: exercice_4_7(); break;
            default: printf(RED "Choix invalide !" RESET "\n");
        }
        printf("\n\n" CYN "Appuyez sur Entrée pour revenir au menu..." RESET);
        getchar(); getchar(); 
    }

    printf(YEL "\nFermeture du programme...\n" RESET);
    return 0;
}

// --- Implémentations raccourcies pour le main ---

void exercice_4_1() {
    int n1, n2, res; char op;
    titre("CALCULATRICE");
    printf("Entrez l'opération (ex: 10 + 5) : "); fflush(stdout);
    scanf("%d %c %d", &n1, &op, &n2);
    if (op == '+') res = somme(n1, n2); 
    else if (op == '-') res = difference(n1, n2);
    else if (op == '*') res = produit(n1, n2);
    else if (op == '/') res = quotient(n1, n2);
    else if (op == '%') res = modulo(n1, n2);
    printf("\n" GRN ">>> Résultat : %d" RESET "\n", res);
}

void exercice_4_2() {
    int c; char nom[50], msg[100];
    titre("GESTION FICHIERS");
    printf("1. Lire | 2. Ecrire : "); fflush(stdout); scanf("%d", &c);
    printf("Nom du fichier : "); scanf("%s", nom);
    if (c == 1) lire_fichier(nom);
    else { 
        printf("Message : "); getchar(); fgets(msg, 100, stdin); 
        ecrire_dans_fichier(nom, msg); 
    }
}

void exercice_4_3() {
    typedef struct { char n[50], p[50], a[100]; int n1, n2; } Etudiant;
    Etudiant e; char b[400];
    titre("BASE ETUDIANTE (5 SAISIES)");
    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant " YEL "%d/5" RESET "\n", i+1);
        printf("Nom : "); scanf("%s", e.n);
        printf("Prénom : "); scanf("%s", e.p);
        printf("Adresse : "); getchar(); fgets(e.a, 100, stdin);
        e.a[strcspn(e.a, "\n")] = 0;
        printf("Notes (1 et 2) : "); scanf("%d %d", &e.n1, &e.n2);
        sprintf(b, "Etudiant: %s %s | Adresse: %s | Notes: %d, %d\n", e.n, e.p, e.a, e.n1, e.n2);
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", b); fclose(f); }
    }
    printf(GRN "\nFichier etudiant.txt mis à jour !" RESET);
}

void exercice_4_7() {
    struct liste_couleurs ma_liste;
    init_liste(&ma_liste);
    titre("LISTE CHAINÉE DE COULEURS");
    for (int i = 0; i < 10; i++) {
        struct couleur c = {(unsigned char)(i*25), (unsigned char)(255-i*10), (unsigned char)(i*15), 0xFF};
        insertion(&c, &ma_liste);
    }
    parcours(&ma_liste);
    printf(GRN "\nListe de 10 couleurs générée avec succès." RESET);
}
