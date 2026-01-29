#include <stdio.h>
#include <string.h>

struct Etudiant {
    char nom[30];
    float note;
};

int main() {
    // Déclaration du tableau de structures pour 4 étudiants
    struct Etudiant classe[4];

    // Initialisation manuelle des données selon tes exemples
    strcpy(classe[0].nom, "Alexis");
    classe[0].note = 20.0;

    strcpy(classe[1].nom, "Salmane");
    classe[1].note = 18.0;

    strcpy(classe[2].nom, "Kais");
    classe[2].note = 18.0;

    strcpy(classe[3].nom, "Mohamed");
    classe[3].note = 18.0;

    printf("--- Notes des Etudiants ---\n\n");

    // Boucle d'affichage
    for (int i = 0; i < 4; i++) {
        printf("Etudiant %d : %s\n", i + 1, classe[i].nom);
        printf("Note : %.1f / 20\n", classe[i].note);
        
        // Petit commentaire selon la note
        if (classe[i].note >= 18) {
            printf("Mention : Excellent\n");
        } else {
            printf("Mention : Bien\n");
        }
        printf("---------------------------\n");
    }

    return 0;
}
