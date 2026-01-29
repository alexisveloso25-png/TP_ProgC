#include <stdio.h>

int main() {
    // 1. Déclaration des tableaux (5 étudiants)
    // Pour les chaînes, on utilise un tableau à deux dimensions : [nombre_etudiants][taille_max_chaine]
    char noms_prenoms[5][50] = {
        "Alice Dupont",
        "Bob Martin",
        "Charlie Durand",
        "David Bernard",
        "Eve Petit"
    };

    char adresses[5][100] = {
        "12 rue des Fleurs, Paris",
        "5 Avenue Foch, Lyon",
        "8 bis Route de Rennes, Nantes",
        "22 Place de la Bourse, Bordeaux",
        "10 Boulevard Victor Hugo, Nice"
    };

    float notes_c[5] = {15.5, 12.0, 18.0, 9.5, 14.0};
    float notes_sys[5] = {14.0, 13.5, 17.0, 11.0, 16.5};

    printf("--- GESTION DES DONNEES ETUDIANTES ---\n\n");

    // 2. Boucle pour parcourir et afficher les données
    for (int i = 0; i < 5; i++) {
        printf("Etudiant.e n %d :\n", i + 1);
        printf("  Nom & Prenom : %s\n", noms_prenoms[i]);
        printf("  Adresse      : %s\n", adresses[i]);
        printf("  Note C       : %.2f/20\n", notes_c[i]);
        printf("  Note Systeme : %.2f/20\n", notes_sys[i]);
        
        // Calcul de la moyenne pour le plaisir
        float moyenne = (notes_c[i] + notes_sys[i]) / 2;
        printf("  Moyenne Gen. : %.2f/20\n", moyenne);
        
        printf("--------------------------------------\n");
    }

    return 0;
}
