#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

// Structure pour regrouper les informations d'un etudiant.
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    int note1;
    int note2;
} Etudiant;

void exercice_4_7() {
    // 1. Creation d'un tableau de structures de taille 5
    Etudiant promo[5];
    char buffer[500];

    printf("\n--- Exercice 4.7 : Gestion de la base de donnees etudiante ---\n");

    // 2. Boucle for pour la saisie des 5 etudiants
    for (int i = 0; i < 5; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);
        
        printf("Nom : "); fflush(stdout);
        scanf("%s", promo[i].nom);
        
        printf("Prenom : "); fflush(stdout);
        scanf("%s", promo[i].prenom);
        
        printf("Adresse : "); fflush(stdout);
        getchar(); // Nettoyage indispensable pour fgets
        fgets(promo[i].adresse, sizeof(promo[i].adresse), stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0; // Enlever le retour ligne

        printf("Note 1 : "); fflush(stdout);
        scanf("%d", &promo[i].note1);
        
        printf("Note 2 : "); fflush(stdout);
        scanf("%d", &promo[i].note2);

        // 3. Formatage des details pour le fichier
        // Chaque etudiant occupe une ligne distincte
        sprintf(buffer, "Nom: %s | Prenom: %s | Adresse: %s | Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);
        
        // 4. Ecriture dans le fichier (on ajoute 'a' pour "append" si on veut tout garder, 
        // ou on gere l'ouverture dans la boucle)
        FILE *f = fopen("etudiant.txt", (i == 0) ? "w" : "a"); 
        if (f != NULL) {
            fprintf(f, "%s", buffer);
            fclose(f);
        }
    }

    printf("\nLes details des etudiants ont ete enregistres dans le fichier etudiant.txt.\n");
}

