import processing.serial.*;
import meter.*;
Serial port;
Meter m;
float voltage = 0;

void setup() {
  size(440, 260);
  background(0,0,0);
  port = new Serial(this, "COM4", 9600);
  port.bufferUntil('\n');
  
  m = new Meter(this, 0, 0);
  m.setMinInputSignal(0);
  m.setMaxInputSignal(1023);
  m.setMaxScaleValue(5);
  m.setTitle("Spriegums uz A6 pin, V");
}

void serialEvent (Serial port){
 voltage=float(port.readStringUntil('\n'));
}

void draw(){
 m.updateMeter(int((voltage)));
}
