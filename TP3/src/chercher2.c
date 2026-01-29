#include <stdio.h>

int main() {
    // 1. Tableau de 10 phrases personnalisées pour le groupe
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

    // Phrase à rechercher (exactement comme écrite dans le tableau)
    char *cible = "Kais verifie si le tableau est bien trie.";
    
    // Exemple de phrase qui n'existe pas
    // char *cible = "Alexis joue au foot."; 

    int phrase_trouvee = 0;

    printf("--- Recherche de phrase pour le groupe ---\n");
    printf("Cible : \"%s\"\n\n", cible);

    // 2. Parcourir le tableau de phrases
    for (int i = 0; i < 10; i++) {
        char *phrase_actuelle = phrases[i];
        int j = 0;
        int identique = 1;

        // 3. Comparaison manuelle (caractere par caractere)
        // On verifie jusqu'a la fin de l'une ou l'autre chaine ('\0')
        while (phrase_actuelle[j] != '\0' || cible[j] != '\0') {
            if (phrase_actuelle[j] != cible[j]) {
                identique = 0; // Difference detectee
                break;
            }
            j++;
        }

        if (identique) {
            phrase_trouvee = 1;
            break; 
        }
    }

    // 4. Affichage du resultat final
    if (phrase_trouvee) {
        printf("Resultat : Phrase trouvee\n");
    } else {
        printf("Resultat : Phrase non trouvee\n");
    }

    return 0;
}
