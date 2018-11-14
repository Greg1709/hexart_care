//
// Created by Etienne on 09/11/2018.
//

#include "../inc/donnees.h"

int tailleDonnees()
{
    int i;
    FILE* fichierCSV = fopen(CSV, "r");
    char chaine[TAILLE_MAX];
    if(fichierCSV != NULL)
    {
        printf("Succes !\n");
        printf("Analyse du fichier...\n");
        for (i = 0; fgets(chaine, TAILLE_MAX, fichierCSV) != NULL; i++);

        fclose(fichierCSV);
        return i;
    }
    else
    {
        printf("Erreur d'ouverture du fichier CVS.");
    }
}

void extraireDonnees(Informations *tableau, int nbLigne)
{
    FILE* fichierCSV = fopen(CSV, "r");

    if(fichierCSV != NULL)
    {
        for (int i = 0; i < nbLigne; i++)
        {
            fscanf(fichierCSV, "%d;%d", &(*tableau)[i].temps, &(*tableau)[i].poul);
        }
        fclose(fichierCSV);
    }
    else
    {
        printf("Erreur d'ouverture du fichier CVS.");
    }
}