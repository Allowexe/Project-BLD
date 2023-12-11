#ifndef INIT_STRUCT_H
#define INIT_STRUCT_H

#include "includeGlobal.h"
#include "Stuctures.h"
#include "moteur.h"
#include "BDD.h"
#include "InitStruct.h"

void initParking(Parking **p);
void initPiste(Piste **p);
void initTaxis(Taxis **t);
void init(Parking **p, Piste **pi, Taxis **t);

#endif

