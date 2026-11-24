#ifndef ANNEE_H
#define ANNEE_H

typedef struct {
    int nb_accidents;
    int gravite[4];
} DonneesAnnee;

void lancer_mode_annee(const char* chemin_fichier);

#endif
