#include "Arduino.h"
#include "coeur.h"
#include "param.h"

// variable global
int LED[10]; // tableau contenant les pins de nos leds
short ledTaille; // contient le nombre de led

void initierLedPin(int pin[], int Taille) { // permet de passer les variables locales en globales au fichier 
  ledTaille = Taille;
  int i;
  for(i = 0; i < ledTaille; i++){
    LED[i] = pin[i];
    pinMode(pin[i], OUTPUT);
  }
}
 
void chenillard() //Allume les led 1 par 1
{
  int i; 
  for(i =0; i<ledTaille; i++)
  {
    digitalWrite(LED[i], HIGH);
    delay(1000);
    digitalWrite(LED[i], LOW); 
  }
}
void UneSurDeux() // Allume une led en allant de 2 en 2 
{
  int i; 
  for(i=0; i<ledTaille; i = i+2)
  {
    digitalWrite(LED[i], HIGH); 
    delay(1000);
    digitalWrite(LED[i], LOW);
  }
}
void UneSurTrois() // Allume une led en allant de 3 en 3 
{
  int i; 
  for(i=0; i<ledTaille; i = i+3)
  {
    digitalWrite(LED[i], HIGH); 
    delay(1000);
    digitalWrite(LED[i], LOW);
  }
}
void LedChoix(int n) // Allume une LED au choix préalablement choisi par l'utilisateur 
{
  digitalWrite(LED[n], HIGH); 
  delay(1000); 
  digitalWrite(LED[n], LOW); 
  delay(1000);
}
void ledRandom()
{
  int i = random(1,10);
  digitalWrite(LED[i], HIGH);
  delay(1000);
  digitalWrite(LED[i], LOW);
  delay(1000);
}
void menu() //Selectionne le mode d'affichage
{
    int n; 
  switch(MODE)
  {
    case 1 : 
    allLed(); 
    break;
    case 2 : 
    UneSurDeux();
    break;
    case 3 :
    UneSurTrois();
    break; 
    case 4 : 
    chenillard(); 
    break; 
    case 5 :
    n = CHOIX -1; 
    LedChoix(n);
    break; 
    case 6 : 
    ledRandom();
    break;
  }
}
