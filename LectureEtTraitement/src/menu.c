//
// Created by Etienne on 09/11/2018.
//

#include "../inc/menu.h"

void menuPrincipal()
{
    printf("=== MENU ===\n");
    printf("1 - Afficher les donn%ces du fichier CVS (dans l'ordre)\n", EACUTE);
    printf("2 - Afficher les donn%ces dans un certain ordre\n", EACUTE);
    printf("3 - Afficher des donn%ces sur une plage de temps\n", EACUTE);
    printf("4 - Quitter le programme\n");
}

void menuOrdre()
{
    printf("=== Affichage des donn%ces dans l'ordre : ===\n", EACUTE);
    printf("1 - Croissant\n");
    printf("2 - D%ccroissant\n", EACUTE);
    printf("3 - Retour\n");
}