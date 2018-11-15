#include "menu.c"
#include "generationCode.c"

int main() {
    char choix[TAILLE], n[TAILLE];
    menu(choix, n);        // L'utilisateur rentre les deux valeurs
    envoyerparam(*choix, *n);  // Generation du code vers param.h
}