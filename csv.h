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

typedef struct {
    int nb_accidents;
    int nb_indemnes;
    int nb_tues;
    int nb_blesses_graves;
    int nb_blesses_legers;
} StatsAnnee;

typedef struct{

    


