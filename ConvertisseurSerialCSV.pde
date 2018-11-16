//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
int compteur = 0;

void setup() {
  // On ouvre le port (udSerial) qu'on utilise (9600) :
  udSerial = new Serial(this, Serial.list()[0], 116000);
  // On crée un ficher où on indique le lieu où on va écrire :
  output = createWriter ("Battements.csv");
}

  void draw() {
    // Si la méthode .available renvoie une estimation
    // du nombre d’octets restants (pouvant être lus) supérieur à 0 alors... :
    if (udSerial.available() > 0) {
       // Senval prends la valeur des données de udSerial sous forme
       // de chaîne ou null s'il n'y a rien de disponible :
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        // On ajoute 1 au compteur
        // On écrit la valeur de Senval dans output (qui se nommera "Battements.cvs") :
        compteur++;
        output.println(SenVal);
      }
      if (compteur == 50) {
        // Si le compteur est égal à 50 alors on vide les buffers d'écriture, 
        //ferme le fichier et quitte le programme :
        output.flush();
        output.close();
        exit(); 
      }
    }
  }
  // Permet de vider les buffers d'écriture vers le médium de sortie,
  // de fermer le fichier et terminer le programme si une touche du clavier est pressée :
  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }
