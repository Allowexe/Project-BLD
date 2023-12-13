#include "BDD.h"
#include "InitStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"


void init(Parking **p, Piste **pi, Taxis **t, EnVol **e)
{
    initParking(p);
    initPiste(pi);
    initTaxis(t);
    initEnVol(e);
}

void initTaxis(Taxis **t)
{
    int capG = 3;
    int capM = 5;
    int capP = 7;
    Taxis *new = malloc(sizeof(Taxis));
    new->capaciteG = capG;
    new->capaciteM = capM;
    new->capaciteP = capP;
    new->premierG = NULL;
    new->premierM = NULL;
    new->premierP = NULL;
    *t = new;
}

void initPiste(Piste **p)
{
    Piste *new = malloc(sizeof(Piste));
    new->premierG = NULL;
    new->premierM = NULL;
    new->premierP = NULL;
    *p = new;
}

void initParking(Parking **p)
{
    int cap = 7;
    Parking *new = malloc(sizeof(Parking));
    new->capacite = cap;
    new->premierG = NULL;
    new->premierM = NULL;
    new->premierP = NULL;
    *p = new;
}

void initEnVol(EnVol **e)
{
    EnVol *new = malloc(sizeof(EnVol));
    new->nbAvions = 0;
    new->premierG = NULL;
    new->premierM = NULL;
    new->premierP = NULL;
    *e = new;
}
