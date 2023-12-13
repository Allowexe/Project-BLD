#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"
#include "affichage.h"

int main(int argc, char const *argv[])
{
    InitialisationBdd();
    Parking *p = malloc(sizeof(Parking));
    Piste *pi = malloc(sizeof(Piste));
    Taxis *t = malloc(sizeof(Taxis));
    EnVol *e = malloc(sizeof(EnVol));
    init(&p, &pi, &t, &e);
    time_t startTime = time(NULL);
    time_t currentTime;
    AssgnBdd(&e, &p);
    animBegining();
    sleep(1.5);
    system("clear");
    while (1)
    {
        currentTime = time(NULL) - startTime;
        boucleMoteur(&e, &pi, &p, &t, currentTime);
        dessinAeroport(compteAvion(p->premierG), compteAvion(p->premierM), compteAvion(p->premierP), compteAvion(t->premierG), compteAvion(t->premierM), compteAvion(t->premierP), compteAvion(pi->premierG), compteAvion(pi->premierM), compteAvion(pi->premierP));
        system("clear");
    }

    return 0;
}
