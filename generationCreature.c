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

int main() {
    srand(time(NULL));
    char nom_creature[30];
    printf("Entrez le nom de la creature (Meduse, Poisson-Epee, Requin, Kraken, CrabeGeant): ");
    scanf("%29s", nom_creature);

    if (!est_nom_valide(nom_creature)) {
        printf("Nom invalide ! La creature n'a pas ete creee\n");
        return 1; 
    }

    CreatureMarine mob = cree_creature(nom_creature);

    printf("%s (PV: %d, ATK: %d-%d, DEF: %d, VITESSE: %d, EFFET_SPECIAL: %s)\n",
           mob.nom,
           mob.points_de_vie_max,
           mob.attaque_minimale,
           mob.attaque_maximale,
           mob.defense,
           mob.vitesse,
           mob.effet_special);

    return 0;
}
