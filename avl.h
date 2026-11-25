#ifndef AVL_H
#define AVL_H

#include "csv.h"

typedef struct Accident {
    long long cle;
    struct Vehicule* liste_vehicules;
    struct Accident* gauche;
    struct Accident* droite;
    int equilibre;
} DonneesAccident;

#endif
