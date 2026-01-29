#include <stdio.h>
#include <string.h>
#include "fichier.h"

typedef struct {
    char nom[50], prenom[50], adresse[100];
    int note1, note2;
} Etudiant;

void exercice_4_3() {
    Etudiant p[5];
    char buf[400];
    printf("\n--- SAISIE 5 ETUDIANTS ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant %d - Nom : ", i + 1); scanf("%s", p[i].nom);
        printf("Prenom : "); scanf("%s", p[i].prenom);
        printf("Note 1 : "); scanf("%d", &p[i].note1);
        printf("Note 2 : "); scanf("%d", &p[i].note2);
        sprintf(buf, "Nom: %s | Prenom: %s | Notes: %d, %d\n", p[i].nom, p[i].prenom, p[i].note1, p[i].note2);
        ecrire_dans_fichier("etudiant.txt", buf);
    }
}
