typedef struct Victime {
    int age;
    int type_usager;
    int genre;
    int gravite;
    struct Victime* suivant;
} DonneesVictime;

typedef struct Vehicule {
    char id_vehicule[16];
    int motif;
    DonneesVictime* liste_victimes;
    struct Vehicule* suivant;
} DonneesVehicule;

typedef struct Accident {
    long long cle;
    DonneesVehicule* liste_vehicules;
    struct Accident* gauche;
    struct Accident* droite;
    int equilibre;
} DonneesAccident;
