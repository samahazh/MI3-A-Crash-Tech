#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int annee;
    int id_accident;
    char id_vehicule[16];
    int emplacement;
    int type_usager;
    int gravite;
    int genre;
    int annee_naissance;
    int motif;
} DonneesLignes;

int charger_donnees_csv(const char *nom_fichier, void *structure_donnees, const char *mode);

#endif
