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

void lancer_mode_annee(const char* chemin_fichier){
  //Ouvrir le fichier avec les données
  FILE* fichier = ouvrir_fichier_csv(chemin_fichier);

  DonneesAnnee annees[20];
  initialiser_tableau(annees);

  DonneesLigne ligne;
}


void afficher_stats_annee(DonneesAnnee* tab, int annee){
  int index = annee - 2005;

  printf("\n=== Statistiques pour l'annee %d ===\n", annee);
  printf("Nombre total d'enregistrements/victimes : %d\n", tab[index].nb_accidents);
  printf("  - Indemnes (1)       : %d\n", tab[index].gravite[0]);
  printf("  - Tues (2)           : %d\n", tab[index].gravite[1]);
  printf("  - Blesses graves (3) : %d\n", tab[index].gravite[2]);
  printf("  - Blesses legers (4) : %d\n", tab[index].gravite[3]);
}
