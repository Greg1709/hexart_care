#include "menu.c"
#include "generationCode.c"
int main() {
    int choix, n;
    n = 0;
    menu(&choix, &n);
    envoyerparam(choix, n);
}