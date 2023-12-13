#include "BDD.h"
#include "InitStruct.h"
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
                ajouteEnFinParId(&(*pi)->premierG, (*e)->premierG, timeG, id);
                supprimeAvion(&(*e)->premierG, id);
                printf("AvionG vient d'atterir\n");
            }
            break;
        case 2:
            if (p->capacite > compteAvion(p->premierM))
            {
                ajouteEnFinParId(&(*pi)->premierM, (*e)->premierM, timeG, id);
                supprimeAvion(&(*e)->premierM, id);
                printf("AvionM vient d'atterir\n");
            }
            break;
        case 3:
            if (p->capacite > compteAvion(p->premierP))
            {
                ajouteEnFinParId(&(*pi)->premierP, (*e)->premierP, timeG, id);
                supprimeAvion(&(*e)->premierP, id);
                printf("AvionP vient d'atterir\n");
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
                if (*time <= timeG && id != 0 && (*pi)->premierG == NULL)
                {
                    atterissage(e, pi, p, 1, timeG, id);
                }
            }
            break;
        case 1:
            if ((*e)->premierM != NULL)
            {
                int id = rechercheParTemps((*e)->premierM, timeG, &time);
                if (*time <= timeG && id != 0 && (*pi)->premierM == NULL)
                {
                    atterissage(e, pi, p, 2, timeG, id);
                }
            }
            break;
        case 2:
            if ((*e)->premierP != NULL)
            {
                int id = rechercheParTemps((*e)->premierP, timeG, &time);
                if (*time <= timeG && id != 0 && (*pi)->premierP == NULL)
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
            if ((*pi)->premierG != NULL && (*pi)->premierG->decolage == true)
            {
                (*pi)->premierG->time = timeG + rand() % ATTENTE_S + 10;
                (*pi)->premierG->decolage = false;
                ajouteEnFin(&(*e)->premierG, (*pi)->premierG);
                supprimeEnTete(&(*pi)->premierG);
                printf("AvionG qui passe en vol\n");
            }
            break;
        case 1:
            if ((*pi)->premierM != NULL && (*pi)->premierM->decolage == true)
            {
                (*pi)->premierM->time = timeG + rand() % ATTENTE_S + 10;
                (*pi)->premierM->decolage = false;
                ajouteEnFin(&(*e)->premierM, (*pi)->premierM);
                supprimeEnTete(&(*pi)->premierM);
                printf("AvionM qui passe en vol\n");
            }
            break;
        case 2:
            if ((*pi)->premierP != NULL && (*pi)->premierP->decolage == true)
            {
                (*pi)->premierP->time = timeG + rand() % ATTENTE_S + 10;
                (*pi)->premierP->decolage = false;
                ajouteEnFin(&(*e)->premierP, (*pi)->premierP);
                supprimeEnTete(&(*pi)->premierP);
                printf("AvionP qui passe en vol\n");
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
                (*t)->premierG->decolage = true;
                ajouteEnFin(&(*pi)->premierG, (*t)->premierG);
                supprimeEnTete(&(*t)->premierG);
                printf("AvionG qui passe en piste pour décoller\n");
            }
            break;
        case 1:
            if ((*t)->premierM != NULL && (*pi)->premierM == NULL)
            {
                (*t)->premierM->decolage = true;
                ajouteEnFin(&(*pi)->premierM, (*t)->premierM);
                supprimeEnTete(&(*t)->premierM);
                printf("AvionM qui passe en piste pour décoller\n");
            }
            break;
        case 2:
            if ((*t)->premierP != NULL && (*pi)->premierP == NULL)
            {
                (*t)->premierP->decolage = true;
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
            if ((*pi)->premierG != NULL && (*pi)->premierG->decolage == false)
            {
                (*pi)->premierG->time = timeG + rand() % ATTENTE_S + 5;
                ajouteEnFin(&(*p)->premierG, (*pi)->premierG);
                supprimeEnTete(&(*pi)->premierG);
                printf("AvionG qui passe au Parking\n");
            }
            break;
        case 1:
            if ((*pi)->premierM != NULL && (*pi)->premierM->decolage == false)
            {
                (*pi)->premierM->time = timeG + rand() % ATTENTE_S + 5;
                ajouteEnFin(&(*p)->premierM, (*pi)->premierM);
                supprimeEnTete(&(*pi)->premierM);
                printf("AvionM qui passe au Parking\n");
            }
            break;
        case 2:
            if ((*pi)->premierP != NULL && (*pi)->premierP->decolage == false)
            {
                (*pi)->premierP->time = timeG + rand() % ATTENTE_S + 5;
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


void boucleMoteur(EnVol **e, Piste **pi, Parking **p, Taxis **t)
{
    time_t currentTime;
    int timeG;
    int tpm = 0;
    int tours = 0;
    int toursMax;
    system("clear");
    printf("Combien de tours voulez-vous faire ?\n");
    printf("Votre choix: ");
    scanf("%d", &toursMax);
    system("clear");
    time_t startTime = time(NULL);
    while (tours < toursMax)
    {
        currentTime = time(NULL);
        timeG =currentTime - startTime;
        printf("Temps écoulé : %d secondes\n", timeG);
        (*e)->nbAvions = compteAvion((*e)->premierG) + compteAvion((*e)->premierM) + compteAvion((*e)->premierP);
        
        if (tpm == 0)
        {
            testFromParkingToTaxis(p, t, timeG);
            testAtterissage(e, pi, *p, timeG);
        }
        if (tpm == 1)
        {
            decollage(pi, e, timeG);
            fromPisteToParking(pi, p, timeG);
            fromTaxisToPiste(t, pi);
        }
        dessinAeroport(compteAvion((*p)->premierG), compteAvion((*p)->premierM), compteAvion((*p)->premierP), compteAvion((*t)->premierG), compteAvion((*t)->premierM), compteAvion((*t)->premierP), compteAvion((*pi)->premierG), compteAvion((*pi)->premierM), compteAvion((*pi)->premierP));
        usleep(250000);
        tpm = (tpm + 1)%2;
        tours++;
        system("clear");
    }
    sauvegardeBdd(e, p, pi, t);
}
