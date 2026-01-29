#include <stdio.h>
#include <stdlib.h> // Pour rand() et srand()
#include <time.h>   // Pour time()

int main() {
    int taille = 11;
    int t_int[11];
    float t_float[11];

    // Initialisation du générateur de nombres aléatoires
    srand(time(NULL));

    // 1. Remplissage des tableaux avec des pointeurs
    for (int i = 0; i < taille; i++) {
        *(t_int + i) = rand() % 100;           // Entiers entre 0 et 99
        *(t_float + i) = (float)rand() / RAND_MAX * 10.0; // Flottants entre 0 et 10
    }

    // --- AFFICHAGE AVANT ---
    printf("Tableau d'entiers (avant) :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d%s", *(t_int + i), (i == taille - 1) ? "" : ", ");
    }

    printf("\n\nTableau de flottants (avant) :\n");
    for (int i = 0; i < taille; i++) {
        printf("%.2f%s", *(t_float + i), (i == taille - 1) ? "" : ", ");
    }

    // 2. Multiplication par 3 si l'indice est divisible par 2
    // On utilise l'arithmétique des pointeurs sans aucune notation []
    for (int i = 0; i < taille; i++) {
        if (i % 2 == 0) {
            *(t_int + i) *= 3;
            *(t_float + i) *= 3.0;
        }
    }

    // --- AFFICHAGE APRES ---
    printf("\n\n--------------------------------------------\n");
    printf("Tableau d'entiers (apres multiplication par 3 sur indices pairs) :\n");
    for (int i = 0; i < taille; i++) {
        printf("%d%s", *(t_int + i), (i == taille - 1) ? "" : ", ");
    }

    printf("\n\nTableau de flottants (apres multiplication par 3 sur indices pairs) :\n");
    for (int i = 0; i < taille; i++) {
        printf("%.2f%s", *(t_float + i), (i == taille - 1) ? "" : ", ");
    }
    printf("\n");

    return 0;
}
