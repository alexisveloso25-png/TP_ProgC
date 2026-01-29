#include <stdio.h>
#include <string.h>
#include "fichier.h"
typedef struct { char nom[50], pre[50]; int n1, n2; } Etudiant;
void exercice_4_3() {
    Etudiant e; char buf[512];
    printf("\n--- SAISIE DE LA BASE DE DONNEES (5 ETUDIANTS) ---\n");
    for (int i = 1; i <= 5; i++) {
        printf("\n[Etudiant %d]\n", i);
        printf("Tapez le NOM de l'etudiant : "); scanf("%s", e.nom);
        printf("Tapez le PRENOM : "); scanf("%s", e.pre);
        printf("Tapez la NOTE n°1 : "); scanf("%d", &e.n1);
        printf("Tapez la NOTE n°2 : "); scanf("%d", &e.n2);
        sprintf(buf, "Etudiant: %s %s | Note1: %d | Note2: %d | Moyenne: %d\n", e.nom, e.pre, e.n1, e.n2, (e.n1+e.n2)/2);
        ecrire_dans_fichier("etudiant.txt", buf);
        printf("\x1B[32mL'etudiant %s a ete ajoute au fichier 'etudiant.txt'\x1B[0m\n", e.nom);
    }
}
