#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
    int id;
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20];
    int est_vivant;
} CreatureMarine;

int est_nom_valide(const char *nom) {
    const char *noms_valides[] = {
        "Meduse", "Poisson-Epee", "Requin", "Kraken", "CrabeGeant"
    };
    int nb_noms = sizeof(noms_valides)/sizeof(noms_valides[0]);
    for (int i = 0; i < nb_noms; i++) {
        if (strcmp(nom, noms_valides[i]) == 0) {
            return 1; 
        }
    }
    return 0;
}

CreatureMarine cree_creature(const char *nom) {
    CreatureMarine c;
    c.est_vivant = 1;
    c.id = 0;

    strcpy(c.nom, nom);

    // On adapte les stats selon le nom
    if (strcmp(nom, "Meduse") == 0) {
        c.points_de_vie_max = rand() % 21 + 20;
        c.attaque_minimale = 8;
        c.attaque_maximale = 15;
        c.vitesse = 4;
    }
    else if (strcmp(nom, "Poisson-Epee") == 0) {
        c.points_de_vie_max = rand() % 21 + 70;
        c.attaque_minimale = 18;
        c.attaque_maximale = 28;
        c.vitesse = 3;
    }
    else if (strcmp(nom, "Requin") == 0) {
        c.points_de_vie_max = rand() % 41 + 60;
        c.attaque_minimale = 15;
        c.attaque_maximale = 25;
        c.vitesse = 5;
    }
    else if (strcmp(nom, "Kraken") == 0) {
        c.points_de_vie_max = rand() % 61 + 120;
        c.attaque_minimale = 25;
        c.attaque_maximale = 40;
        c.vitesse = 2;
    }
    else if (strcmp(nom, "CrabeGeant") == 0) {
        c.points_de_vie_max = rand() % 41 + 80;
        c.attaque_minimale = 12;
        c.attaque_maximale = 20;
        c.vitesse = 1;
    }

    c.points_de_vie_actuels = c.points_de_vie_max;
    c.defense = 5;
    strcpy(c.effet_special, "Aucun");

    return c;
}

CreatureMarine *cree_creatures(int Profondeur){

    const char *listes_creatures[] = {"Meduse", "Poisson-Epee", "Requin", "Kraken", "CrabeGeant"};
    int nbr_mobs;
    double dificulte;
    int random_number;
    char nom[30];
    
    if (Profondeur == 1){
        // combat 1v1
        nbr_mobs = 1;
        dificulte = 0.2;
    
    }else if(Profondeur == 2){
        // combat 1v2
        nbr_mobs = 2;
        dificulte = 0.4;
    }else if (Profondeur >=3){
        // combat 1v3
        nbr_mobs = 3;
        dificulte = 0.9;

    }
    
    CreatureMarine *creatures = malloc(sizeof(CreatureMarine) * (nbr_mobs));

    for (int i = 0; i < nbr_mobs; i++) {
        double r = (double)rand() / RAND_MAX;
        int random_number;

        if (r > dificulte) {
            // mob facile
            random_number = rand() % 2; // 0 or 1
            strcpy(nom, listes_creatures[random_number]);
        } else {
            // mob difficile
            random_number = 2 + rand() % 3; // 2, 3, 4
            strcpy(nom, listes_creatures[random_number]);
        }

        creatures[i] = cree_creature(nom);
    }
    return creatures;
}


int main() {
    srand(time(NULL));
    int profondeur = 3;// choisir ici la profondeur
    int nbr_mobs;

    CreatureMarine *creatures = cree_creatures(profondeur);
    
    if (profondeur == 1) {
        nbr_mobs = 1;
    }
    else if (profondeur == 2) {
        nbr_mobs = 2;
    }
    else {
        nbr_mobs = 3;
    }
    printf("=== Creatures generees pour Profondeur %d ===\n", profondeur);
    for (int i = 0; i < nbr_mobs; i++) {
        printf("%d - %s (PV: %d, ATK: %d-%d, DEF: %d, VITESSE: %d, EFFET_SPECIAL: %s)\n",
               i + 1,
               creatures[i].nom,
               creatures[i].points_de_vie_max,
               creatures[i].attaque_minimale,
               creatures[i].attaque_maximale,
               creatures[i].defense,
               creatures[i].vitesse,
               creatures[i].effet_special);
    }

    free(creatures); // libirer memoire
    return 0;

}
