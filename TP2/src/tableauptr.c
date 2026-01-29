#include <stdio.h>

int main() {
    // 1. Déclaration des variables de base
    char c = 'A';
    short s = 10;
    int i = 100;
    long int li = 1000;
    long long int lli = 10000;
    float f = 2.0f;
    double d = 4.0;
    long double ld = 8.0L;

    // 2. Déclaration des pointeurs
    char *p_c = &c;
    short *p_s = &s;
    int *p_i = &i;
    long int *p_li = &li;
    long long int *p_lli = &lli;
    float *p_f = &f;
    double *p_d = &d;
    long double *p_ld = &ld;

    printf("--- Avant la manipulation ---\n");
    // Affichage des adresses (%p) et des valeurs en hexadécimal (%x)
    printf("Adresse de c : %p, Valeur de c (hex) : %x\n", (void*)p_c, c);
    printf("Adresse de i : %p, Valeur de i (hex) : %x\n", (void*)p_i, i);
    // Pour les flottants, on interprète leur adresse comme un pointeur d'entier pour voir l'hexadécimal réel
    printf("Adresse de f : %p, Valeur de f (hex) : %x\n", (void*)p_f, *(unsigned int*)&f);
    printf("\n");

    // 3. Manipulation via les pointeurs (Accès indirect)
    *p_c = 'B';           // Modifie c via p_c
    *p_i = 0xABCDE;       // Modifie i via p_i
    *p_f = 1.0f;          // Modifie f via p_f (1.0f en IEEE 754 est 0x3f800000)

    printf("--- Apres la manipulation ---\n");
    printf("Adresse de c : %p, Valeur de c (hex) : %x\n", (void*)p_c, c);
    printf("Adresse de i : %p, Valeur de i (hex) : %x\n", (void*)p_i, i);
    printf("Adresse de f : %p, Valeur de f (hex) : %x\n", (void*)p_f, *(unsigned int*)&f);

    return 0;
}
