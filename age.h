typedef struct Age {
    int age;
    int genre[3];
    int type_usager[3];
    struct Age* suivant;
} DonneesAge;

DonneesAge* creer_chainon_age(int age);
DonneesAge* inserer_ou_maj_age(DonneesAge* tete, int age, int genre, int type_usager);
void afficher_pyramide(DonneesAge* tete, int choix_stat);
void liberer_liste_age(DonneesAge* tete);
void lancer_mode_age(const char* chemin_fichier);
