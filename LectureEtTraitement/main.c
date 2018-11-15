#include "src/donnees.c"
#include "src/menu.c"
#include "src/actions.c"



int main() {

    printf("Ouverture du fichier CVS...\n");
    int nbLigne = tailleDonnees(); //Calcul du nombre de ligne du fichier CSV
    printf("%d lignes trouv%ces.\n", nbLigne, EACUTE);

    Informations *donnees = malloc(nbLigne * sizeof(Information)); //Allocation de mémoire pour deux tableaux en fonction du nombre de ligne trouvé
    Informations *donneesTriees = malloc(nbLigne * sizeof(Information));

    extraireDonnees(donnees, nbLigne); //Mise en mémoire des données

    int temps_max, temps_mini;
    tempsMaxMin(*donnees, nbLigne, &temps_mini, &temps_max); //Recherche des temps minimum et maximum durant l'acquisition
    printf("L'intervalle de temps de l'acquisition totale enregistr%ce est [%d;%d].\n", EACUTE, temps_mini, temps_max);

    char choix[TAILLE_MAX], choix2[TAILLE_MAX], entree1[TAILLE_MAX], entree2[TAILLE_MAX], choix3[TAILLE_MAX];

    do
    {
        menuPrincipal(); //Affichage du menu principal
        scanf("%s", choix);
        while(isNum(choix) != 1) //On vérifie que l'utilisateur entre bien un ou des chiffres
        {
            printf(NOT_NUMBER); //On affiche une erreur si il n'y a pas que des chiffres
            scanf("%s", choix);
        }

        switch (atoi(choix)){
            case 1:
                afficherDonnees(*donnees, nbLigne); //Affichage des données dans l'ordre du fichier CSV
                break;
            case 2:
                do
                {
                    menuOrdre(); //Affichage du menu pour le choix de l'ordre de tri demandé
                    scanf("%s", choix2);
                    while(isNum(choix2) != 1)
                    {
                        printf(NOT_NUMBER);
                        scanf("%s", choix2);
                    }
                    switch(atoi(choix2)){
                        case 1:
                            afficherTriees(*donnees, donneesTriees, nbLigne, 1);
                            break;
                        case 2:
                            afficherTriees(*donnees, donneesTriees, nbLigne, 2);
                            break;
                        case 3:
                            break;
                        default:
                            printf(ERREUR_MENU); //On affiche une erreur
                            break;
                    }
                }
                while(atoi(choix2) != 3);
                break;
            case 3:
                printf("L'intervalle de temps total depuis le lancement de l'acquisition va de 0 %c %d.\n", AGRAVE, temps_max);
                printf("Entrez un intervalle :\n");

                do //Demande de l'intervalle de temps voulu à l'utilisateur
                {
                    printf("Borne de gauche :\n");
                    scanf("%s", entree1);
                    while(isNum(entree1) != 1)
                    {
                        printf(NOT_NUMBER);
                        scanf("%s", entree1);
                    }
                    printf("Borne de droite :\n");
                    scanf("%s", entree2);
                    while(isNum(entree2) != 1)
                    {
                        printf(NOT_NUMBER);
                        scanf("%s", entree2);
                    }

                    if(atoi(entree1) > atoi(entree2)){printf("La borne de droite doit %ctre plus grande que la borne de gauche !\n", ECIRCONFLEXE);} //Erreur si l'utilisateur entre une borne de droite plus petite que la borne de droite
                    if((atoi(entree2) > temps_max) || (atoi(entree1) < temps_mini)){printf("L'intervalle ne peuvent pas d%cpasser les temps minimum et maximum de l'acquisition.\n", EACUTE);} //Erreur si l'utilisateur dépasse les maximum et/ou minimum de temps de l'acquisition
                }
                while(((atoi(entree1) > atoi(entree2)) || (atoi(entree2) > temps_max) || (atoi(entree1) < temps_mini))); //Tant qu'il y a des erreurs d'intervalle



                int borneInf = atoi(entree1), borneSup = atoi(entree2);

                if(poulMaxMin(*donnees, borneInf, borneSup, nbLigne) == 1) //Valide si l'intervalle contient bien des valeurs et recherche des pouls max et mini
                {
                    poulMoyen(*donnees, borneInf, borneSup, nbLigne); //Calcul du poul moyen

                    do //Affichage (ou non) des valeurs comprises dans l'intervalle
                    {
                        printf("=== Voulez-vous afficher les donn%ces de cet intervalle ? ===\n1 - Oui\n2 - Non\n", EACUTE);
                        scanf("%s", choix3);
                        while(isNum(choix3) != 1)
                        {
                            printf(NOT_NUMBER);
                            scanf("%s", choix3);
                        }
                        switch(atoi(choix3))
                        {
                            case 1:
                                afficherDonneesTemps(*donnees, borneInf, borneSup, nbLigne);
                                break;
                            case 2:
                                break;
                            default:
                                printf(ERREUR_MENU);
                                break;
                        }
                    }
                    while(atoi(choix3) != 2 && atoi(choix3) != 1);
                }


                break;
            case 4:
                break;
            default:
                printf(ERREUR_MENU);
                break;
        }
    }
    while(atoi(choix) != 4); //Si l'utilisateur entre "4" dans le menu principal, il quitte le programme

    return 0;
}