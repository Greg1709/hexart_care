//
// Created by Etienne on 09/11/2018.
//

#ifndef LECTUREETTRAITEMENT_ACTIONS_H
#define LECTUREETTRAITEMENT_ACTIONS_H

#include "general.h"

void afficherDonnees(Informations, int);
void afficherTriees(Informations, Informations *, int, int);
int tempsMax(Informations, int);
int tempsMini(Informations, int);
int isNum(char [TAILLE_MAX]);
int poulMaxMin(Informations, int, int, int);
void poulMoyen(Informations, int, int, int);
void afficherDonneesTemps(Informations, int, int, int);
void fusion (Informations *, int, int, int, int);
void triFusionBis(Informations *, int, int, int);
void triFusion(Informations *, int, int);
void afficherTab(Informations, int, int);

#endif //LECTUREETTRAITEMENT_ACTIONS_H
