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
 
void chenillard(int temps) //Allume les led 1 par 1
{
  int i; 
  for(i =0; i<ledTaille; i++)
  {
    digitalWrite(LED[i], HIGH);
    delay(temps);
    digitalWrite(LED[i], LOW); 
  }
}
void UneSurDeux(int temps) // Allume une led en allant de 2 en 2 
{
  int i; 
  for(i=0; i<ledTaille; i = i+2)
  {
    digitalWrite(LED[i], HIGH); 
    delay(temps);
    digitalWrite(LED[i], LOW);
  }
}
void UneSurTrois(int temps) // Allume une led en allant de 3 en 3 
{
  int i; 
  for(i=0; i<ledTaille; i = i+3)
  {
    digitalWrite(LED[i], HIGH); 
    delay(temps);
    digitalWrite(LED[i], LOW);
  }
}
void LedChoix(int n, int temps) // Allume une LED au choix préalablement choisi par l'utilisateur 
{
  digitalWrite(LED[n], HIGH); 
  delay(temps); 
  digitalWrite(LED[n], LOW); 
  delay(temps);
}
void allLed(int temps)
{
  int i; 
  for(i = 0; i< ledTaille; i++)
 {
  digitalWrite(LED[i], HIGH);
  
 }
 delay(temps); 
 for(i = 0; i<ledTaille; i++)
 {
  digitalWrite(LED[i], LOW); 
  
 }
}
void uneParUne(int temps)
{
  int i; 
  for(i=0; i<ledTaille; i++)
  {
    digitalWrite(LED[i], HIGH);
    delay(temps);
  }
  for(i=0; i<ledTaille; i++)
  {
    digitalWrite(LED[i], LOW); 
    delay(temps); 
  }
}
void menu(int temps) //Selectionne le mode d'affichage
{
    int n; 
  switch(MODE)
  {
    case 1 : 
    allLed(temps); 
    break;
    case 2 : 
    UneSurDeux(temps);
    break;
    case 3 :
    UneSurTrois(temps);
    break; 
    case 4 : 
    chenillard(temps); 
    break; 
    case 5 :
    n = CHOIX -1; 
    LedChoix(n,temps);
    break; 
    case 6 : 
    uneParUne(temps); 
    
  }
}
