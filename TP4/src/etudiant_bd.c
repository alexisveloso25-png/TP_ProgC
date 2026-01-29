#include <stdio.h>
#include <string.h>
#include "fichier.h"

typedef struct { char nom[50], pre[50], adr[100]; int n1, n2; } Etudiant;

void exercice_4_3() {
    Etudiant e; char buf[512];
    printf("\n\x1B[34m╔════════════════════════════════════╗\n");
    printf("║  SAISIE BASE DE DONNÉES ÉTUDIANTS  ║\n");
    printf("╚════════════════════════════════════╝\x1B[0m\n");
    for (int i = 1; i <= 5; i++) {
        printf("\x1B[33m[Etudiant %d/5]\x1B[0m\n", i);
        printf(" > Nom: "); scanf("%s", e.nom);
        printf(" > Prénom: "); scanf("%s", e.pre);
        printf(" > Adresse: "); getchar(); fgets(e.adr, 100, stdin);
        e.adr[strcspn(e.adr, "\n")] = 0;
        printf(" > Notes (Ex1 Ex2): "); scanf("%d %d", &e.n1, &e.n2);
        
        sprintf(buf, "Nom: %s | Prenom: %s | Adresse: %s | Moyenne: %d\n", 
                e.nom, e.pre, e.adr, (e.n1+e.n2)/2);
        ecrire_dans_fichier("etudiant.txt", buf);
    }
    printf("\x1B[32m✔ Données enregistrées dans 'etudiant.txt'.\x1B[0m\n");
}
