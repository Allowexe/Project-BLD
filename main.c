#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"
#include "affichage.h"

int main(int argc, char const *argv[])
{
    time_t startTime = time(NULL);
    time_t currentTime;
    // InitialisationBdd();
    // animBegining();
    // sleep(5);
    // initalisation des structures
    EnVol *enVol = malloc(sizeof(EnVol));
    Parking *parking = malloc(sizeof(Parking));
    Piste *piste = malloc(sizeof(Piste));
    Taxis *taxis = malloc(sizeof(Taxis));
    init(&parking, &piste, &taxis);
    
    enVol->nbAvions = 1;
    Avion *avion = malloc(sizeof(Avion));
    avion->identifiant = 20;
    avion->categorie = 1;
    avion ->NbPassagers = 1;
    avion->time = 0;
    while (taxis->numero != 1)
    {
        taxis = taxis->suivant;
    }
    ajouteEnFin(&taxis->premier, avion);
    testTaxisToPiste(&taxis, &piste);
    while (piste->numero != 1)
    {
        piste = piste->suivant;
    }
    while (piste->premier != NULL)
    {
        printf("identifiant : %d\n", piste->premier->identifiant);
        piste->premier = piste->premier->suivant;
    }

    
    
    //afficher les avions sur la piste
    

    
    
    
    
    


    // while (1)
    // {
    //     currentTime = time(NULL) - startTime;
    //     printf("Temps écoulé : %ld secondes\n", currentTime);
    //     // Ajoutez ici une pause pour ralentir l'affichage de l'horloge
    //     boucleMoteur(&parking, &taxis, &piste, &enVol, currentTime);
    //     system("clear");
        
    // }

    return 0;
}
