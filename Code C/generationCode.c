#include "generationCode.h"
void envoyerparam(char mode, char led)
{

    FILE* fichier = NULL;
    // On définit l'emplacement du param.h :
    fichier = fopen("app/param.h", "w");
    if(fichier != NULL)
    {
        //On écrit dans param.h le mode et la LED choisit par l'utilisateur   :
        fprintf(fichier,"#define MODE %d \n#define LED %d",atoi(&mode),atoi(&led)); // Une convertion de char vers int et restitution

        fclose(fichier);
    }

}