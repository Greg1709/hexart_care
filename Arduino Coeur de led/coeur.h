#ifndef COEUR_H
#define COEUR_H
#ifdef __cplusplus
extern "C" {
#endif

// Intitialise les LED comme étant en SORTIE
void initierLedPin(int pin[], int Length);
//Allume toute les LED
void allLed();
void UneSurDeux();
void UneSurTrois();
void chenillard();
void LedChoix(int n); 
void ledRandom();
//Affiche le menu : 
void menu();
#ifdef __cplusplus
} // extern "C"
#endif
#endif
