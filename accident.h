typedef struct Victime {
    int age;
    int type_usager;
    int genre;
    int gravite;
    struct Victime* suivant;
} Victime;

typedef struct Vehicule {
    char id_vehicule[16];
    int motif;
    Victime* liste_victimes;
    struct Vehicule* suivant;
} Vehicule;

typedef struct NoeudAVL {
    long long cle;
    Vehicule* liste_vehicules;
    struct NoeudAVL* gauche;
    struct NoeudAVL* droite;
    int equilibre;
} NoeudAVL;
