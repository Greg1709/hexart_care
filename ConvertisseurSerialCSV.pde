//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
int compteur = 0;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 1500000);
  output = createWriter ("Battements.csv");
}

  void draw() {
    
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      println(compteur);
      if (compteur == 99) {
        output.flush();
        output.close();
        exit(); 
      }
      if (SenVal != null) {
        compteur++;
        output.println(SenVal);
      }
    }
  }
  
  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }
