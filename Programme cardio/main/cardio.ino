#include "cardio.h"

// Fonction qui permet de trouver le pouls toute les 2 secondes et fait la moyenne du pouls en 1 minute.
int pulsion() 
{
  int pouls = 0;
  int temps1 = millis();
  int temps2 = millis();

  // On prends le pouls toute les 2 secondes.
  while (temps2 - temps1 < 2000) 
  {
    // On va exécuter une moyenne des valeurs obtenus de moy1 et moy2 pour définir un seuil à atteindre
    // pour considérer qu'il y a bien une pulsation.
    int moy1 = analogRead(A0);
    delay(10);
    int moy2 = analogRead(A0);
    int moyenne = (moy1 + moy2) / 2;
    int valeur = analogRead(A0);

    if (valeur > moyenne)
    {
      pouls++;
    }
    temps2 = millis();
    delay(100);
  }
  pouls *= 12;

  return pouls;
}
