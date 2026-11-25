#include "annee.h"
#include "csv.h"
#include <stdio.h>

void initialiser_tableau(DonneesAnnee* tab){
  for (int i = 0; i < 20; i++) {
        tab[i].nb_accidents = 0;
        for (int j = 0; j < 4; j++) {
            tab[i].gravite[j] = 0;
        }
    }
}


void afficher_stats_annee(DonneesAnnee* tab, int annee){
  for(int i=0; i<20; i++){
    printf("%d
}

void lancer_mode_annee(const char* chemin_fichier);
