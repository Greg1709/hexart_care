#include "menu.h"
#include "generationCode.h"
void menu(char * choiceUser, char * scdChoice)
{

    // Affichage du menu:
    printf("--------- Veuillez choisir votre d'affichage :  --------- \n 1.Allumer toutes les Leds \n 2. 1 Led sur 2 \n 3. 1 Led sur 3 \n 4. Chenillard \n 5. Une led aux choix  \n ");
    scanf("%s", choiceUser);
    checkNumber(choiceUser);
    while (atoi(choiceUser) <1 || atoi(choiceUser) > 5 || checkNumber(choiceUser) != 1) // Boucle qui demande à l'utilisateur de rentrer un nombre correct
    {
        printf("Veuillez choisir un nombre correspondant au menu \n");
        scanf("%s", choiceUser);
    }

    if(atoi(choiceUser) == 5 || checkNumber(scdChoice) != 1) //Choix d'une LED à allumer
    {
        do
        {
            printf("Attention vous devez choisir un nombre inf%crieur %c 10 ou sup%crieur %c 0 \n",130,133,130,133);
            scanf("%s", scdChoice);
        }while(*scdChoice<10 && *scdChoice>0);
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