#include <stdio.h>

int main() {
    printf("--- Tailles des types et des pointeurs (Architecture 64 bits) ---\n\n");

    // Types entiers et leurs pointeurs
    printf("La taille de int est : %zu octets\n", sizeof(int));
    printf("La taille de int* est : %zu octets\n", sizeof(int*));
    printf("La taille de int** est : %zu octets\n", sizeof(int**));
    printf("\n");

    // Types caractères et leurs pointeurs (multi-niveaux)
    printf("La taille de char* est : %zu octets\n", sizeof(char*));
    printf("La taille de char** est : %zu octets\n", sizeof(char**));
    printf("La taille de char*** est : %zu octets\n", sizeof(char***));
    printf("\n");

    // Types flottants et leurs pointeurs
    printf("La taille de float* est : %zu octets\n", sizeof(float*));
    printf("La taille de float** est : %zu octets\n", sizeof(float**));
    printf("La taille de float*** est : %zu octets\n", sizeof(float***));

    return 0;
}
