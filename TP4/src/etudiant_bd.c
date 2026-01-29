#include <stdio.h>
#include <string.h>
#include "fichier.h"

// Définition de la structure Etudiant
typedef struct {
    char nom[50];
    char prenom[50];
    char adresse[100];
    float note1;
    float note2;
} Etudiant;

void gerer_base_etudiants() {
    Etudiant promo[5];
    char ligne[300];
    char nom_fichier[] = "etudiant.txt";

    printf("\n=== SAISIE DE LA BASE DE DONNEES ETUDIANTE ===\n");

    for (int i = 0; i < 5; i++) {
        printf("\nEntrez les details de l'etudiant.e %d :\n", i + 1);
        
        printf("Nom : "); fflush(stdout);
        scanf("%s", promo[i].nom);
        
        printf("Prenom : "); fflush(stdout);
        scanf("%s", promo[i].prenom);
        
        printf("Adresse : "); fflush(stdout);
        getchar(); // Nettoie le buffer avant le fgets
        fgets(promo[i].adresse, sizeof(promo[i].adresse), stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0; // Enlever le \n

        printf("Note 1 : "); fflush(stdout);
        scanf("%f", &promo[i].note1);
        
        printf("Note 2 : "); fflush(stdout);
        scanf("%f", &promo[i].note2);

        // Formatage de la ligne pour le fichier
        sprintf(ligne, "Etudiant %d : %s %s, Adresse : %s, Notes : %.2f, %.2f\n", 
                i + 1, promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);
        
        // On utilise ta fonction ecrire_dans_fichier
        // Note : pour ajouter sans écraser, il faudrait modifier fichier.c avec "a" au lieu de "w"
        // Ici on écrit chaque étudiant (pour cet exo, on peut concaténer ou écrire à la fin)
        FILE *f = fopen(nom_fichier, (i == 0) ? "w" : "a"); 
        if (f != NULL) {
            fprintf(f, "%s", ligne);
            fclose(f);
        }
    }
    printf("\nLes details des etudiants ont ete enregistres dans %s.\n", nom_fichier);
}
