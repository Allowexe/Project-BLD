#ifndef MOTEUR_H
#define MOTEUR_H

#include "BDD.h"
#include "InitStruct.h"
#include "Structures.h"
#include "includeGlobal.h"
#include "affichage.h"

void atterissage(EnVol **e, Piste **pi, Parking *p, int categorie, int timeG, int id);
void testAtterissage(EnVol **e, Piste **pi, Parking *p, int timeG);
void decollage(Piste **pi, EnVol **e, int timeG);
void fromParkingToTaxis(Parking **p, Taxis **t, int timeG, int categorie, int id);
void testFromParkingToTaxis(Parking **p, Taxis **t, int timeG);
void fromTaxisToPiste(Taxis **t, Piste **pi);
void fromPisteToParking(Piste **pi, Parking **p, int timeG);
void boucleMoteur(EnVol **e, Piste **pi, Parking **p, Taxis **t);

#endif //MOTEUR_H
