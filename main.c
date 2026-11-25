#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annee.h"
#include "age.h"
#include "accident.h"

int main(int argc, char* argv[]) { // Récupère ce que l'utilisateur tape dans le terminal au lancement du programme
    if (argc != 3) { 
        printf("Erreur : nombre d'arguments invalide.\n");
        printf("Commande attendue : %s <MODE> <fichier.csv>\n", argv[0]);
        printf("Modes disponibles : YEAR_DATA, AGE_DATA, CRASH_DATA\n");
        return 1;
    }

    // Lancement du mode donné (argv[1]) en lui transmettant le chemin du fichier CSV (argv[2])
    if (strcmp(argv[1], "YEAR_DATA") == 0) {
        lancer_mode_annee(argv[2]); // Lancement du mode YEAR_DATA
    } else if (strcmp(argv[1], "AGE_DATA") == 0) {
        lancer_mode_age(argv[2]); // Lancement du mode AGE_DATA
    } else if (strcmp(argv[1], "CRASH_DATA") == 0) {
        lancer_mode_accident(argv[2]); // Lancement du mode CRASH_DATA
    } else { 
        printf("Erreur : mode inconnu (%s)\n", argv[1]);
        printf("Modes disponibles : YEAR_DATA, AGE_DATA, CRASH_DATA\n");
        return 1;
    }

    return 0;
}
