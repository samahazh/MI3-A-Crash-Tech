#ifndef ANNEE_H
#define ANNEE_H

typedef struct {
    int nb_accidents;
    int gravite[4];
} DonneesAnnee;

void initialiser_tableau(DonneesAnnee* tab);
void afficher_stats_annee(DonneesAnnee* tab, int annee);
void lancer_mode_annee(const char* chemin_fichier);

#endif
