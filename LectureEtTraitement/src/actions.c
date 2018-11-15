//
// Created by Etienne on 09/11/2018.
//

#include "../inc/actions.h"

//Fonction permettant d'afficher les données dans l'ordre du fichier CSV :
void afficherDonnees(Informations tableau, int nbLigne)
{
    for (int i = 0; i < nbLigne ; i++) //Pour chaque ligne de notre tableau
    {
        printf("Element %d : temps : %d poul : %d\n", i, tableau[i].temps, tableau[i].poul); //On affiche son contenu
    }
}


//Fonction permettant d'afficher les données triées d'une certaine façon via un tri fusion :
void afficherTriees(Informations tableau, Informations *tableauTrie, int nbLigne, int ordre)
{
    for(int i = 0; i<nbLigne; i++) //On duplique le tableau du fichier CSV dans un autre espace mémoire
    {
        (*tableauTrie)[i] = tableau[i];
    }
    char choix[TAILLE_MAX];

    do
    {
        printf("=== Trier en fonction du : ===\n1 - Poul\n2 - Temps\n3 - Retour\n");
        scanf("%s", choix);
        while(isNum(choix) != 1) //On teste si l'utilisateur n'entre bien que des chiffres
        {
            printf(NOT_NUMBER);
            scanf("%s", choix);
        }
        switch(atoi(choix)) //Menu de sélection poul/temps
        {
            case 1:
                triFusion(tableauTrie, nbLigne, 1); //On lance le tri fusion en fonction du poul
                afficherTab(*tableauTrie, nbLigne, ordre); //On lance l'affichage dans l'ordre demandé
                break;
            case 2:
                triFusion(tableauTrie, nbLigne, 2); //On lance le tri fusion en fonction du temps
                afficherTab(*tableauTrie, nbLigne, ordre);
                break;
            case 3:
                break;
            default:
                printf(ERREUR_MENU); //Affichage d'une erreur si l'utilisateur entre un chiffre ne correspondant pas à une option du menu
                break;
        }
    }
    while(atoi(choix) != 3); //Quand l'utilisateur entre "3", il revient au menu précédent
}


//Fonction permettant de recueillir les temps maximum et minimum enregistrés lors de l'acquisition Arduino :
void tempsMaxMin(Informations tableau, int nbLigne, int *min, int *max)
{
    int maxArbitraire = tableau[0].temps, minArbitraire = tableau[0].temps; //On défini des temps arbitraires
    for(int i = 0; i < nbLigne; i++) //Pour chaque ligne
    {
        if (tableau[i].temps < minArbitraire) //On teste si les temps dépassent les temps max et mini enregistrés jusqu'à présent
        {
            minArbitraire = tableau[i].temps; //On attribu un nouveau temps minimum
        }

        if (tableau[i].temps > maxArbitraire)
        {
            maxArbitraire = tableau[i].temps; //On attribu un nouveau temps maximum
        }
    }
    *min = minArbitraire; //Attribution des max/min trouvés dans des variables globales
    *max = maxArbitraire;
}


//Fonction permettant de tester si un tableau de charactères n'est composé que de chiffre :
int isNum(char entree[])
{
    for (int i = 0; entree[i] != '\0'; i++) //Pour chaque caractère de notre tableau de caractère
    {
        if (48 > entree[i] || entree[i] > 57) //Si le code ASCII ne correspond pas à celui d'un chiffre
        {
            return 0; //On retourne directement 0
        }
    }
    return 1; //Si la condition d'avant n'a jamais été vraie, alors le tableau est composé uniquement de chiffre, on retourne 1
}


//Fonction permettant, pour un intervalle de temps donné, de recueillir le poul max/mini ainsi que le temps associé :
int poulMaxMin(Informations tableau, int borneInf, int borneSup, int nbLigne)
{
    Information max, min;
    max.poul = tableau[0].poul; //Définition d'un poul max et mini arbitraire
    min.poul = tableau[0].poul;
    int is_value = 0;


    for(int i = 0; i < nbLigne; i++) { //Pour chaque ligne du tableau

        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup)) //Si le temps appartient au bornes demandées
        {
            if(tableau[i].poul >= max.poul) //On compare les pouls
            {
                max = tableau[i]; //On associe le poul au temps
                is_value = 1; //Il y a bien une valeur dans l'intervalle demandé
            }

            if(tableau[i].poul <= min.poul)
            {
                min = tableau[i];
                is_value = 1;
            }
        }
    }
    printf("Dans l'intervalle [%d;%d] :\n", borneInf, borneSup);
    if(is_value == 1) //Si il y a une valeur dans l'intervalle demandé
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


//Fonction permettant, pour un intervalle donné, de calculer le poul moyen :
void poulMoyen(Informations tableau, int borneInf, int borneSup, int nbLigne)
{
    int ligneIntervalle = 0;
    int totalPoul = 0;
    for (int i = 0; i < nbLigne; i++) //Pour chaque ligne du tableau
    {
        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup)) //Si la ligne du tableau appartient à la l'intervalle demandé
        {
            totalPoul += tableau[i].poul; //Eléments utilisés pour calculer le poul
            ligneIntervalle++;
        }
    }

    int resultat = totalPoul/ligneIntervalle; //Moyenne des pouls
    printf("Le poul moyen dans cet intervalle est de %d\n", resultat);
}


//Fonction permettant, pour un intervalle donné, d'afficher les données :
void afficherDonneesTemps(Informations tableau, int borneInf, int borneSup, int nbLigne)
{

    for (int i = 0; i < nbLigne ; i++) //Pour chaque ligne du tableau
    {
        if ((borneInf <= tableau[i].temps) && (tableau[i].temps <= borneSup)) //Si la ligne appartient à l'intervalle de temps demandé
        {
            printf("Element %d : temps : %d poul : %d\n", i, tableau[i].temps, tableau[i].poul);
        }
    }

}

void fusion (Informations *T, int deb1, int fin1, int fin2, int mode) //Fonction composant le tri Fusion
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

void triFusionBis(Informations *T, int deb, int fin, int mode) //Fonction composant le tri Fusion
{
    if(deb!=fin)
    {
        int milieu = (fin+deb)/2;
        triFusionBis(T, deb, milieu, mode);
        triFusionBis(T, milieu+1, fin, mode);
        fusion(T, deb, milieu, fin, mode);
    }
}


//Fonction composant le tri Fusion (Fonction d'initialisation du tri) :
void triFusion(Informations *T, int longueur, int mode)

{
    if(longueur > 0)
    {
        triFusionBis(T, 0, longueur-1, mode);
    }
}


//Fonction permettant d'afficher les données d'un tableau, dans l'ordre croissant ou décroissant :
void afficherTab(Informations tableau, int nbLigne, int ordre)
{
    if (ordre == 1)//Si l'ordre choisi est 1 (=croissant)
    {                                                       //
        for (int k = 0; k < nbLigne ; k++) //De 0 à "nombre de ligne"
        {
            printf("Element %d : temps : %d poul : %d\n", k, tableau[k].temps, tableau[k].poul); //On affiche chaque ligne
        }
    }
    else //Sinon 0 (=décroissant)
    {
        for (int k = nbLigne-1; k >= 0 ; k--) //De "nombre de ligne" à 0
        {
            printf("Element %d : temps : %d poul : %d\n", k, tableau[k].temps, tableau[k].poul);
        }
    }
}