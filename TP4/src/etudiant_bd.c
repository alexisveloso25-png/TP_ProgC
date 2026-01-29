#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

// Structure pour la gestion des données (Exo 4.3)
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    int note1;
    int note2;
} Etudiant;

void exercice_4_3() {
    // Création d'un tableau de structures de taille 5
    Etudiant promo[5];
    char ligne[300];

    printf("\n\x1B[33m=== GESTION BASE ETUDIANTE (EXO 4.3) ===\x1B[0m\n");

    // Boucle de saisie pour 5 étudiants
    for (int i = 0; i < 5; i++) {
        printf("\nSaisie de l'etudiant.e %d/5 :\n", i + 1);
        
        printf("Nom : "); fflush(stdout);
        scanf("%s", promo[i].nom);
        
        printf("Prenom : "); fflush(stdout);
        scanf("%s", promo[i].prenom);
        
        printf("Adresse : "); fflush(stdout);
        getchar(); // Nettoyage buffer
        fgets(promo[i].adresse, 100, stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0;

        printf("Note 1 : "); fflush(stdout);
        scanf("%d", &promo[i].note1);
        
        printf("Note 2 : "); fflush(stdout);
        scanf("%d", &promo[i].note2);

        // Formatage pour le fichier etudiant.txt
        sprintf(ligne, "Nom: %s | Prenom: %s | Adresse: %s | Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);
        
        // Écriture : 'w' pour le premier (écrase), 'a' pour les autres (ajoute)
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a");
        if (f != NULL) {
            fprintf(f, "%s", ligne);
            fclose(f);
        }
    }
    printf("\n\x1B[32m[Succes] Les 5 etudiants sont enregistres dans etudiant.txt\x1B[0m\n");
}
