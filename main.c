#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"

int main(int argc, char const *argv[])
{
    animBegining();
    sleep(1.5);
    system("clear");
    int choix = menu();
    switch (choix)
    {
    case 1:
        InitialisationBdd();
        break;
    case 3:
        exit(0);
        break;
    default:
        break;
    }
    InitialisationBdd();
    Parking *p = malloc(sizeof(Parking));
    Piste *pi = malloc(sizeof(Piste));
    Taxis *t = malloc(sizeof(Taxis));
    EnVol *e = malloc(sizeof(EnVol));
    init(&p, &pi, &t, &e);
    AssgnBdd(&e, &p);
    boucleMoteur(&e, &pi, &p, &t);
    return 0;
}
