#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"
#include "affichage.h"

int main(int argc, char const *argv[])
{
    animBegining();
    InitialisationBdd();
    Parking *p = malloc(sizeof(Parking));
    Piste *pi = malloc(sizeof(Piste));
    Taxis *t = malloc(sizeof(Taxis));
    EnVol *e = malloc(sizeof(EnVol));
    init(&p, &pi, &t, &e);
    time_t startTime = time(NULL);
    time_t currentTime;
    AssgnBdd(&e, &p);
    sleep(1.5);
    system("clear");
    while (1)
    {
        currentTime = time(NULL) - startTime;
        printf("Temps écoulé : %ld secondes\n", currentTime);
        boucleMoteur(&e, &pi, &p, &t, currentTime);
        printf("Nombre d'avions en vol : %d\n", e->nbAvions);
        printf("Nombre de gros avions au parking : %d\n", compteAvion(p->premierG));
        printf("Nombre de moyen avions au parking : %d\n", compteAvion(p->premierM));
        printf("Nombre de petit avions au parking : %d\n", compteAvion(p->premierP));
        printf("Nombre de gros avions sur le taxis : %d\n", compteAvion(t->premierG));
        printf("Nombre de moyen avions sur le taxis : %d\n", compteAvion(t->premierM));
        printf("Nombre de petit avions sur le taxis : %d\n", compteAvion(t->premierP));
        sleep(1);
        system("clear");
    }

    return 0;
}
