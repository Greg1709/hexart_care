#include "cardio.h"

// On initialise le Serial avec 115200 bauds :
void setup() 
{
  Serial.begin(115200);
}

// On appele la fonction pulsions pour obtenir le pouls puis on l'envoie vers le processing,
// on sépare l'information avec un ";" puis on envoie le temps en milliseconde.
void loop() {

  int pouls;
  pouls = pulsion();
  
  Serial.print(pouls);
  Serial.print(";");
  Serial.println(millis());
  delay(1);
}
