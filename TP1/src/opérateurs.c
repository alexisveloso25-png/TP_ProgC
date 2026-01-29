#include <stdio.h>

int main() {
    int a = 16;
    int b = 3;

    printf("--- Opérations sur a = %d et b = %d ---\n\n", a, b);

    // --- Opérateurs Arithmétiques ---
    
    // Addition
    printf("Addition (a + b) : %d\n", a + b);

    // Soustraction
    printf("Soustraction (a - b) : %d\n", a - b);

    // Multiplication
    printf("Multiplication (a * b) : %d\n", a * b);

    // Division (Attention : division entière car a et b sont des int)
    printf("Division entière (a / b) : %d\n", a / b);

    // Modulo (Reste de la division)
    printf("Modulo (a %% b) : %d\n\n", a % b);


    // --- Opérateurs de Comparaison (Logiques) ---
    
    // Égalité
    // On affiche le résultat brut (0 ou 1)
    printf("Est-ce que a == b ? %d (0 = faux, 1 = vrai)\n", a == b);

    // Supériorité
    printf("Est-ce que a > b ? %d (0 = faux, 1 = vrai)\n", a > b);

    return 0;
}


