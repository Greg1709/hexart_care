#include "param.h"
#include "coeur.h"

int led_rouge[10]={1,2,3,4,5,6,7,8,9,10};


void setup() {
  int i = 0;
   for(i=0; i<10; i++)
    {
      pinMode(led_rouge[i], OUTPUT);
    }
}

void loop() {
  if(MODE == 1)
  {
    toutes_leds();
  }

  else if(MODE == 2)
  {
    led_sur_deux();
  }

  else if(MODE == 3)
  {
    led_sur_trois();
  }

  else if(MODE == 4)
  {                                                                    
    chenille();
  }

  else if(MODE == 5)
  {
    n= LED-1; 
    Une_LED_au_choix(n);
  }
}
