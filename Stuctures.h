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
    Avion *suivant;
    Avion *precedent;
    int time;
};

struct stPiste
{
    int numero;
    Avion *premier;
    Piste *suivant;
};

struct stTaxis
{
    int numero;
    int capacite;
    int nbAvions;
    Avion *premier;
    Taxis *suivant;
};

struct stParking
{
    int numero;
    int capacite;
    int nbAvions;
    Avion *premier;
    Parking *suivant;
};

struct stEnVol
{
    int nbAvions;
    Avion *premierG;
    Avion *premierM;
    Avion *premierP;    
};


#endif // STRUCTURES_H