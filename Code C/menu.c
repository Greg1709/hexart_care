#include "menu.h"
#include "generationCode.h"
void menu(char * choiceUser, char * scdChoice)
{

    // Affichage du menu:
    printf("--------- Veuillez choisir votre d'affichage :  --------- \n 1.Allumer toutes les Leds \n 2. 1 Led sur 2 \n 3. 1 Led sur 3 \n 4. Chenillard \n 5. Une led aux choix  \n 6.Autres forme de chenillard \n");
    scanf("%s", choiceUser);

    while (atoi(choiceUser) <1 || atoi(choiceUser) > 6 || checkNumber(choiceUser) != 1) // Boucle qui demande à l'utilisateur de rentrer un nombre correct
    {
        printf("Veuillez choisir un nombre correspondant au menu \n");
        scanf("%s", choiceUser);
    }

    if(atoi(choiceUser) == 5 || checkNumber(scdChoice) != 1) //Choix d'une LED à allumer
    {
        scanf("%s", scdChoice);
        while (atoi(scdChoice) <1 || atoi(scdChoice) > 10 || checkNumber(choiceUser) != 1) {

                printf("Veuillez choisir un nombre correspondant au menu \n");
                scanf("%s", scdChoice);


        }

    }
}

int checkNumber(char check[]) // Vérifie si le chiffre entrée dans le char est bien un nombre
{
    int i;
    for(i = 0; check[i] != '\0'; i++ )
    {
        if(check[i]<48 || check[i]>57) //Si les nombres ne correspondent pas au code ASCII
        {
            return 0;
        }

    }
    return 1;

}