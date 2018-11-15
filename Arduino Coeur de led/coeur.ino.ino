#include "Arduino.h"
#include "coeur.h"

void setup(){
  //Serial.begin9600);
  int pins[] = {1,2,3,4,5,6,7,8,9,10};
  initierLedPin(pins, 10);

}

void loop(){
  menu();
}
