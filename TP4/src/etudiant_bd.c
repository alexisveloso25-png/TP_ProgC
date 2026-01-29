#include <stdio.h>
#include <stdlib.h>
#include "fichier.h"

// Structure pour stocker les données d'un étudiant
typedef struct {
    char nom[50];
    char prenom[50];
    int note1;
    int note2;
} Etudiant;

void exercice_4_3() {
    Etudiant e;
    char buffer[256];

    printf("\n--- SAISIE DE LA BASE DE DONNEES (5 ETUDIANTS) ---\n");

    for (int i = 1; i <= 5; i++) {
        printf("\n[Etudiant %d]\n", i);

        printf("Tapez le NOM de l'etudiant : ");
        fflush(stdout); // Force l'affichage immédiat du texte
        scanf("%s", e.nom);

        printf("Tapez le PRENOM de l'etudiant : ");
        fflush(stdout);
        scanf("%s", e.prenom);

        printf("Tapez la NOTE n°1 : ");
        fflush(stdout);
        scanf("%d", &e.note1);

        printf("Tapez la NOTE n°2 : ");
        fflush(stdout);
        scanf("%d", &e.note2);

        // Préparation de la ligne à écrire dans le fichier
        int moyenne = (e.note1 + e.note2) / 2;
        sprintf(buffer, "Nom: %s | Prenom: %s | Moyenne: %d\n", e.nom, e.prenom, moyenne);
        
        // Sauvegarde automatique dans le fichier (Exo 4)
        ecrire_dans_fichier("etudiant.txt", buffer);

        printf("\x1B[32mL'etudiant %s a ete ajoute au fichier 'etudiant.txt'\x1B[0m\n", e.nom);
    }
    printf("\n\x1B[36mSaisie des 5 etudiants terminee avec succes.\x1B[0m\n");
}
