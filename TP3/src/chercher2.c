#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // 1. Tableau de 10 phrases liées au groupe
    char *phrases[10] = {
        "Alexis est en train de coder sur VS Code.",
        "Salmane prefere utiliser le terminal Linux.",
        "Kais a trouve la solution de l'exercice.",
        "Mohamed explique les pointeurs a ses amis.",
        "Le groupe travaille sur le TP de programmation C.",
        "Alexis propose une pause cafe.",
        "Salmane a fini son script avant tout le monde.",
        "Kais verifie si le tableau est bien trie.",
        "Mohamed a oublie un point-virgule dans son code.",
        "Le projet ProgC avance tres bien."
    };

    srand(time(NULL)); // Initialisation de l'aleatoire

    // 2. Choix dynamique de la cible
    char *cible;
    int mode = rand() % 2; // 0 ou 1

    if (mode == 0) {
        // On choisit une phrase qui existe au hasard dans le tableau
        int index_aleatoire = rand() % 10;
        cible = phrases[index_aleatoire];
    } else {
        // On choisit une phrase qui n'existe pas
        cible = "L'ordinateur de Kais a plante.";
    }

    printf("--- Test de recherche dynamique ---\n");
    printf("Phrase recherchee : \"%s\"\n\n", cible);

    int phrase_trouvee = 0;

    // 3. Boucle de recherche à travers le tableau
    for (int i = 0; i < 10; i++) {
        char *phrase_actuelle = phrases[i];
        int j = 0;
        int identique = 1;

        // Comparaison manuelle caractere par caractere
        // On continue tant que l'une des deux n'est pas terminee par '\0'
        while (phrase_actuelle[j] != '\0' || cible[j] != '\0') {
            if (phrase_actuelle[j] != cible[j]) {
                identique = 0;
                break;
            }
            j++;
        }

        if (identique) {
            phrase_trouvee = 1;
            break; 
        }
    }

    // 4. Affichage du resultat
    if (phrase_trouvee) {
        printf("Resultat : Phrase trouvee\n");
    } else {
        printf("Resultat : Phrase non trouvee\n");
    }

    return 0;
}
