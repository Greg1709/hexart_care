//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Serial udSerial;
int compteur = 0;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");
}

  void draw() {
    
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        compteur++;
        output.println(SenVal);
      }
      if (compteur == 100) {
        output.flush();
        output.close();
        exit(); 
      }
    }
  }
  
  void keyPressed(){
    output.flush();
    output.close();
    exit(); 
  }
