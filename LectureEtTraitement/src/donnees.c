//
// Created by Etienne on 09/11/2018.
//

#include "../inc/donnees.h"

int tailleDonnees() //Fonction permettant de recueillir le nombre total de ligne du fichier CSV
{
    int i;
    FILE* fichierCSV = fopen(CSV, "r"); //Ouverture du fichier CSV en mode lecture
    char chaine[TAILLE_MAX];
    if(fichierCSV != NULL) //Si l'ouverture à réussie :
    {
        printf("Succes !\n");
        printf("Analyse du fichier...\n");
        for (i = 0; fgets(chaine, TAILLE_MAX, fichierCSV) != NULL; i++); //Incrémentation de i pour chaque ligne trouvée

        fclose(fichierCSV);
        return i; //Retour du nombre de ligne (i)
    }
    else
    {
        printf(ERREUR_CSV);
        exit(1);
    }
}

void extraireDonnees(Informations *tableau, int nbLigne) //Fonction permettant de mettre en mémoire les données du fichier CSV
{
    FILE* fichierCSV = fopen(CSV, "r");

    if(fichierCSV != NULL)
    {
        for (int i = 0; i < nbLigne; i++)
        {

            fscanf(fichierCSV, "%d;%d", &(*tableau)[i].temps, &(*tableau)[i].poul); //Pour chaque ligne, on prend les valeurs du fichier CSV ("temps;poul") pour les mettre en mémoire (tableau de structure)

        }
        fclose(fichierCSV);
    }
    else
    {
        printf(ERREUR_CSV);
        exit(1);
    }
}