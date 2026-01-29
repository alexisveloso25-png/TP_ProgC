#include <stdio.h>

int main() {
    // 1. Déclaration et assignation
    int a = 2;
    int b = 3;
    
    // 2. Variable pour stocker le résultat
    // On l'initialise à 1 (élément neutre de la multiplication)
    long long resultat = 1; 

    // 3. Calcul de la puissance avec une boucle for
    // On multiplie le résultat par 'a', 'b' fois de suite
    for (int i = 0; i < b; i++) {
        resultat = resultat * a;
    }

    // 4. Affichage du résultat
    printf("%d eleve a la puissance %d est egal a : %lld\n", a, b, resultat);

    return 0;
}
