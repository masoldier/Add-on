#include<LiquidCrystal.h>
LiquidCrystal lcd(13,12,8,7,4,2);
const unsigned int TRIG_PIN=5;
const unsigned int ECHO_PIN=6;
const unsigned int BAUD_RATE=9600;


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  Serial.begin(BAUD_RATE);
  lcd.begin(16,2);
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  

 const unsigned long duration= pulseIn(ECHO_PIN, HIGH);
 int distance= duration/29/2;
 if(duration==0){
   Serial.println("Warning: no pulse from sensor");
   lcd.clear();
   lcd.print("WARNING");
   } 
  else{
      lcd.setCursor(0,0);
      lcd.clear();
      lcd.print("Distance");
      Serial.print("distance to nearest object:");
      Serial.println(distance);
      Serial.println(" cm");
      lcd.setCursor(0,1);
      lcd.print(distance);
      lcd.print("cm");
      lcd.setCursor(0,0);
  }
 delay(100);
 }
