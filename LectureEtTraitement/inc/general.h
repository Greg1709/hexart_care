//
// Created by Etienne on 12/11/2018.
//

#include <stdio.h>
#include <stdlib.h>

#ifndef LECTUREETTRAITEMENT_GENERAL_H
#define LECTUREETTRAITEMENT_GENERAL_H

#define ERREUR_MENU "Veuillez entrer une option du menu !\n"
#define NOT_NUMBER "Veuillez entrer un nombre !\n"
#define EACUTE 130
#define AGRAVE 133
#define ECIRCONFLEXE 136
#define TAILLE_MAX 20
#define CSV "alea2t1m.csv"

typedef struct{
    int temps;
    int poul;
}Information;

typedef Information Informations[];

#endif //LECTUREETTRAITEMENT_GENERAL_H
