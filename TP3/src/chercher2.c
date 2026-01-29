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

    srand(time(NULL));

    // 2. Affichage de toutes les phrases (le "Tableau de base")
    printf("--- LISTE DES PHRASES DISPONIBLES ---\n");
    for (int i = 0; i < 10; i++) {
        printf("[%d] %s\n", i, phrases[i]);
    }
    printf("-------------------------------------\n\n");

    // 3. Choix dynamique de la cible
    char *cible;
    if (rand() % 2 == 0) {
        // Cas : La phrase existe
        cible = phrases[rand() % 10];
    } else {
        // Cas : La phrase est fausse
        cible = "L'ordinateur de Kais est en surchauffe.";
    }

    printf("RECHERCHE DE : \"%s\"\n", cible);

    // 4. Logique de recherche manuelle
    int phrase_trouvee = 0;
    for (int i = 0; i < 10; i++) {
        char *phrase_actuelle = phrases[i];
        int j = 0;
        int identique = 1;

        // Comparaison caractere par caractere sans strcmp
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

    // 5. Affichage du résultat final
    if (phrase_trouvee) {
        printf("\nRESULTAT : Phrase trouvee !\n");
    } else {
        printf("\nRESULTAT : Phrase non trouvee.\n");
    }

    return 0;
}
