#ifndef CSV_H
#define CSV_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int annee;
    char id_accident[16];
    char id_vehicule[16];
    int emplacement;
    int type_usager;
    int gravite;
    int genre;
    int annee_naissance;
    int motif;
} DonneesLigne;

FILE* ouvrir_fichier_csv(const char* chemin);
int lire_ligne_csv(FILE* fichier, DonneesLigne* donnee);

#endif
