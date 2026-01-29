#include <stdio.h>

int main() {
    // 1. Initialisation des chaînes
    char chaine1[50] = "Bonjour";
    char chaine2[] = " CNAM!";
    char copie[50];
    char concat[100];

    int i, j;

    // --- OPÉRATION 1 : Calculer la longueur de chaine1 ---
    int longueur = 0;
    while (chaine1[longueur] != '\0') {
        longueur++;
    }
    printf("1. Longueur de '%s' : %d\n", chaine1, longueur);


    // --- OPÉRATION 2 : Copier chaine1 dans 'copie' ---
    i = 0;
    while (chaine1[i] != '\0') {
        copie[i] = chaine1[i];
        i++;
    }
    copie[i] = '\0'; // Très important : ajouter le caractère nul à la fin
    printf("2. Copie reussie : '%s'\n", copie);


    // --- OPÉRATION 3 : Concaténer chaine1 et chaine2 dans 'concat' ---
    // Étape A : Copier la première chaîne dans le résultat
    i = 0;
    while (chaine1[i] != '\0') {
        concat[i] = chaine1[i];
        i++;
    }
    
    // Étape B : Ajouter la deuxième chaîne à la suite
    j = 0;
    while (chaine2[j] != '\0') {
        concat[i] = chaine2[j];
        i++;
        j++;
    }
    concat[i] = '\0'; // On ferme la chaîne concaténée
    printf("3. Concatenation : '%s'\n", concat);

    return 0;
}

