#include "BDD.h"
#include "initStruct.h"
#include "Structures.h"
#include "includeGlobal.h"

void atterissage(EnVol **e, Piste **pi, Parking *p, int categorie, int timeG, int id)
{
    if (id != 0)
    {
        switch (categorie)
        {
        case 1:
            if (p->capacite > compteAvion(p->premierG))
            {
                ajouteEnFinParId(&p->premierG, (*e)->premierG, timeG, id);
                supprimeAvion(&(*e)->premierG, id);
                printf("AvionG vient d'atterir\n");
                (*e)->nbAvions--;
            }
            break;
        case 2:
            if (p->capacite > compteAvion(p->premierM))
            {
                ajouteEnFinParId(&p->premierM, (*e)->premierM, timeG, id);
                supprimeAvion(&(*e)->premierM, id);
                printf("AvionM vient d'atterir\n");
                (*e)->nbAvions--;
            }
            break;
        case 3:
            if (p->capacite > compteAvion(p->premierP))
            {
                ajouteEnFinParId(&p->premierP, (*e)->premierP, timeG, id);
                supprimeAvion(&(*e)->premierP, id);
                printf("AvionP vient d'atterir\n");
                (*e)->nbAvions--;
            }
            break;
        default:
            break;
        }
    }
}

void testAtterissage(EnVol **e, Piste **pi, Parking *p, int timeG)
{
    for (int i = 0; i < 3; i++)
    {
        int *time = malloc(sizeof(int));
        switch (i)
        {
        case 0:
            if ((*e)->premierG != NULL)
            {
                int id = rechercheParTemps((*e)->premierG, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    atterissage(e, pi, p, 1, timeG, id);
                }
            }
            break;
        case 1:
            if ((*e)->premierM != NULL)
            {
                int id = rechercheParTemps((*e)->premierM, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    atterissage(e, pi, p, 2, timeG, id);
                }
            }
            break;
        case 2:
            if ((*e)->premierP != NULL)
            {
                int id = rechercheParTemps((*e)->premierP, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    atterissage(e, pi, p, 3, timeG, id);
                }
            }
            break;
        default:
            break;
        }
    }
}

//_______________________________________________________________________________________________________________________//

void decollage(Piste **pi, EnVol **e, int timeG)
{
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            if ((*pi)->premierG != NULL)
            {
                (*pi)->premierG->time = timeG + ATTENTE;
                ajouteEnFin(&(*e)->premierG, (*pi)->premierG);
                supprimeEnTete(&(*pi)->premierG);
                printf("AvionG qui passe en vol\n");
                (*e)->nbAvions++;
            }
            break;
        case 1:
            if ((*pi)->premierM != NULL)
            {
                (*pi)->premierM->time = timeG + ATTENTE;
                ajouteEnFin(&(*e)->premierM, (*pi)->premierM);
                supprimeEnTete(&(*pi)->premierM);
                printf("AvionM qui passe en vol\n");
                (*e)->nbAvions++;
            }
            break;
        case 2:
            if ((*pi)->premierP != NULL)
            {
                (*pi)->premierP->time = timeG + ATTENTE;
                ajouteEnFin(&(*e)->premierP, (*pi)->premierP);
                supprimeEnTete(&(*pi)->premierP);
                printf("AvionP qui passe en vol\n");
                (*e)->nbAvions++;
            }
            break;
        default:
            break;
        }
    }
}

//_______________________________________________________________________________________________________________________//

void fromParkingToTaxis(Parking **p, Taxis **t, int timeG, int categorie, int id)
{
    if (id != 0)
    {
        switch (categorie)
        {
        case 1:
            if ((*t)->capaciteG > compteAvion((*t)->premierG))
            {
                ajouteEnFinParId(&(*t)->premierG, (*p)->premierG, timeG, id);
                supprimeAvion(&(*p)->premierG, id);
                printf("AvionG qui passe au Taxis\n");
            }
            break;
        case 2:
            if ((*t)->capaciteM > compteAvion((*t)->premierM))
            {
                ajouteEnFinParId(&(*t)->premierM, (*p)->premierM, timeG, id);
                supprimeAvion(&(*p)->premierM, id);
                printf("AvionM qui passe au Taxis\n");
            }
            break;
        case 3:
            if ((*t)->capaciteP > compteAvion((*t)->premierP))
            {
                ajouteEnFinParId(&(*t)->premierP, (*p)->premierP, timeG, id);
                supprimeAvion(&(*p)->premierP, id);
                printf("AvionP qui passe au Taxis\n");
            }
            break;
        default:
            break;
        }
    }
}

