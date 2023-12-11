#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void fromParkingToTaxis(Parking **p, Taxis **t, Avion *a, int categorie)
{
    while ((*t)->numero != categorie)
    {
        *t = (*t)->suivant;
    }

    if ((*t)->nbAvions < (*t)->capacite)
    {
        (*t)->nbAvions++;
        while ((*p)->numero != categorie)
        {
            *p = (*p)->suivant;
        }
        ajouteEnFin(&(*t)->premier, a);
        supprimeAvion(&(*p)->premier, a->identifiant);
        (*p)->nbAvions--;
    }
}

void testParkingToTaxis(Parking **p, Taxis **t, int timeG)
{
    for (int i = 1; i < 4; i++)
    {
        Avion *actuel = malloc(sizeof(*actuel));
        actuel = rechercheParTempsParking(*p, i, timeG);
        if (actuel != NULL)
        {
            fromParkingToTaxis(p, t, actuel, i);
        }
    }
}

//___________________________________________________________________________________________

void fromTaxisToPiste(Taxis **t, Piste **p, int categorie)
{
    if ((*t)->premier == NULL)
    {
        return;
    }

    while ((*p)->numero != categorie)
    {
        *p = (*p)->suivant;
    }
    while ((*t)->numero != categorie)
    {
        *t = (*t)->suivant;
    }

    if ((*p)->premier == NULL && (*t)->nbAvions < (*t)->capacite && (*t)->premier != NULL)
    {
        ajouteEnFin(&(*p)->premier, (*t)->premier);
        supprimeEnTete(&(*t)->premier);
        (*t)->nbAvions--;
    }
}

void testTaxisToPiste(Taxis **t, Piste **p)
{
    for (int i = 1; i < 4; i++)
    {
        if ((*t)->premier == NULL)
        {
            fromTaxisToPiste(t, p, i);
        }
    }
}

//___________________________________________________________________________________________

void decollage(Piste **p, EnVol **e, int categorie, int timeG)
{
    Piste *actuel = malloc(sizeof(*actuel));
    actuel = *p;
    while (actuel->numero != categorie)
    {
        actuel = actuel->suivant;
    }
    if (actuel->premier != NULL)
    {
        actuel->premier->time = timeG + 20;
        switch (categorie)
        {
        case 1:
            ajouteEnFin(&(*e)->premierG, actuel->premier);
            supprimeAvion(&(*p)->premier, actuel->premier->identifiant);
            (*e)->nbAvions++;
            break;

        case 2:
            ajouteEnFin(&(*e)->premierM, actuel->premier);
            supprimeAvion(&(*p)->premier, actuel->premier->identifiant);
            (*e)->nbAvions++;
            break;

        case 3:
            ajouteEnFin(&(*e)->premierP, actuel->premier);
            supprimeAvion(&(*p)->premier, actuel->premier->identifiant);
            (*e)->nbAvions++;

            break;

        default:
            break;
        }
    }
}

int testDecollage(Piste **p, EnVol **e, int timeG)
{
    for (int i = 1; i < 4; i++)
    {
        decollage(p, e, i, timeG);
    }
    return 0;
}

//___________________________________________________________________________________________

void atterissage(Piste **p, EnVol **e, Avion *a, int categorie)
{
    while ((*p)->numero != categorie)
    {
        *p = (*p)->suivant;
    }

    switch (categorie)
    {
    case 1:
        ajouteEnFin(&(*p)->premier, a);
        supprimeAvion(&(*e)->premierG, a->identifiant);
        (*e)->nbAvions--;
        break;

    case 2:
        ajouteEnFin(&(*p)->premier, a);
        supprimeAvion(&(*e)->premierG, a->identifiant);
        (*e)->nbAvions--;
        break;

    case 3:
        ajouteEnFin(&(*p)->premier, a);
        supprimeAvion(&(*e)->premierG, a->identifiant);
        (*e)->nbAvions--;
        break;

    default:
        break;
    }
}

void testAtterissage(Parking **p, Piste **pi, EnVol **e, int timeG)
{
    if (((*p)->nbAvions < (*p)->capacite) && (*pi)->premier != NULL)
    {
        for (int i = 1; i < 4; i++)
        {
            Avion *actuel = malloc(sizeof(*actuel));
            actuel = rechercheParTempsEnVol(*e, i, timeG);
            if (actuel != NULL)
            {
                atterissage(pi, e, actuel, i);
            }
        }
    }
}

//___________________________________________________________________________________________

void fromPisteToParking(Piste **p, Parking **park, int categorie, int timeG)
{
    Piste *actuel = malloc(sizeof(*actuel));
    actuel = *p;
    while (actuel->numero != categorie)
    {
        actuel = actuel->suivant;
    }
    if (actuel->premier != NULL)
    {
        actuel->premier->time = timeG + 20;
        if ((*park)->nbAvions < (*park)->capacite)
        {
            Parking *actuel2 = malloc(sizeof(*actuel2));
            actuel2 = *park;
            while (actuel2->numero != categorie)
            {
                actuel2 = actuel2->suivant;
            }
            ajouteEnFin(&actuel2->premier, actuel->premier);
            supprimeEnTete(&actuel->premier);
            actuel2->nbAvions++;
            *p = actuel;
            *park = actuel2;
        }
    }
}

//___________________________________________________________________________________________

void boucleMoteur(Parking **p, Taxis **t, Piste **pi, EnVol **e, int timeG)
{
    testParkingToTaxis(p, t, timeG);
    testTaxisToPiste(t, pi);
    testDecollage(pi, e, timeG);
    testAtterissage(p, pi, e, timeG);
    for (int i = 1; i < 4; i++)
    {
        fromPisteToParking(pi, p, i, timeG);
    }
    sauvegardeBdd(*e, *p, *t, *pi, timeG);
}
