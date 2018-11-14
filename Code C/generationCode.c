#include "generationCode.h"
void envoyerparam(int choix, int n)
{

    FILE* fichier = NULL;
    // On définit l'emplacement du param.h :
    fichier = fopen("param.h", "w");
    if(fichier != NULL)
    {
        //On écrit dans param.h le mode et la LED choisit par l'utilisateur   :
        fprintf(fichier,"#define MODE %d \n#define LED %d",choix,n);

        fclose(fichier);
    }

}