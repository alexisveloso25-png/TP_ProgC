#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    int note1;
    int note2;
} Etudiant;

// L'unique définition de la fonction
void exercice_4_3() {
    Etudiant promo[5];
    char ligne[300];

    printf("\n--- GESTION BASE ETUDIANTE (4.3) ---\n");

    for (int i = 0; i < 5; i++) {
        printf("\nSaisie de l'etudiant.e %d/5 :\n", i + 1);
        printf("Nom : "); fflush(stdout); scanf("%s", promo[i].nom);
        printf("Prenom : "); fflush(stdout); scanf("%s", promo[i].prenom);
        printf("Adresse : "); fflush(stdout); getchar();
        fgets(promo[i].adresse, 100, stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0;
        printf("Note 1 : "); fflush(stdout); scanf("%d", &promo[i].note1);
        printf("Note 2 : "); fflush(stdout); scanf("%d", &promo[i].note2);

        sprintf(ligne, "Nom: %s | Prenom: %s | Adresse: %s | Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);
        
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f) { fprintf(f, "%s", ligne); fclose(f); }
    }
    printf("\n[OK] Enregistre dans etudiant.txt\n");
}
