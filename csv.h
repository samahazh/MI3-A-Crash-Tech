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
} LigneCSV;

// YEAR_DATA
typedef struct {
    int nb_accidents;
    int gravite[4];
} StatsAnnee;


