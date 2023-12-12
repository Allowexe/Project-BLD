#ifndef STRUCTURES_H
#define STRUCTURES_H

typedef struct stAvion Avion;
typedef struct stPiste Piste;
typedef struct stParking Parking;
typedef struct stTaxis Taxis;
typedef struct stEnVol EnVol;


struct stAvion
{
    int identifiant;
    int categorie; // 1: ligne, 2: affaire, 3: légers
    int etat;      // 0: au sol, 1: en vol
    int NbPassagers;
    int time;
    Avion *suivant;

};

struct stPiste
{
    Avion *premierG;
    Avion *premierM;
    Avion *premierP;
};

struct stTaxis
{
    int capaciteG;
    int capaciteM;
    int capaciteP;
    Avion *premierG;
    Avion *premierM;
    Avion *premierP;

};

struct stParking
{
    int capacite;
    Avion *premierG;
    Avion *premierM;
    Avion *premierP;
};

struct stEnVol
{
    int nbAvions;
    Avion *premierG;
    Avion *premierM;
    Avion *premierP;    
};


#endif // STRUCTURES_H
