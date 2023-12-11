#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void init(Parking **p, Piste **pi, Taxis **t)
{
    initParking(p);
    initPiste(pi);
    initTaxis(t);
}

void initTaxis(Taxis **t)
{
    int capG = 3;
    int capM = 5;
    int capP = 7;
    for (int i = 0; i < 3; i++)
    {
        Taxis *new = malloc(sizeof(Taxis));
        new->numero = i + 1;
        switch (i)
        {
        case 0:
            new->capacite = capG;
            break;

        case 1:
            new->capacite = capM;
            break;

        case 2:
            new->capacite = capP;
            break;

        default:
            break;
        }
        new->nbAvions = 0;
        new->premier = NULL;
        new->suivant = *t;
        *t = new;
    }
}

void initPiste(Piste **p)
{
    for (int i = 0; i < 3; i++)
    {
        Piste *new = malloc(sizeof(Piste));
        new->numero = i + 1;
        new->premier = NULL;
        new->suivant = *p;
    }
}

void initParking(Parking **p)
{
    int cap = 7;

    for (int i = 0; i < 3; i++)
    {
        Parking *new = malloc(sizeof(Parking));
        new->numero = i + 1;
        new->capacite = cap;
        new->nbAvions = 0;
        new->premier = NULL;
        new->suivant = *p;
        *p = new;
    }
}