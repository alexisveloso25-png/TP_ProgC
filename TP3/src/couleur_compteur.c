#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 1. Structure pour représenter une couleur RGBA
typedef struct {
    unsigned char r, g, b, a;
} Couleur;

// Structure pour stocker une couleur et son nombre d'apparitions
typedef struct {
    Couleur color;
    int compteur;
} CouleurDistincte;

// Fonction pour comparer deux couleurs
int sont_identiques(Couleur c1, Couleur c2) {
    return (c1.r == c2.r && c1.g == c2.g && c1.b == c2.b && c1.a == c2.a);
}

int main() {
    Couleur palette[100];
    CouleurDistincte distinctes[100];
    int nb_distinctes = 0;

    srand(time(NULL));

    // 2. Remplissage du tableau avec des couleurs aléatoires
    // On limite volontairement à 10 variations pour voir des doublons
    for (int i = 0; i < 100; i++) {
        palette[i].r = rand() % 10; 
        palette[i].g = rand() % 10;
        palette[i].b = rand() % 10;
        palette[i].a = 255; // Opaque par défaut
    }

    // 3. Logique de comptage
    for (int i = 0; i < 100; i++) {
        int trouve = 0;
        
        // On vérifie si la couleur est déjà dans notre liste "distinctes"
        for (int j = 0; j < nb_distinctes; j++) {
            if (sont_identiques(palette[i], distinctes[j].color)) {
                distinctes[j].compteur++;
                trouve = 1;
                break;
            }
        }

        // Si c'est une nouvelle couleur, on l'ajoute à la liste
        if (!trouve) {
            distinctes[nb_distinctes].color = palette[i];
            distinctes[nb_distinctes].compteur = 1;
            nb_distinctes++;
        }
    }

    // 4. Affichage des résultats
    printf("--- Compteur de Couleurs (Alexis, Salmane, Kais, Mohamed) ---\n");
    printf("Couleurs distinctes trouvees :\n\n");

    for (int i = 0; i < nb_distinctes; i++) {
        printf("0x%02x 0x%02x 0x%02x 0x%02x : %d occurrence(s)\n", 
                distinctes[i].color.r, 
                distinctes[i].color.g, 
                distinctes[i].color.b, 
                distinctes[i].color.a, 
                distinctes[i].compteur);
    }

    return 0;
}
