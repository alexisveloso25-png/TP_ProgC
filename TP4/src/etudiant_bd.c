#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fichier.h"

// Structure basee sur etudiant2.c
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    int note1;
    int note2;
} Etudiant;

void exercice_4_3() {
    // Creation d'un tableau de structures pour 5 etudiants
    Etudiant promo[5];
    char ligne_etudiant[300];

    printf("\n--- Gestion de la Base de Donnees Etudiante ---\n");

    for (int i = 0; i < 5; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);

        printf("Nom : "); fflush(stdout);
        scanf("%s", promo[i].nom);

        printf("Prenom : "); fflush(stdout);
        scanf("%s", promo[i].prenom);

        printf("Adresse : "); fflush(stdout);
        getchar(); // Nettoie le buffer pour permettre la saisie de l'adresse avec espaces
        fgets(promo[i].adresse, sizeof(promo[i].adresse), stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0; // Supprime le retour a la ligne

        printf("Note 1 : "); fflush(stdout);
        scanf("%d", &promo[i].note1);

        printf("Note 2 : "); fflush(stdout);
        scanf("%d", &promo[i].note2);

        // Preparation du formatage de la ligne
        sprintf(ligne_etudiant, "Etudiant %d: %s %s | Adresse: %s | Notes: %d, %d\n", 
                i + 1, promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);

        // Appel de la fonction ecrire_dans_fichier (fichier.c)
        // On ecrase au premier etudiant ('w'), puis on ajoute ('a') pour les suivants
        if (i == 0) {
            ecrire_dans_fichier("etudiant.txt", ligne_etudiant);
        } else {
            FILE *f = fopen("etudiant.txt", "a");
            if (f != NULL) {
                fprintf(f, "%s", ligne_etudiant);
                fclose(f);
            }
        }
    }

    printf("\n[Succes] Les details des etudiants ont ete enregistres dans etudiant.txt.\n");
}
