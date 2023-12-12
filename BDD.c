#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void InitialisationBdd()
{
    srand(time(NULL));
    // création de la base de donnée
    FILE *fichier;
    int categorie = 0;
    int etat = 0;
    int id = 0;
    int nb = 0;
    int cpt = 0;
    int cpt2 = 0;
    int cpt3 = 0;
    fichier = fopen("bdd.txt", "w");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    else
    {
        printf("Fichier ouvert avec succès\n");
        fprintf(fichier, "Nombre d'avions: %d\n", NB_AVION);
        for (int i = 0; i < NB_AVION; i++)
        {
            id = i + 1;
            fprintf(fichier, "ID: %d ", id);
            categorie = (rand() % 3 + 1);
            fprintf(fichier, "Categorie: %d ", categorie);
            if (nb < 21)
            {
                etat = (rand() % 2);
                switch (categorie)
                {
                case 1:
                    if (cpt < 7 && etat == 0)
                    {
                        nb++;
                        cpt++;
                    }
                    else
                    {
                        etat = 1;
                    }

                    break;

                case 2:
                    if (cpt2 < 7 && etat == 0)
                    {
                        cpt2++;
                        nb++;
                    }
                    else
                    {
                        etat = 1;
                    }
                    break;

                case 3:
                    if (cpt3 < 7 && etat == 0)
                    {
                        cpt3++;
                        nb++;
                    }
                    else
                    {
                        etat = 1;
                    }
                    break;

                default:
                    break;
                }
            }
            else
            {
                etat = 1;
            }
            fprintf(fichier, "Etat: %d ", etat);
            switch (categorie)
            {
            case 1:
                fprintf(fichier, "Passagers: %d ", (rand() % 311 + 530));
                break;
            case 2:
                fprintf(fichier, "Passagers: %d ", (rand() % 19 + 10));
                break;

            case 3:
                fprintf(fichier, "Passagers: %d ", (rand() % 10 + 2));
                break;
            default:
                break;
            }
            fprintf(fichier, "Temps: %d\n", (rand() % 10 + 1));
        }
        printf("Fin de l'initialisation\n");
        // initialisation de la BDD effectuée, fermeture du fichier
        fclose(fichier);
    }
}

void AssgnBdd(EnVol **e, Parking **p)
{
    FILE *fichier;
    fichier = fopen("bdd.txt", "r");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }

    int nb_av = 0;
    printf("Fichier ouvert avec succès\n");
    fscanf(fichier, "Nombre d'avions: %d\n", &nb_av);
    printf("Nombre d'avions: %d\n", nb_av);
    for (int i = 0; i < nb_av; i++)
    {
        Avion *nouveau = malloc(sizeof(*nouveau));
        fscanf(fichier, "ID: %02d ", &nouveau->identifiant);
        fscanf(fichier, "Categorie: %d ", &nouveau->categorie);
        fscanf(fichier, "Etat: %d ", &nouveau->etat);
        fscanf(fichier, "Passagers: %d ", &nouveau->NbPassagers);
        fscanf(fichier, "Temps: %d\n", &nouveau->time);
        if (nouveau->etat == 1)
        {
            (*e)->nbAvions++;
            switch (nouveau->categorie)
            {
            case 1:
                ajouteEnFin(&(*e)->premierG, nouveau);
                break;

            case 2:
                ajouteEnFin(&(*e)->premierM, nouveau);
                break;

            case 3:
                ajouteEnFin(&(*e)->premierP, nouveau);
                break;

            default:
                break;
            }
        }
        else
        {
            (*p)->nbAvions++;
            switch (nouveau->categorie)
            {
            case 1:
                ajouteEnFin(&(*p)->premier, nouveau);
                break;

            case 2:
                ajouteEnFin(&(*p)->suivant->premier, nouveau);
                break;

            case 3:
                ajouteEnFin(&(*p)->suivant->suivant->premier, nouveau);
                break;

            default:
                break;
            }
        }
    }

    printf("Fin de l'assignation\n");
    // initialisation de la BDD effectuée, fermeture du fichier
    fclose(fichier);
}

