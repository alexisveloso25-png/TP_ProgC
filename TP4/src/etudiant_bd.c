#include <stdio.h>
#include <string.h>

typedef struct { char n[50], p[50]; int n1, n2; } Etudiant;

void exercice_4_3() {
    printf("\n--- GESTION ETUDIANTS (4.3) ---\n");
    Etudiant e;
    printf("Nom : "); scanf("%s", e.n);
    printf("Note 1 : "); scanf("%d", &e.n1);
    // Logique de sauvegarde...
    printf("Etudiant %s enregistre.\n", e.n);
}
