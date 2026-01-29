#include <stdio.h>

int main() {
    // Liste des nombres à tester
    int nombres[] = {0, 4096, 65536, 65535, 1024};
    int taille = 5;

    for (int n = 0; n < taille; n++) {
        int num = nombres[n];
        printf("Nombre : %d\t Binaire : ", num);

        // Si le nombre est 0, on l'affiche directement
        if (num == 0) {
            printf("0");
        } else {
            // On commence par trouver le bit le plus haut pour éviter les zéros inutiles à gauche
            // On suppose un int sur 32 bits
            int affiche = 0; // Drapeau pour commencer l'affichage
            
            for (int i = 31; i >= 0; i--) {
                // On décale 1 de 'i' positions vers la gauche (le masque)
                // On vérifie si le bit à la position 'i' est à 1
                if ((num >> i) & 1) {
                    printf("1");
                    affiche = 1; // On a trouvé le premier 1, on peut commencer à afficher
                } else {
                    // On n'affiche le 0 que si on a déjà commencé à afficher des 1
                    if (affiche) {
                        printf("0");
                    }
                }
            }
        }
        printf("\n");
    }

    return 0;
}
