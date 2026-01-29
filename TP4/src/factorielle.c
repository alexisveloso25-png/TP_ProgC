#include <stdio.h>
int factorielle(int n) {
    if (n <= 0) return 1;
    int res = n * factorielle(n - 1);
    printf("\x1B[30;1m  -> Calcul de %d! en cours...\x1B[0m\n", n);
    return res;
}
