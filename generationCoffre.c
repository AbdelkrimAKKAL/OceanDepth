
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> // rand


typedef struct
{
    char nom[30];
    int rarete; // 0 = abimé | 1 = basique | 2 = peu commun | 3 = rare | 4 = legendaire | 5 = mythique
    int degats_min;
    int degats_max;
    int consomation; // conso d'02 par attaque
    int special;
} Arme;

typedef struct
{
    char nom[30];
    int rarete; // 0 = abimé | 1 = basique | 2 = peu commun | 3 = rare | 4 = legendaire | 5 = mythique
    int defense;
} Equipement; // Armure (combinaison)


int trouver_rarete(double rarete, int profondeur);
Arme GenererArme(int profondeur);
Equipement GenererEquipement(int profondeur);



int main()
{
    // Initialiser rand une seule fois
    srand(time(NULL));

    // Tester la génération d’armes
    for (int prof = 1; prof <= 5; prof++) {
        Arme a = GenererArme(prof);
        printf("Profondeur %d -> Arme: %s | Rarete=%d | Degats=[%d-%d] | Conso=%d | Special=%d\n",
               prof, a.nom, a.rarete, a.degats_min, a.degats_max, a.consomation, a.special);
    }

    printf("\n");
    
    

    // Tester la génération d’équipements
    for (int prof = 1; prof <= 5; prof++) {
        Equipement e = GenererEquipement(prof);
        printf("Profondeur %d -> Equipement: %s | Rarete=%d | Defense=%d\n",
               prof, e.nom, e.rarete, e.defense);
    }

    return 0;
}

Arme GenererArme(int Profondeur)
{
    // Determiner une rareté en fonction du niveau de prof
    double rarete; // Probabilité d'avoir un objet rare
    // {"abimé", "basique", "peu commun", "rare", "legendaire", "mythique"};
    Arme arme;

    if (Profondeur == 1){
        // Probabilité d'avoir un objet rare est de: 10%
        rarete = 0.1;
    }
    else if (Profondeur == 2){
        rarete = 0.3;
    }
    else if (Profondeur == 3){
        rarete = 0.5;
    }
    else if (Profondeur == 4){
        rarete = 0.8;
    }
    else if (Profondeur >= 5){
        rarete = 0.95;
    }
    
    int nom_rarete = trouver_rarete(rarete, Profondeur);

    if (nom_rarete == 0)
    {
        strcpy(arme.nom, "abime"); // on change le nom aprés
        arme.rarete = 0;
        arme.degats_min = 1;
        arme.degats_max = 5;
        arme.consomation = 1;
        arme.special = 0; // ??
        return arme;
    }
    else if (nom_rarete == 1)
    {
        strcpy(arme.nom, "basique");
        arme.rarete = 1;
        arme.degats_min = 5;
        arme.degats_max = 10;
        arme.consomation = 2;
        arme.special = 0;
        return arme;
    }
    else if (nom_rarete == 2)
    {
        strcpy(arme.nom, "peu commun");
        arme.rarete = 2;
        arme.degats_min = 10;
        arme.degats_max = 15;
        arme.consomation = 3;
        arme.special = 0;
        return arme;
    }
    else if (nom_rarete == 3)
    {
        strcpy(arme.nom, "rare");
        arme.rarete = 3;
        arme.degats_min = 15;
        arme.degats_max = 20;
        arme.consomation = 4;
        arme.special = 0;
        return arme;
    }
    else if (nom_rarete == 4)
    {
        strcpy(arme.nom, "legendaire");
        arme.rarete = 4;
        arme.degats_min = 20;
        arme.degats_max = 25;
        arme.consomation = 5;
        arme.special = 0;
        return arme;
    }
    else if (nom_rarete == 5)
    {
        strcpy(arme.nom, "mythique");
        arme.rarete = 5;
        arme.degats_min = 25;
        arme.degats_max = 30;
        arme.consomation = 6;
        arme.special = 0;
        return arme;
    }
}