void ajouteEnFin(Avion **a, Avion *nouveau)
{
    if (a == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    nouveau->suivant = NULL;
    if (*a == NULL)
    {
        *a = nouveau;
    }
    else
    {
        Avion *actuel = *a;
        while (actuel->suivant != NULL)
        {
            actuel = actuel->suivant;
        }
        actuel->suivant = nouveau;
    }
}

void supprimeEnTete(Avion **a)
{
    Avion *nouveau = malloc(sizeof(*nouveau));
    if (a == NULL || nouveau == NULL)
    {
        exit(EXIT_FAILURE);
    }
    *a = (*a)->suivant;
}

Avion *rechercheParTempsEnVol(EnVol *e, int categorie, int timeG)
{
    Avion *actuel = malloc(sizeof(*actuel));
    int i = 0;
    switch (categorie)
    {
    case 1:
        actuel = e->premierG;
        break;

    case 2:
        actuel = e->premierM;
        break;

    case 3:
        actuel = e->premierP;
        break;

    default:
        break;
    }

    while (i < 1)
    {
        if (actuel->time <= timeG)
        {
            i++;
        }
        else
        {
            if (actuel->suivant == NULL && actuel == NULL)
            {
                break;
            }
            actuel = actuel->suivant;
        }
    }

    return actuel;
}

Avion *rechercheParTempsParking(Parking *p, int categorie, int timeG)
{
    Avion *actuel = malloc(sizeof(*actuel));
    int i = 0;
    while (p->numero != categorie)
    {
        p = p->suivant;
    }
    actuel = p->premier;
    while (p->nbAvions> i)
    {
        if (actuel->time <= timeG)
        {
            return actuel;
        }
        else
        {
            actuel = actuel->suivant;
        }
        i++;
    }

    return NULL;
}

void supprimeAvion(Avion **a, int id)
{
    Avion *actuel = *a;
    Avion *precedent = NULL;
    while (actuel != NULL && actuel->identifiant != id)
    {
        precedent = actuel;
        actuel = actuel->suivant;
    }
    if (actuel == NULL)
    {
        printf("L'avion n'existe pas\n");
    }
    else if (precedent == NULL)
    {
        *a = actuel->suivant;
        free(actuel);
    }
    else
    {
        precedent->suivant = actuel->suivant;
        free(actuel);
    }
}

void printAllAvion(Avion *a)
{
    Avion *actuel = a;
    while (actuel != NULL)
    {
        printf("ID: %d ", actuel->identifiant);
        printf("Categorie: %d ", actuel->categorie);
        printf("Etat: %d ", actuel->etat);
        printf("Passagers: %d\n", actuel->NbPassagers);
        actuel = actuel->suivant;
    }
}

void sauvegardeBdd(EnVol *e, Parking *p, Taxis *t, Piste *pi, int timeG)
{
    FILE *fichier;
    fichier = fopen("bdd.txt", "w");
    if (fichier == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier\n");
        exit(1);
    }
    else
    {
        printf("Fichier ouvert avec succès\n");
        fprintf(fichier, "Nombre d'avions: %d\n", NB_AVION);
        Avion *actuel = malloc(sizeof(*actuel));
        for (int i = 0; i < 3; i++)
        {
            switch (i)
            {
            case 0:
                actuel = e->premierG;
                break;

            case 1:
                actuel = e->premierM;
                break;

            case 2:
                actuel = e->premierP;
                break;

            default:
                break;
            }
            while (actuel != NULL)
            {
                fprintf(fichier, "ID: %02d ", actuel->identifiant);
                fprintf(fichier, "Categorie: %d ", actuel->categorie);
                fprintf(fichier, "Etat: %d ", actuel->etat);
                fprintf(fichier, "Passagers: %d ", actuel->NbPassagers);
                fprintf(fichier, "Temps: %d\n", (actuel->time-timeG));
                actuel = actuel->suivant;
            }
        }
        for (int i = 0; i < 3; i++)
        {
            switch (i)
            {
            case 0:
                actuel = p->premier;
                break;

            case 1:
                actuel = p->suivant->premier;
                break;

            case 2:
                actuel = p->suivant->suivant->premier;
                break;

            default:
                break;
            }
            while (actuel != NULL)
            {
                fprintf(fichier, "ID: %02d ", actuel->identifiant);
                fprintf(fichier, "Categorie: %d ", actuel->categorie);
                fprintf(fichier, "Etat: %d ", actuel->etat);
                fprintf(fichier, "Passagers: %d ", actuel->NbPassagers);
                fprintf(fichier, "Temps: %d\n", actuel->time-timeG);
                actuel = actuel->suivant;
            }
        }
        if (t->premier != NULL)
        {
            for (int i = 0; i < 3; i++)
            {
                switch (i)
                {
                case 0:
                    actuel = t->premier;
                    break;

                case 1:
                    actuel = t->suivant->premier;
                    break;

                case 2:
                    actuel = t->suivant->suivant->premier;
                    break;

                default:
                    break;
                }

                while (actuel != NULL)
                {
                    fprintf(fichier, "ID: %02d ", actuel->identifiant);
                    fprintf(fichier, "Categorie: %d ", actuel->categorie);
                    fprintf(fichier, "Etat: %d ", actuel->etat);
                    fprintf(fichier, "Passagers: %d ", actuel->NbPassagers);
                    fprintf(fichier, "Temps: %d\n", actuel->time-timeG);
                    actuel = actuel->suivant;
                }
            }
        }

        if (pi->premier != NULL)
        {
            for (int i = 0; i < 3; i++)
            {
                
                switch (i)
                {
                case 0:
                    actuel = pi->premier;
                    break;

                case 1:
                    actuel = pi->suivant->premier;
                    break;

                case 2:
                    actuel = pi->suivant->suivant->premier;
                    break;

                default:
                    break;
                }
                while (actuel != NULL)
                {
                    fprintf(fichier, "ID: %02d ", actuel->identifiant);
                    fprintf(fichier, "Categorie: %d ", actuel->categorie);
                    fprintf(fichier, "Etat: %d ", actuel->etat);
                    fprintf(fichier, "Passagers: %d ", actuel->NbPassagers);
                    fprintf(fichier, "Temps: %d\n", actuel->time-timeG);
                    actuel = actuel->suivant;
                }
            }
        }

        printf("Fin de la sauvegarde\n");
    }
    fclose(fichier);
}
