//
// Created by Etienne on 09/11/2018.
//

#include "../inc/actions.h"

void afficherDonnees(Informations tableau, int nbLigne)
{
    for (int i = 0; i < nbLigne ; i++)
    {
        printf("Element %d : temps : %d poul : %d\n", i, tableau[i].temps, tableau[i].poul);
    }
}

void afficherTriees(Informations tableau, Informations *tableauTrie, int nbLigne, int ordre)
{
    for(int i = 0; i<nbLigne; i++)
    {
        (*tableauTrie)[i] = tableau[i];
    }
    char choix[TAILLE_MAX];

    do
    {
        printf("=== Trier en fonction du : ===\n1 - Poul\n2 - Temps\n3 - Retour\n");
        scanf("%s", choix);
        while(isNum(choix) != 1)
        {
            printf(NOT_NUMBER);
            scanf("%s", choix);
        }
        switch(atoi(choix))
        {
            case 1:
                //printf("Debut du tri fusion...\n");
                triFusion(tableauTrie, nbLigne, 1);
                //printf("Fin du tri.\n");
                afficherTab(*tableauTrie, nbLigne, ordre);
                break;
            case 2:
                triFusion(tableauTrie, nbLigne, 2);
                afficherTab(*tableauTrie, nbLigne, ordre);
                break;
            case 3:
                break;
            default:
                printf(ERREUR_MENU);
                break;
        }
    }
    while(atoi(choix) != 3);
}

int tempsMax(Informations tableau, int nbLigne)
{
    int max = tableau[0].temps;
    for (int i = 0; i < nbLigne ; i++)
    {
        if (tableau[i].temps > max)
        {
            max = tableau[i].temps;
        }
    }
    return max;
}

int tempsMini(Informations tableau, int nbLigne)
{
    int mini = tableau[0].temps;
    for (int i = 0; i < nbLigne ; i++)
    {
        if (tableau[i].temps < mini)
        {
            mini = tableau[i].temps;
        }
    }
    return mini;
}

int isNum(char entree[])
{
    for (int i = 0; entree[i] != '\0'; i++)
    {
        if (48 > entree[i] || entree[i] > 57)
        {
            return 0;
        }
    }
    return 1;
}

int poulMaxMin(Informations tableau, int borneInf, int borneSup, int nbLigne)
{
    Information max, min;
    max.poul = tableau[0].poul;
    min.poul = tableau[0].poul;
    int is_value = 0;


    for(int i = 0; i < nbLigne; i++) {

        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup))
        {
            if(tableau[i].poul >= max.poul)
            {
                max = tableau[i];
                is_value = 1;
            }

            if(tableau[i].poul <= min.poul)
            {
                min = tableau[i];
                is_value = 1;
            }
        }
    }
    printf("Dans l'intervalle [%d;%d] :\n", borneInf, borneSup);
    if(is_value == 1)
    {
        printf("Poul maximum de %d atteint %c %d\n", max.poul, AGRAVE, max.temps);
        printf("Poul minimum de %d atteint %c %d\n", min.poul, AGRAVE, min.temps);
        return 1;
    }
    else
    {
        printf("Il n'y a aucune valeur !\n");
        return 0;
    }
}

void poulMoyen(Informations tableau, int borneInf, int borneSup, int nbLigne)
{
    int ligneIntervalle = 0;
    int totalPoul = 0;
    for (int i = 0; i < nbLigne; i++)
    {
        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup))
        {
            totalPoul += tableau[i].poul;
            ligneIntervalle++;
        }
    }

    int resultat = totalPoul/ligneIntervalle;
    printf("Le poul moyen dans cet intervalle est de %d\n", resultat);
}

void afficherDonneesTemps(Informations tableau, int borneInf, int borneSup, int nbLigne)
{

    for (int i = 0; i < nbLigne ; i++)
    {
        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup))
        {
            printf("Element %d : temps : %d poul : %d\n", i, tableau[i].temps, tableau[i].poul);
        }
    }

}

void fusion (Informations *T, int deb1, int fin1, int fin2, int mode)
{
    Informations *table1;
    int deb2 = fin1+1;
    int compt1 = deb1;
    int compt2 = deb2;
    int i;

    table1 = malloc((fin1-deb1+1)*sizeof(Information));

    for(i = deb1; i <= fin1 ; i++)
    {
        (*table1)[i-deb1] = (*T)[i];
    }

    for(i = deb1 ; i <= fin2; i++)
    {
        if(mode == 1)
        {
            if(compt1 == deb2)
            {
                break;
            }
            else if (compt2 == (fin2+1))
            {
                (*T)[i] = (*table1)[compt1-deb1];
                compt1++;
            }
            else if((*table1)[compt1-deb1].poul < (*T)[compt2].poul)
            {
                (*T)[i] = (*table1)[compt1-deb1];
                compt1++;
            }
            else
            {
                (*T)[i] = (*T)[compt2];
                compt2++;
            }
        }
        else
        {
            if(compt1 == deb2)
            {
                break;
            }
            else if (compt2 == (fin2+1))
            {
                (*T)[i] = (*table1)[compt1-deb1];
                compt1++;
            }
            else if((*table1)[compt1-deb1].temps < (*T)[compt2].temps)
            {
                (*T)[i] = (*table1)[compt1-deb1];
                compt1++;
            }
            else
            {
                (*T)[i] = (*T)[compt2];
                compt2++;
            }
        }

    }
    free(table1);
}

void triFusionBis(Informations *T, int deb, int fin, int mode)
{
    if(deb!=fin)
    {
        int milieu = (fin+deb)/2;
        triFusionBis(T, deb, milieu, mode);
        triFusionBis(T, milieu+1, fin, mode);
        fusion(T, deb, milieu, fin, mode);
    }
}

void triFusion(Informations *T, int longueur, int mode)
{
    if(longueur > 0)
    {
        triFusionBis(T, 0, longueur-1, mode);
    }
}
void afficherTab(Informations tableau, int nbLigne, int ordre)
{
    if (ordre == 1)
    {
        for (int k = 0; k < nbLigne ; k++)
        {
            printf("Element %d : temps : %d poul : %d\n", k, tableau[k].temps, tableau[k].poul);
        }
    }
    else
    {
        for (int k = nbLigne-1; k >= 0 ; k--)
        {
            printf("Element %d : temps : %d poul : %d\n", k, tableau[k].temps, tableau[k].poul);
        }
    }
}