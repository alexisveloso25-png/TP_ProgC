#include <stdio.h>

int main() {
    // 1. Caractères
    char c = 'A';
    unsigned char uc = 255;
    signed char sc = -127;

    // 2. Entiers courts (short)
    short s = -32768;
    unsigned short us = 65535;

    // 3. Entiers standards (int)
    int i = -2147483648;
    unsigned int ui = 4294967295U;

    // 4. Entiers longs (long int)
    long int li = -9223372036854775807L;
    unsigned long int uli = 18446744073709551615UL;

    // 5. Entiers très longs (long long int)
    long long int lli = -9223372036854775807LL;
    unsigned long long int ulli = 18446744073709551615ULL;

    // 6. Flottants (Pas de version unsigned)
    float f = 3.14159f;
    double d = 3.141592653589793;
    long double ld = 3.14159265358979323846L;

    // Affichage
    printf("--- Valeurs des variables ---\n");
    printf("char : %c (code ASCII : %d)\n", c, c);
    printf("unsigned char : %u\n", uc);
    printf("signed char : %d\n\n", sc);

    printf("short : %hd\n", s);
    printf("unsigned short : %hu\n\n", us);

    printf("int : %d\n", i);
    printf("unsigned int : %u\n\n", ui);

    printf("long int : %ld\n", li);
    printf("unsigned long int : %lu\n\n", uli);

    printf("long long int : %lld\n", lli);
    printf("unsigned long long int : %llu\n\n", ulli);

    printf("float : %f\n", f);
    printf("double : %f\n", d);
    printf("long double : %Lf\n", ld);

    return 0;
}
