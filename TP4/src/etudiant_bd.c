#include <stdio.h>
#include <string.h>
#include "fichier.h"

typedef struct {
    char nom[50], prenom[50], adresse[100];
    int note1, note2;
} Etudiant;

void exercice_4_3() {
    Etudiant promo[5];
    char buffer[400];
    
    printf("\n--- SAISIE DE 5 ETUDIANTS ---\n");
    for (int i = 0; i < 5; i++) {
        printf("\nEtudiant %d :\n", i + 1);
        printf("Nom : "); scanf("%s", promo[i].nom);
        printf("Prenom : "); scanf("%s", promo[i].prenom);
        printf("Adresse : "); getchar(); // vider buffer
        fgets(promo[i].adresse, 100, stdin);
        promo[i].adresse[strcspn(promo[i].adresse, "\n")] = 0;
        printf("Note 1 : "); scanf("%d", &promo[i].note1);
        printf("Note 2 : "); scanf("%d", &promo[i].note2);

        sprintf(buffer, "Nom: %s | Prenom: %s | Adresse: %s | Notes: %d, %d\n", 
                promo[i].nom, promo[i].prenom, promo[i].adresse, promo[i].note1, promo[i].note2);
        
        ecrire_dans_fichier("etudiant.txt", buffer);
    }
    printf("\n[OK] Enregistre dans etudiant.txt\n");
}
