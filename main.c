#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"

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
    boucleMoteur(&e, &pi, &p, &t, currentTime, startTime);
    return 0;
}
