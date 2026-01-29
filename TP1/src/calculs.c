#include <stdio.h>

int main() {
    int somme = 0;
    int limite_somme = 5000;
    int i;

    for (i = 1; i <= 1000; i++) {
        // Condition 1 : Divisible par 11 ? On passe au suivant.
        // On utilise 'continue' pour sauter tout le reste du bloc for.
        if (i % 11 == 0) {
            continue;
        }

        // Condition 2 : Divisible par 5 OU par 7 ?
        if (i % 5 == 0 || i % 7 == 0) {
            somme += i;
        }

        // Condition 3 : Si la somme dépasse 5000, on arrête tout.
        if (somme > limite_somme) {
            printf("Arrêt : La somme a dépassé %d (i = %d)\n", limite_somme, i);
            break;
        }
    }

    printf("La somme finale est : %d\n", somme);

    return 0; 
}
#