Equipement GenererEquipement(int Profondeur)
{
    // Determiner une rareté en fonction du niveau de prof
    double rarete; // Probabilité d'avoir un objet rare

    // {"abimé", "basique", "peu commun", "rare", "legendaire", "mythique"};
    
    Equipement equipement;

    if (Profondeur == 1){
        // Probabilité d'avoir un objet rare est de: 10%
        rarete = 0.1;
    }
    else if (Profondeur == 2){
        rarete = 0.3;
    }
    else if (Profondeur == 3){
        rarete = 0.5;
    }
    else if (Profondeur == 4){
        rarete = 0.8;
    }
    else if (Profondeur >= 5){
        rarete = 0.95;
    }
    
    int nom_rarete = trouver_rarete(rarete, Profondeur);

    if (nom_rarete == 0){
        strcpy(equipement.nom, "equipement abime"); // on change le nom aprés
        equipement.rarete = 0;
        equipement.defense = 5;
        return equipement;
    }
    else if (nom_rarete == 1)
    {
        strcpy(equipement.nom, "equipement basique");
        equipement.rarete = 1;
        equipement.defense = 10;
        return equipement;
    }
    else if (nom_rarete == 2)
    {
        strcpy(equipement.nom, "equip peu commun");
        equipement.rarete = 2;
        equipement.defense = 15;
        return equipement;
    }
    else if (nom_rarete == 3)
    {
        strcpy(equipement.nom, "equip rare");
        equipement.rarete = 3;
        equipement.defense = 20;
        return equipement;
    }
    else if (nom_rarete == 4)
    {
        strcpy(equipement.nom, "equip legendaire");
        equipement.rarete = 4;
        equipement.defense = 25;
        return equipement;
    }
    else if (nom_rarete == 5)
    {
        strcpy(equipement.nom, "equip mythique");
        equipement.rarete = 5;
        equipement.defense = 30;
        return equipement;
    }
}

// trouver_rarete() retourne le type d'objet a generer basée sur la probabilite de la rarete
// 0 = abimé | 1 = basique | 2 = peu commun | 3 = rare | 4 = legendaire | 5 = mythique
int trouver_rarete(double rarete, int prof)
{   
    // rareté = [0.1, 0.3, 0.5, 0.8, 0.95] (probabilité d'avoir un objet rare dans les 5 NIVEAUX de profondeurs)
    // Générer un nombre entre 0 et 1
    double r = (double)rand() / RAND_MAX;

    if (r < rarete){
        //generer un objet rare (3 = rare | 4 = legendaire | 5 = mythique)

        double r1 = (double)rand() / RAND_MAX;
        // profondeur <= 3: probabilité d'avoir objet rare plus qu'un objet legendaire/mythique
        if(prof <= 3){
            if(r1 <= 0.5){
                return 3;
            }else if(r1 <= 0.85){
                return  4;
            }else{
                return 5;
            }
        // profondeur = 4: probabilité d'avoir objet legendaire plus qu'un objet rare/mythique
        }else if(prof == 4){
            if(r1 <= 0.5){
                return 4;
            }else if(r1 <= 0.85){
                return  3;
            }else{
                return 5;
            }
        // profondeur >= 5: probabilité d'avoir objet mythique plus qu'un objet rare/legendaire
        }else if(prof >=5){
            if(r1 <= 0.5){
                return 5;
            }else if(r1 <= 0.85){
                return  4;
            }else{
                return 3;
            }
        }
        
    }else{
        //generer un objet pas rare (0 = abimé | 1 = basique | 2 = peu commun)

        double r2 = (double)rand() / RAND_MAX;
        // profondeur = 1: probabilité d'avoir objet abime plus qu'un objet basique/peu commun
        if(prof == 1){
            if(r2 <= 0.5){
                return 0;
            }else if(r2 <= 0.85){
                return  1;
            }else{
                return 2;
            }
        // profondeur = 2: probabilité d'avoir objet basique plus qu'un objet abimé/peu commun
        }else if (prof == 2){
            if(r2 <= 0.5){
                return 1;
            }else if(r2 <= 0.85){
                return  0;
            }else{
                return 2;
            }
        // profondeur >= 3: probabilité d'avoir objet peu plus qu'un objet abimé/basique
        }else if(prof >= 3){
            if(r2 <= 0.5){
                return 2;
            }else if(r2 <= 0.85){
                return  1;
            }else{
                return 0;
            }
        }

        
        
    }

}