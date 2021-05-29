#include "LiquidCrystal.h"

const int rs = 1, en = 2, d4 = 4, d5 = 5, d6 =6, d7 = 7;
const int button1pin=14, button2pin=15, button3pin=16, button4pin=17, speakerPin=19;

int buttonState1,buttonState2,buttonState3,buttonState4,lastButtonState1,lastButtonState2,lastButtonState3,lastButtonState4;
int lastButtonState;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

int s,m=1;
unsigned long long Time1,Time2;
char mode=1;

int buttonPin;
int risingedge(int buttonPin);

void setup() {
  lcd.begin(16,2);

  pinMode(speakerPin, OUTPUT);
  pinMode(button1pin,INPUT_PULLUP);
  pinMode(button2pin,INPUT_PULLUP);
  pinMode(button3pin,INPUT_PULLUP);
  pinMode(button4pin,INPUT_PULLUP);
  
  Time1=millis(); 
}

void loop() {
 Time2=millis();

  lcd.setCursor(6,0);
  lcd.print(m);
  lcd.print(":");
  if (s<10) lcd.print("0");
  lcd.print(s);

  buttonState1=digitalRead(button1pin);
  buttonState2=digitalRead(button2pin);
  buttonState3=digitalRead(button3pin);
  buttonState4=digitalRead(button4pin);

  if (buttonState1 != lastButtonState1) {
    noTone(speakerPin);
    if (buttonState1 == HIGH) {
      if(mode!=1) mode =1;
      else mode =0;
    }
  }
  lastButtonState1 = buttonState1;
  
  if (buttonState2 != lastButtonState2) {
    noTone(speakerPin);
    if (buttonState2 == HIGH) {
      mode =2;
    }
  }
  lastButtonState2 = buttonState2; 
 
 if (mode==1){
  if(Time2-Time1>1000){
    Time1=millis();
    s-=1;
  }
  lcd.setCursor(0,0);
  lcd.print("START");
 }
 
 if (mode==0){
  lcd.setCursor(0,0);
  lcd.print("STOP ");
 }

 if (mode==2){
  lcd.setCursor(0,0);
  lcd.print("SET  ");
  
   if (buttonState3 != lastButtonState3) {
    if (buttonState3 == HIGH) {
    noTone(speakerPin);
      s+=5;
    }
  }
  lastButtonState3 = buttonState3;

  if (buttonState4 != lastButtonState4) {
    if (buttonState4 == HIGH) {
    noTone(speakerPin);
      s-=5;
    }
  }
  lastButtonState4 = buttonState4;
 }

 if(s==0 && m==0 && mode ==1) {
  mode = 0;
  m=1;
  tone(speakerPin,440);
 }
 if (s>=60){
  s= s%60;
  m+=1;
 }
 if (s<0){
  s= 60+s;
  m-=1;
 }
 if(m<0) m=0;
 if(mode>2 || mode<0) mode = 1;
}
