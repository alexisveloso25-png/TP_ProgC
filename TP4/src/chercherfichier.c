#include <stdio.h>
#include <string.h>
void exercice_4_6(char *fn) {
    FILE *f = fopen(fn, "r");
    if (!f) return;
    char p[100], l[256];
    printf("\n\x1B[35mRECHERCHE DANS LE FICHIER : %s\x1B[0m\n", fn);
    printf("Entrez le mot ou phrase à chercher : ");
    getchar(); fgets(p, 100, stdin); p[strcspn(p, "\n")] = 0;
    
    int nl = 0;
    while (fgets(l, sizeof(l), f)) {
        nl++; char *ptr = l; int count = 0;
        while ((ptr = strstr(ptr, p))) { count++; ptr += strlen(p); }
        if (count > 0) printf("\x1B[32m[Trouvé]\x1B[0m Ligne %d : %d occurrence(s)\n", nl, count);
    }
    fclose(f);
}
