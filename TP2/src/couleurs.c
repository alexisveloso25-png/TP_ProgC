#include <stdio.h>

// 1. Définition de la structure RGBA
struct Couleur {
    unsigned char r; // Rouge
    unsigned char g; // Vert
    unsigned char b; // Bleu
    unsigned char a; // Alpha (transparence)
};

int main() {
    // 2. Création d'un tableau de 10 couleurs
    struct Couleur palette[10];

    // 3. Initialisation en notation hexadécimale
    // Couleur 1 : Un orange vif
    palette[0].r = 0xEF; palette[0].g = 0x78; palette[0].b = 0x12; palette[0].a = 0xFF;
    
    // Couleur 2 : Un vert émeraude
    palette[1].r = 0x2C; palette[1].g = 0xC8; palette[1].b = 0x64; palette[1].a = 0xFF;

    // Couleur 3 : Bleu royal
    palette[2].r = 0x41; palette[2].g = 0x69; palette[2].b = 0xE1; palette[2].a = 0xFF;

    // Couleur 4 : Rouge pur à demi-transparent
    palette[3].r = 0xFF; palette[3].g = 0x00; palette[3].b = 0x00; palette[3].a = 0x80;

    // Couleur 5 : Blanc
    palette[4].r = 0xFF; palette[4].g = 0xFF; palette[4].b = 0xFF; palette[4].a = 0xFF;

    // Couleur 6 : Noir
    palette[5].r = 0x00; palette[5].g = 0x00; palette[5].b = 0x00; palette[5].a = 0xFF;

    // Couleur 7 : Gris
    palette[6].r = 0x80; palette[6].g = 0x80; palette[6].b = 0x80; palette[6].a = 0xFF;

    // Couleur 8 : Jaune
    palette[7].r = 0xFF; palette[7].g = 0xFF; palette[7].b = 0x00; palette[7].a = 0xFF;

    // Couleur 9 : Magenta
    palette[8].r = 0xFF; palette[8].g = 0x00; palette[8].b = 0xFF; palette[8].a = 0xFF;

    // Couleur 10 : Cyan
    palette[9].r = 0x00; palette[9].g = 0xFF; palette[9].b = 0xFF; palette[9].a = 0xFF;

    // 4. Affichage des couleurs
    printf("--- AFFICHAGE DE LA PALETTE RGBA ---\n\n");

    for (int i = 0; i < 10; i++) {
        printf("Couleur %d :\n", i + 1);
        printf("Rouge : %u\n", palette[i].r);
        printf("Vert  : %u\n", palette[i].g);
        printf("Bleu  : %u\n", palette[i].b);
        printf("Alpha : %u\n\n", palette[i].a);
    }

    return 0;
}
