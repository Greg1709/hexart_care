#include "menu.h"
#include "generationCode.h"
void menu(int *choiceUser, int *scdChoice)
{
    printf("--------- Veuillez choisir votre d'affichage :  --------- \n 1.Allumer toutes les Leds \n 2. 1 Led sur 2 \n 3. 1 Led sur 3 \n 4. Chenillard \n 5. Une led aux choix  \n ");
    scanf("%d",choiceUser);

    if(*choiceUser == 5)
    {
        printf("Veuillez choisir l'intervalle de led à allumer \n");
        scanf("%d", scdChoice);

    }

}