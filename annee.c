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
  int dernier_id = -1;
  int derniere_annee = -1;


  // Lit toutes les lignes du CSV une par une
    while (lire_ligne_csv(fichier, &ligne) == 1) {
        // Vérifier que l'année est bien dans l'intervalle [2005, 2024]
        if (ligne.annee >= 2005 && ligne.annee <= 2024) {
            int index = ligne.annee - 2005;
            
            // Compte un nouvel accident uniquement quand l'ID ou l'année change
            if(ligne.id_accident != dernier_id || ligne.annee != derniere_annee){
               annees[index].nb_accidents++;
               dernier_id = ligne.id_accident;
               derniere_annee = ligne.annee;
             }
            // La gravité va de 1 à 4. On gère l'indice du tableau (0 à 3)
            if (ligne.gravite >= 1 && ligne.gravite <= 4) {
                annees[index].gravite[ligne.gravite - 1]++;
            }
        }
    }
fclose(fichier);

int choix = -1;
    while (choix != 0) {
        printf("\nEntrez une annee entre 2005 et 2024 (0 pour quitter) : ");
        if (scanf("%d", &choix) != 1) {
            printf("Erreur : saisie invalide.\n");
            return;
        }

        if (choix >= 2005 && choix <= 2024) {
            afficher_stats_annee(annees, choix);
        } else if (choix != 0) {
            printf("Erreur : annee hors intervalle [2005, 2024].\n");
        }
    }
}

void afficher_stats_annee(DonneesAnnee* tab, int annee){
  int index = annee - 2005;

  printf("\n=== Statistiques pour l'annee %d ===\n", annee);

  printf("Nombre total d'accidents : %d\n", tab[index].nb_accidents);
  printf("  - Indemnes (1)       : %d\n", tab[index].gravite[0]);
  printf("  - Tues (2)           : %d\n", tab[index].gravite[1]);
  printf("  - Blesses graves (3) : %d\n", tab[index].gravite[2]);
  printf("  - Blesses legers (4) : %d\n", tab[index].gravite[3]);
}

