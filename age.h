typedef struct ChainonAge {
    int age;
    int genre[3];
    int type_usager[3];
    struct ChainonAge* suivant;
} ChainonAge;
