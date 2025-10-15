#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_CREATURES 4


typedef struct {
    int id;  // identifiant unique pour cibler
    char nom[30];
    int points_de_vie_max;
    int points_de_vie_actuels;
    int attaque_minimale;
    int attaque_maximale;
    int defense;
    int vitesse;
    char effet_special[20]; // "paralysie", "poison", "aucun"
    int est_vivant;
} CreatureMarine;

CreatureMarine cree_creature(int id){
    CreatureMarine c;
    c.id = id;
    c.est_vivant = 1;

    switch (id)
    {
    case 1: 
        strcpy(c.nom, "Meduse"); 
        c.points_de_vie_max = rand()%21+20; c.points_de_vie_actuels = c.points_de_vie_max;
        c.attaque_minimale=8; c.attaque_maximale=15; c.defense=0; c.vitesse=0; 
        strcpy(c.effet_special,"Aucun"); //Paralysie
        break;
    case 2: 
        strcpy(c.nom, "Poisson-Epee"); 
        c.points_de_vie_max = rand()%21+70;c.points_de_vie_actuels = c.points_de_vie_max; c.attaque_minimale=18; 
        c.attaque_maximale=28; c.defense=0; c.vitesse=0; 
        strcpy(c.effet_special,"Aucun"); //Perforant
        break;
    case 3:
        strcpy(c.nom, "Requin");c.points_de_vie_max = rand()%41+60; 
        c.points_de_vie_actuels = c.points_de_vie_max;c.attaque_minimale=15; c.attaque_maximale=25; 
        c.defense=0; c.vitesse=0; 
        strcpy(c.effet_special,"Aucun");//Frenesie
        break;
    case 4: 
        strcpy(c.nom, "Kraken");
        c.points_de_vie_max = rand()%61+120; c.points_de_vie_actuels = c.points_de_vie_max;
        c.attaque_minimale = 25;c.attaque_maximale = 40;
        c.defense = 0;c.vitesse = 0;strcpy(c.effet_special, "Aucun");//Double_Attaque
        break;
    case 5: 
        strcpy(c.nom, "Crabe Geant"); 
        c.points_de_vie_max = rand()%41+80; c.points_de_vie_actuels = c.points_de_vie_max;c.attaque_minimale=12; 
        c.attaque_maximale=20; c.defense=0; 
        c.vitesse=0; strcpy(c.effet_special,"Aucun");//Carapace
        break;
    default: 
        strcpy(c.nom,"Inconnu"); c.points_de_vie_max=50; 
        c.attaque_minimale=10; c.attaque_maximale=15; 
        c.defense=0; c.vitesse=0; 
        strcpy(c.effet_special,"Aucun"); 
        break;
    }
    return c;   
}

int main() {
    srand(time(NULL));
    int nb;
    int profondeur = 3;

    CreatureMarine mob1 = cree_creature(3);
    printf("%s (ID: %d ,PV: %d, ATK: %d, DEF: %d, VITESSE: %d, EFFET_SPECIAL: %s)\n",
                    mob1.nom,
                    mob1.id,
                    mob1.points_de_vie_max,
                    mob1.attaque_maximale,
                    mob1.defense,
                    mob1.vitesse,
                    mob1.effet_special);

}