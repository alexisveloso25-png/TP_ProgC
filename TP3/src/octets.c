#include <stdio.h>

void afficher_octets(void *ptr, size_t taille) {
    // On transforme le pointeur générique en pointeur d'octets (unsigned char)
    unsigned char *p = (unsigned char *)ptr;
    
    for (size_t i = 0; i < taille; i++) {
        // %02x affiche l'octet en hexadécimal sur 2 caractères
        printf("%02x ", p[i]);
    }
    printf("\n");
}

int main() {
    // Variables de test (Alexis, Salmane, Kais et Mohamed peuvent tester leurs propres valeurs)
    int entier = 0x12345678;
    float flottant = 1.0f;
    double reel = 3.14;

    printf("--- Visualisation de la memoire (Octets) ---\n\n");

    printf("Octets de l'entier (0x12345678) : ");
    afficher_octets(&entier, sizeof(entier));

    printf("Octets du flottant (1.0)        : ");
    afficher_octets(&flottant, sizeof(flottant));

    printf("Octets du double (3.14)         : ");
    afficher_octets(&reel, sizeof(reel));

    return 0;
}
