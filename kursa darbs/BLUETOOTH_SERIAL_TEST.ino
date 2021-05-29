#include <NeoSWSerial.h>


#include <Servo.h>

const byte numChars = 32;
char receivedChars[numChars];   // an array to store the received data
String bt = "";
boolean newData = 0;

Servo myServo;
NeoSWSerial mySerial( 15, 14 );
char open = 0;

//PAROLE
String pass = "parole123";

void setup() {
  // put your setup code here, to run once:
  mySerial.begin(9600);
  Serial.begin(9600);
  myServo.attach(3);
}



void loop() {

while (Serial.available() > 0) {
    Serial.read();
}


  String bt = mySerial.readString();
  Serial.println(bt);

  noTone(9);

  while(bt==pass){
      tone(9,600);
      
      if (open==1) {
        myServo.write(90);
        open = 0 ;
      } else {
        myServo.write(180);
        open = 1 ;
      }
      bt = "";

  }

}