void testFromParkingToTaxis(Parking **p, Taxis **t, int timeG)
{
    for (int i = 0; i < 3; i++)
    {
        int *time = malloc(sizeof(int));
        switch (i)
        {
        case 0:
            if ((*p)->premierG != NULL)
            {
                int id = rechercheParTemps((*p)->premierG, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    fromParkingToTaxis(p, t, timeG, 1, id);
                }
            }
            break;
        case 1:
            if ((*p)->premierM != NULL)
            {
                int id = rechercheParTemps((*p)->premierM, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    fromParkingToTaxis(p, t, timeG, 2, id);
                }
            }
            break;
        case 2:
            if ((*p)->premierP != NULL)
            {
                int id = rechercheParTemps((*p)->premierP, timeG, &time);
                if (*time <= timeG && id != 0)
                {
                    fromParkingToTaxis(p, t, timeG, 3, id);
                }
            }
            break;
        default:
            break;
        }
    }
}

//_______________________________________________________________________________________________________________________//

void fromTaxisToPiste(Taxis **t, Piste **pi)
{
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            if ((*t)->premierG != NULL && (*pi)->premierG == NULL)
            {
                ajouteEnFin(&(*pi)->premierG, (*t)->premierG);
                supprimeEnTete(&(*t)->premierG);
                printf("AvionG qui passe en piste pour décoller\n");
            }
            break;
        case 1:
            if ((*t)->premierM != NULL && (*pi)->premierM == NULL)
            {
                ajouteEnFin(&(*pi)->premierM, (*t)->premierM);
                supprimeEnTete(&(*t)->premierM);
                printf("AvionM qui passe en piste pour décoller\n");
            }
            break;
        case 2:
            if ((*t)->premierP != NULL && (*pi)->premierP == NULL)
            {
                ajouteEnFin(&(*pi)->premierP, (*t)->premierP);
                supprimeEnTete(&(*t)->premierP);
                printf("AvionP qui passe en piste pour décoller\n");
            }
            break;
        default:
            break;
        }
    }
}

//_______________________________________________________________________________________________________________________//

void fromPisteToParking(Piste **pi, Parking **p, int timeG)
{
    for (int i = 0; i < 3; i++)
    {
        switch (i)
        {
        case 0:
            if ((*pi)->premierG != NULL)
            {
                (*pi)->premierG->time = timeG + ATTENTE;
                ajouteEnFin(&(*p)->premierG, (*pi)->premierG);
                supprimeEnTete(&(*pi)->premierG);
                printf("AvionG qui passe au Parking\n");
            }
            break;
        case 1:
            if ((*pi)->premierM != NULL)
            {
                (*pi)->premierM->time = timeG + ATTENTE;
                ajouteEnFin(&(*p)->premierM, (*pi)->premierM);
                supprimeEnTete(&(*pi)->premierM);
                printf("AvionM qui passe au Parking\n");
            }
            break;
        case 2:
            if ((*pi)->premierP != NULL)
            {
                (*pi)->premierP->time = timeG + ATTENTE;
                ajouteEnFin(&(*p)->premierP, (*pi)->premierP);
                supprimeEnTete(&(*pi)->premierP);
                printf("AvionP qui passe au Parking\n");
            }
            break;
        default:
            break;
        }
    }
    
}

//_______________________________________________________________________________________________________________________//

void boucleMoteur(EnVol **e, Piste **pi, Parking **p, Taxis **t, int timeG)
{
    decollage(pi, e, timeG);
    fromTaxisToPiste(t, pi);
    testAtterissage(e, pi, *p, timeG);
    fromPisteToParking(pi, p, timeG);
    testFromParkingToTaxis(p, t, timeG);
    
    
}
