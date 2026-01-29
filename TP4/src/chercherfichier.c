#include <stdio.h>
#include <string.h>

void exercice_4_6(char *nom_fichier) {
    FILE *f = fopen(nom_fichier, "r");
    if (!f) {
        printf("Fichier introuvable.\n");
        return;
    }
    
    char phrase[100];
    char ligne[256];
    int num_ligne = 0;

    printf("Entrez la phrase a rechercher : ");
    getchar(); // vider buffer
    fgets(phrase, 100, stdin);
    phrase[strcspn(phrase, "\n")] = 0;

    printf("\nResultats de la recherche :\n");
    while (fgets(ligne, sizeof(ligne), f)) {
        num_ligne++;
        int count = 0;
        char *ptr = ligne;
        while ((ptr = strstr(ptr, phrase)) != NULL) {
            count++;
            ptr += strlen(phrase);
        }
        if (count > 0) {
            printf("Ligne %d, %d fois\n", num_ligne, count);
        }
    }
    fclose(f);
}
