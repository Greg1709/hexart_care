#include "menu.c"
#include "generationCode.c"

int main() {
    int choix, n;
    n = 0;
    menu(&choix, &n);        // L'utilisateur rentre les deux valeurs
    envoyerparam(choix, n);  // Generation du code vers param.h
}