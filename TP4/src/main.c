#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"

void afficher_titre(char *titre) {
    printf("\n==========================================\n");
    printf("   %s\n", titre);
    printf("==========================================\n");
}

void exercice_4_1() {
    int n1, n2, res;
    char op;
    afficher_titre("EXO 4.1 : CALCULATRICE DYNAMIQUE");

    printf(" > Entrez num1 : "); fflush(stdout); scanf("%d", &n1);
    printf(" > Entrez num2 : "); fflush(stdout); scanf("%d", &n2);
    printf(" > Operateur (+, -, *, /, %%, &, |, ~) : "); fflush(stdout);
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
        default: printf("\n [!] Erreur : Operateur inconnu.\n"); return;
    }
    printf("\n [RESULTAT] : %d %c %d = %d\n", n1, op, n2, res);
}

void exercice_4_2() {
    int choix;
    char nom[50], msg[100];
    afficher_titre("EXO 4.2 : GESTION DE FICHIERS");

    printf(" 1. [LIRE] un fichier existant\n");
    printf(" 2. [ECRIRE] dans un nouveau fichier\n");
    printf(" > Votre choix : "); fflush(stdout);
    scanf("%d", &choix);

    if (choix == 1) {
        printf(" > Nom du fichier a lire : "); fflush(stdout);
        scanf("%s", nom);
        printf("\n--- DEBUT DU CONTENU ---\n");
        lire_fichier(nom);
        printf("--- FIN DU CONTENU ---\n");
    } else {
        printf(" > Nom du fichier a creer : "); fflush(stdout);
        scanf("%s", nom);
        printf(" > Message a enregistrer : "); fflush(stdout);
        getchar(); // Nettoie le buffer
        fgets(msg, 100, stdin);
        ecrire_dans_fichier(nom, msg);
    }
}

int main() {
    int choix;
    system("clear"); // Nettoie l'écran au lancement
    afficher_titre("MENU PRINCIPAL - TP4 PROGC");
    
    printf("  [1] Lancer la Calculatrice\n");
    printf("  [2] Lancer la Gestion de Fichiers\n");
    printf("  [0] Quitter le programme\n");
    printf("\n > Selection : "); fflush(stdout);
    
    if (scanf("%d", &choix) == 1 && choix != 0) {
        if (choix == 1) exercice_4_1();
        else if (choix == 2) exercice_4_2();
    } else {
        printf("\n Au revoir !\n");
    }
    return 0;
}
