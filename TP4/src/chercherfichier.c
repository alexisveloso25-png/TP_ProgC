#include <stdio.h>
#include <string.h>

void exercice_4_6(char *nom_f) {
    FILE *f = fopen(nom_f, "r");
    if (!f) { printf("Fichier introuvable.\n"); return; }
    char p[100], l[256];
    printf("Phrase a chercher : "); getchar();
    fgets(p, 100, stdin);
    p[strcspn(p, "\n")] = 0;
    int nl = 0;
    while (fgets(l, sizeof(l), f)) {
        nl++;
        char *ptr = l; int c = 0;
        while ((ptr = strstr(ptr, p))) { c++; ptr += strlen(p); }
        if (c > 0) printf("Ligne %d, %d fois\n", nl, c);
    }
    fclose(f);
}
