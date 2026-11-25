#include "csv.h"

FILE* ouvrir_fichier_csv(const char* nom_fichier){
    FILE* f = fopen(nom_fichier, "r");

    if(f==NULL){
        printf("Erreur: Impossible d'ouvrir le fichier %s\n", nom_fichier);
        exit(1);
    }

    return f;
}

int lire_ligne_csv(FILE* fichier, DonneesLigne* donnee) {
    char ligne[256];

    // Lecture de la ligne suivante dans le fichier
    if (fgets(ligne, sizeof(ligne), fichier) == NULL) {
        return 0; // Fin du fichier ou erreur
    }

    //Remplacer les sauts de ligne par '\0'
    ligne[strcspn(ligne, "\r\n")] = '\0';

    if (strncmp(ligne, "year", 4) == 0 || strlen(ligne) == 0) {
        return lire_ligne_csv(fichier, donnee); //Si on rencontre l'en-tête ou une ligne vide on fait un appel récursif pour lire la ligne en dessous
    }

    //Extraction des 9 données nécessaires.
    int resultat = sscanf(ligne, "%d;%15[^;];%15[^;];%d;%d;%d;%d;%d;%d",
                          &(donnee->annee),
                          donnee->id_accident,
                          donnee->id_vehicule,
                          &(donnee->emplacement),
                          &(donnee->type_usager),
                          &(donnee->gravite),
                          &(donnee->genre),
                          &(donnee->annee_naissance),
                          &(donnee->motif));

    //Si les 9 données nécessaires ont été extraites on retourn vrai
    if (resultat == 9) {
        return 1;
    }

    return 0;
}
