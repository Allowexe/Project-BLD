#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"

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
    fscanf(fichier, "Nombre d'avions: %d\n", &nb_av);
    for (int i = 0; i < nb_av; i++)
    {
        Avion *new = malloc(sizeof(Avion));
        fscanf(fichier, "ID: %d ", &new->identifiant);
        fscanf(fichier, "Categorie: %d ", &new->categorie);
        fscanf(fichier, "Etat: %d ", &new->etat);
        fscanf(fichier, "Passagers: %d ", &new->NbPassagers);
        fscanf(fichier, "Temps: %d\n", &new->time);
        if (new->etat == 0)
        {
            switch (new->categorie)
            {
            case 1:
                if ((*p)->premierG == NULL)
                {
                    (*p)->premierG = new;
                }
                else
                {
                    ajouteEnFin(&(*p)->premierG, new);
                }
                break;
            case 2:
                if ((*p)->premierM == NULL)
                {
                    (*p)->premierM = new;
                }
                else
                {
                    ajouteEnFin(&(*p)->premierM, new);
                }
                break;
            case 3:
                if ((*p)->premierP == NULL)
                {
                    (*p)->premierP = new;
                }
                else
                {
                    ajouteEnFin(&(*p)->premierP, new);
                }
                break;
            default:
                break;
            }
        }
        else
        {
            switch (new->categorie)
            {
            case 1:
                if ((*e)->premierG == NULL)
                {
                    (*e)->premierG = new;
                }
                else
                {
                    ajouteEnFin(&(*e)->premierG, new);
                }
                break;
            case 2:
                if ((*e)->premierM == NULL)
                {
                    (*e)->premierM = new;
                }
                else
                {
                    ajouteEnFin(&(*e)->premierM, new);
                }
                break;
            case 3:
                if ((*e)->premierP == NULL)
                {
                    (*e)->premierP = new;
                }
                else
                {
                    ajouteEnFin(&(*e)->premierP, new);
                }
                break;
            default:
                break;
            }
        }
    }
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

void ajouteEnFinParId(Avion **nouveau, Avion *Ancien, int timeG, int id)
{
    if (id != 0)
    {
        Avion *actuel = Ancien;
        while (actuel != NULL && actuel->identifiant != id)
        {
            actuel = actuel->suivant;
        }

        if (actuel != NULL) // if a plane with the given id was found
        {
            Avion *newNode = malloc(sizeof(*newNode));
            *newNode = *actuel; // copy the data
            newNode->suivant = NULL;
            newNode->time = timeG + 20;

            if (*nouveau == NULL)
            {
                *nouveau = newNode;
            }
            else
            {
                Avion *temp = *nouveau;
                while (temp->suivant != NULL)
                {
                    temp = temp->suivant;
                }
                temp->suivant = newNode;
            }
        }
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

int rechercheParTemps(Avion *a, int timeG, int **timeA)
{
    Avion *actuel = malloc(sizeof(*actuel));
    actuel = a;
    while (actuel != NULL)
    {
        if (actuel->time <= timeG)
        {
            **timeA = actuel->time;
            return actuel->identifiant;
        }
        actuel = actuel->suivant;
    }
    return 0;
}

void supprimeAvion(Avion **a, int id)
{
    Avion *actuel = *a;
    Avion *precedent = NULL;
    if (actuel != NULL && actuel->identifiant == id)
    {
        *a = actuel->suivant;
        free(actuel);
        return;
    }
    while (actuel != NULL && actuel->identifiant != id)
    {
        precedent = actuel;
        actuel = actuel->suivant;
    }
    if (actuel == NULL)
    {
        return;
    }
    precedent->suivant = actuel->suivant;
    free(actuel);
}


int compteAvion(Avion *a)
{
    int cpt = 0;
    while (a != NULL)
    {
        cpt++;
        a = a->suivant;
    }
    return cpt;
}
