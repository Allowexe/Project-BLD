#ifndef INIT_STRUCT_H
#define INIT_STRUCT_H

#include "BDD.h"
#include "initStruct.h"
#include "moteur.h"
#include "Structures.h"
#include "includeGlobal.h"

void initParking(Parking **p);
void initPiste(Piste **p);
void initTaxis(Taxis **t);
void initEnVol(EnVol **e);
void init(Parking **p, Piste **pi, Taxis **t, EnVol **e);

#endif

