#include "csv.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

FILE* ouvrir_fichier_csv(const char* nom_fichier) {
    FILE* f = fopen(nom_fichier, "r");

    if (f == NULL) {
        printf("Erreur : impossible d'ouvrir le fichier %s\n", nom_fichier);
        exit(1);
    }

    return f;
}

int lire_ligne_csv(FILE* fichier, DonneesLigne* donnee) {
    char ligne[256];

    // Lecture ligne par ligne jusqu'à en trouver une valide (ou arriver à la fin)
    while (fgets(ligne, sizeof(ligne), fichier) != NULL) {
        // Remplacer les sauts de ligne par '\0'
        ligne[strcspn(ligne, "\r\n")] = '\0';

        // Si on rencontre l'en-tête ou une ligne vide, on passe à la suivante
        if (strncmp(ligne, "year", 4) == 0 || strlen(ligne) == 0) {
            continue;
        }

        // Extraction des 9 données nécessaires
        int resultat = sscanf(ligne, "%d;%d;%15[^;];%d;%d;%d;%d;%d;%d",
                              &(donnee->annee),
                              &(donnee->id_accident),
                              donnee->id_vehicule,
                              &(donnee->emplacement),
                              &(donnee->type_usager),
                              &(donnee->gravite),
                              &(donnee->genre),
                              &(donnee->annee_naissance),
                              &(donnee->motif));

        // Si les 9 données nécessaires ont été extraites, on retourne 1
        if (resultat == 9) {
            return 1;
        }
    }

    return 0; // Fin du fichier
}
