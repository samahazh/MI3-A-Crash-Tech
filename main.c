#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "annee.h"
#include "age.h"
#include "accident.h"
#include "csv.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        printf("Usage : %s <MODE> <fichier.csv>\n", argv[0]);
        printf("Modes disponibles : YEAR_DATA, AGE_DATA, CRASH_DATA\n");
        return 1;
    }

    if (strcmp(argv[1], "YEAR_DATA") == 0) {
        lancer_mode_annee(argv[2]);
    } else if (strcmp(argv[1], "AGE_DATA") == 0) {
        lancer_mode_age(argv[2]);
    } else if (strcmp(argv[1], "CRASH_DATA") == 0) {
        lancer_mode_accident(argv[2]);
    } else {
        printf("Erreur : mode inconnu (%s)\n", argv[1]);
        printf("Modes disponibles : YEAR_DATA, AGE_DATA, CRASH_DATA\n");
        return 1;
    }

    return 0;
}
