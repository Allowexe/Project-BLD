#ifndef BDD_H
#define BDD_H

#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"

void InitialisationBdd();
void AssgnBdd(EnVol **e, Parking **p);
void ajouteEnFin(Avion **a, Avion *nouveau);
void ajouteEnFinParId(Avion** nouveau, Avion* ancien, int timeG, int id);
void supprimeEnTete(Avion **a);
int rechercheParTemps(Avion *Ancien, int timeG, int **timeA);
void supprimeAvion(Avion **a, int id);
int compteAvion(Avion *a);
void printAllAvion(Avion *a);


#endif // BDD_H
