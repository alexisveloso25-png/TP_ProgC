#include <stdio.h>

int main() {
    // On choisit une valeur qui a ces bits à 1 pour tester.
    // En hexadécimal, 0x10001000 active les positions 28 et 12.
    unsigned int d = 0x10001000; 

    // Extraction du 4ème bit de gauche (position 28)
    // On décale de 28 positions vers la droite et on isole le bit avec & 1
    int bit4 = (d >> 28) & 1;

    // Extraction du 20ème bit de gauche (position 12)
    int bit20 = (d >> 12) & 1;

    // Vérification : les deux doivent être égaux à 1
    if (bit4 == 1 && bit20 == 1) {
        printf("1\n");
    } else {
        printf("0\n");
    }

    return 0;
}
