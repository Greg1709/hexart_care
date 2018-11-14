//From Arduino to Processing to Txt or cvs etc.
//import
import processing.serial.*;
//declare
PrintWriter output;
Table sortie;
Serial udSerial;

void setup() {
  udSerial = new Serial(this, Serial.list()[0], 9600);
  output = createWriter ("Battements.csv");
  sortie = new Table();
  sortie.addColumn("poul");
  sortie.addColumn("temps en ms");
}

  void draw() {
    if (udSerial.available() > 0) {
      String SenVal = udSerial.readString();
      if (SenVal != null) {
        TableRow newRow = sortie.addRow();
        newRow.setString("poul",SenVal);
        newRow.setString("temps en ms",SenVal);
        saveTable(sortie, "Battements.csv");
        if (sortie.getRowCount() == 100) {
          saveTable(sortie, "Battements.csv");
          output.flush();
          output.close();
          exit(); 
        }
      }
    }
  }
