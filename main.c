x#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"

/*
 * Fonction qui lit une ligne du fichier CSV
 * et place chaque information dans la structure DonneesLignes.
 */
int lire_donnees_csv(FILE *fichier, DonneesLignes *donnees)
{
    char ligne[512];    // Tableau qui contient une ligne du fichier CSV
    char *colonne;      // Pointeur vers la colonne en cours de lecture

    /*
     * Lecture d'une ligne du fichier.
     * Si fgets retourne NULL, cela signifie que le fichier est terminé
     * ou qu'une erreur de lecture s'est produite.
     */
    if (fgets(ligne, sizeof(ligne), fichier) == NULL)
    {
        return 0;
    }

    /*
     * Récupération de l'année (première colonne).
     * strtok découpe la ligne à chaque point-virgule.
     */
    colonne = strtok(ligne, ";");

    if (colonne == NULL)
        return -1;

    donnees->annee = atoi(colonne);


    /*
     * Récupération de l'identifiant de l'accident (deuxième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    strcpy(donnees->id_accident, colonne);


    /*
     * Récupération de l'identifiant du véhicule (troisième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    strcpy(donnees->id_vehicule, colonne);


    /*
     * Récupération de l'emplacement de l'usager (quatrième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    donnees->emplacement = atoi(colonne);


    /*
     * Récupération du type d'usager (cinquième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    donnees->type_usager = atoi(colonne);


    /*
     * Récupération de la gravité de l'accident (sixième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    donnees->gravite = atoi(colonne);


    /*
     * Récupération du genre de l'usager (septième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    donnees->genre = atoi(colonne);


    /*
     * Récupération de l'année de naissance (huitième colonne).
     */
    colonne = strtok(NULL, ";");

    if (colonne == NULL)
        return -1;

    donnees->annee_naissance = atoi(colonne);


    /*
     * Récupération du motif du trajet (neuvième colonne).
     * On utilise ";\r\n" pour retirer également le retour à la ligne.
     */
    colonne = strtok(NULL, ";\r\n");

    if (colonne == NULL)
        return -1;

    donnees->motif = atoi(colonne);

    /*
     * Toutes les colonnes ont été récupérées.
     * La ligne est donc considérée comme lue.
     */
    return 1;
}
