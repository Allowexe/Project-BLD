#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

int main(int argc, char const *argv[])
{
    time_t startTime = time(NULL);
    time_t currentTime;
    InitialisationBdd();
    // initalisation des structures
    EnVol *enVol = malloc(sizeof(EnVol));
    Parking *parking = malloc(sizeof(Parking));
    Piste *piste = malloc(sizeof(Piste));
    Taxis *taxis = malloc(sizeof(Taxis));
    init(&parking, &piste, &taxis);

    while (1)
    {
        currentTime = time(NULL) - startTime;
        printf("Temps écoulé : %ld secondes\n", currentTime);
        // Ajoutez ici une pause pour ralentir l'affichage de l'horloge
        boucleMoteur(&parking, &taxis, &piste, &enVol, currentTime);
        system("clear");
        
    }

    return 0;
}
