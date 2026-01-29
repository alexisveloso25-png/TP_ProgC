
#include <stdio.h>

int main() {
    printf("--- Tailles des types de base en C ---\n\n");

    // Types Caractères
    printf("char : %zu octets\n", sizeof(char));
    printf("unsigned char : %zu octets\n", sizeof(unsigned char));
    printf("signed char : %zu octets\n\n", sizeof(signed char));

    // Types Entiers
    printf("short : %zu octets\n", sizeof(short));
    printf("unsigned short : %zu octets\n", sizeof(unsigned short));
    printf("signed short : %zu octets\n\n", sizeof(signed short));

    printf("int : %zu octets\n", sizeof(int));
    printf("unsigned int : %zu octets\n", sizeof(unsigned int));
    printf("signed int : %zu octets\n\n", sizeof(signed int));

    printf("long int : %zu octets\n", sizeof(long int));
    printf("unsigned long int : %zu octets\n", sizeof(unsigned long int));
    printf("signed long int : %zu octets\n\n", sizeof(signed long int));

    printf("long long int : %zu octets\n", sizeof(long long int));
    printf("unsigned long long int : %zu octets\n", sizeof(unsigned long long int));
    printf("signed long long int : %zu octets\n\n", sizeof(signed long long int));

    // Types Flottants (pas de unsigned/signed ici)
    printf("float : %zu octets\n", sizeof(float));
    printf("double : %zu octets\n", sizeof(double));
    printf("long double : %zu octets\n", sizeof(long double));

    return 0;
}
