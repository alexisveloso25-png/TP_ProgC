#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h" // Inclusion du nouvel en tête

void exercice_4_2() {
    int choix;
    char nom_f[100];
    char msg[256];

    printf("\nQue souhaitez-vous faire ?\n");
    printf("1. Lire un fichier\n");
    printf("2. Ecrire dans un fichier\n");
    printf("Votre choix : ");
    fflush(stdout);
    scanf("%d", &choix);
    getchar(); // Consomme le retour à la ligne restant

    if (choix == 1) {
        printf("Entrez le nom du fichier a lire : ");
        fflush(stdout);
        scanf("%s", nom_f);
        lire_fichier(nom_f); //
    } 
    else if (choix == 2) {
        printf("Entrez le nom du fichier : ");
        fflush(stdout);
        scanf("%s", nom_f);
        getchar(); // Nettoyage avant le message

        printf("Entrez le message a ecrire : ");
        fflush(stdout);
        fgets(msg, sizeof(msg), stdin); // fgets permet de saisir des espaces
        
        ecrire_dans_fichier(nom_f, msg); //
    } 
    else {
        printf("Choix invalide.\n");
    }
}

int main() {
    int choix;
    printf("Menu de Travail :\n");
    printf("1. Exercice 4.1 (Calculatrice)\n");
    printf("2. Exercice 4.2 (Fichiers)\n");
    printf("Votre choix : ");
    fflush(stdout);
    scanf("%d", &choix);

    if (choix == 1) exercice_4_1();
    else if (choix == 2) exercice_4_2(); // Appel de la nouvelle fonction
    else printf("Choix non valide.\n");

    return 0;
}
