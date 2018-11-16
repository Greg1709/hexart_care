#ifndef COEUR_H
#define COEUR_H
#ifdef __cplusplus
extern "C" {
#endif

// Intitialise les LED comme étant en SORTIE
void initierLedPin(int pin[], int Length);
//Allume toute les LED
void allLed(int temps);
//Allume une led sur deux
void UneSurDeux(int temps);
//Allume une led sur trois
void UneSurTrois(int temps);
//Allume une led une par une 
void chenillard(int temps);
//allume une led aux choix 
void LedChoix(int n, int temps); 
//Autre forme de chenillards
void uneParUne(int temps); 
//Affiche le menu : 
void menu(int temps);
#ifdef __cplusplus
} // extern "C"
#endif
#endif
