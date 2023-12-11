#ifndef MOTEUR_H
#define MOTEUR_H

#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void fromParkingToTaxis(Parking **p, Taxis **t, Avion *a, int categorie);
void testParkingToTaxis(Parking **p, Taxis **t, int timeG);
//___________________________________________________________________________________________
void fromTaxisToPiste(Taxis **t, Piste **p, int categorie);
void testTaxisToPiste(Taxis **t, Piste **p);
//___________________________________________________________________________________________
void decollage(Piste **p, EnVol **e, int categorie, int timeG);
int testDecollage(Piste **p, EnVol **e, int timeG);
//___________________________________________________________________________________________
void atterissage(Piste **p, EnVol **e, Avion *a, int categorie);
void testAtterissage(Parking **p, Piste **pi, EnVol **e, int timeG);
//___________________________________________________________________________________________
void fromPisteToParking(Piste **p, Parking **park, int categorie, int timeG);
//___________________________________________________________________________________________


void boucleMoteur(Parking **p, Taxis **t, Piste **pi, EnVol **e, int timeG);


#endif