#include "generationCode.h"
void envoyerparam(int choix, int n)
{

    FILE* fichier = NULL;
    fichier = fopen("param.h", "w");
    if(fichier != NULL)
    {
        fprintf(fichier,"#define MODE %d \n#define INTERVALLE %d",choix,n);

        fclose(fichier);
    }

}