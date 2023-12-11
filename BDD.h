#ifndef BDD_H
#define BDD_H

#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void InitialisationBdd();
void AssgnBdd(EnVol **e, Parking **p);
void ajouteEnFin(Avion **a, Avion *nouveau);
void supprimeEnTete(Avion **a);
Avion *rechercheParTempsEnVol(EnVol *e, int categorie, int timeP);
Avion *rechercheParTempsParking(Parking *e, int categorie, int timeG);
void supprimeAvion(Avion **a, int id);
void printAllAvion(Avion *a);
void sauvegardeBdd(EnVol *e, Parking *p, Taxis *t, Piste *pi, int timeG);




#endif