void toutes_leds()
{

  int led_rouge[]={1,2,3,4,5,6,7,8,9,10};
  int temps = 500;
  int i; 
  for(i =0; i<10; i++)
  {
    digitalWrite(led_rouge[i],1);
  }
  
  delay(temps);

  
  for(i =0; i<10; i++)
  {
    digitalWrite(led_rouge[i],0);
  }
  delay(temps);
}

void chenille()
{
 int i = 0;
 int led_rouge[]={1,2,3,4,5,6,7,8,9,10};
 int temps = 500;

  for(i = 0; i < 10; i++)
  {
    digitalWrite(led_rouge[i], 1);
    delay(temps);
    digitalWrite(led_rouge[i], 0);
    delay(temps);
  }
}

void led_sur_deux()
{
  int led_rouge[]={2,3,4,5,6,7,8,9,10,11};
  int temps = 500;
  int i; 

   for(i=0; i<10; i= i+2)
   {
    digitalWrite(led_rouge[i], 1);
   }
  delay(temps);

 
   for(i=0; i<10; i= i+2)
   {
    digitalWrite(led_rouge[i], 0);
   }
  delay(temps);
}

void led_sur_trois()
{
  int led_rouge[]={2,3,4,5,6,7,8,9,10,11};
  int temps = 500;
  int i;
   for(i=0; i<10; i= i+3)
   {
    digitalWrite(led_rouge[i], 1);
   }
  delay(temps);

 
   for(i=0; i<10; i= i+3)
   {
    digitalWrite(led_rouge[i], 0);
   }
  delay(temps);
}

void Une_LED_au_choix(int n)
{
  int led_rouge[]={1,2,3,4,5,6,7,8,9,10};
  int temps = 500;

  digitalWrite(led_rouge[n], 1);
  delay(temps);

  digitalWrite(led_rouge[n], 0);
  delay(temps);
}
