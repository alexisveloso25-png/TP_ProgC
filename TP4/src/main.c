#include <stdio.h>
#include <stdlib.h>
#include "operator.h"
#include "fichier.h"

// Utilise bien des underscores (_) et pas d'espaces
void exercice_4_1() {
    int n1, n2, res;
    char op;
    printf("\n--- Exercice 4.1 : Calculatrice ---\n");
    printf("Entrez num1 : "); fflush(stdout); scanf("%d", &n1);
    printf("Entrez num2 : "); fflush(stdout); scanf("%d", &n2);
    printf("Entrez l'operateur (+, -, *, /) : "); fflush(stdout); scanf(" %c", &op);

    switch(op) {
        case '+': res = somme(n1, n2); break;
        case '-': res = difference(n1, n2); break;
        // ... autres cas ...
        default: printf("Erreur\n"); return;
    }
    printf("Resultat : %d\n", res);
}

void exercice_4_2() {
    int choix;
    char nom[100];
    printf("\n1. Lire\n2. Ecrire\nChoix : "); fflush(stdout);
    scanf("%d", &choix);
    if(choix == 1) {
        printf("Nom du fichier : "); fflush(stdout);
        scanf("%s", nom);
        lire_fichier(nom);
    }
    // ... reste du code ...
}

int main() {
    int choix;
    printf("Quel exercice ? (1 ou 2) : ");
    fflush(stdout); 
    if (scanf("%d", &choix) == 1) {
        if (choix == 1) exercice_4_1(); // Pas d'espace ici !
        else if (choix == 2) exercice_4_2();
    }
    return 0;
}
