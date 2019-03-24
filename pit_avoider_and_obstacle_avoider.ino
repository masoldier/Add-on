int ls;
int cs;
int rs;
int us=9;
int lmt1=5;
int lmt2=3;
int rmt1=6;
int rmt2=11;

void setup() {
  // put your setup code here, to run once:
 
  pinMode(4,INPUT);
  pinMode(2,OUTPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(lmt1, OUTPUT);
  pinMode(lmt2, OUTPUT);
  pinMode(rmt1, OUTPUT);
  pinMode(rmt2, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(2, LOW);
  delayMicroseconds(2);
  digitalWrite(2, HIGH);
  delayMicroseconds(10);
  digitalWrite(2, LOW);
  

 const unsigned long duration= pulseIn(4, HIGH);
 int distance= duration/29/2;

 
  ls=digitalRead(7);
  cs=digitalRead(8);
  rs=digitalRead(9);
if(distance>us){
  Serial.println("Forward");
   forward();
}
else if(distance<us){
   reverse();
    delay(150);
    left();
    delay(150);
    Serial.println("Backward");
 
}
  if(ls==HIGH&&cs==HIGH&&rs==HIGH){
    //Serial.println("Forward");
    forward();
  }
  else if (ls==HIGH&&cs==LOW&&rs==HIGH){
    reverse();
    delay(150);
    left();
    delay(150);
    //Serial.println("Backward");
  }
  else if (ls==LOW&&cs==HIGH&&rs==HIGH){
    right();
  }
  else if (ls==HIGH&&cs==HIGH&&rs==LOW){
    left();
   }
  else if (ls==LOW&&cs==HIGH&&rs==LOW){
    reverse();
    delay(150);
    left();
    delay(150);
  } 
  else if (ls==LOW&&cs==LOW&&rs==HIGH){
    reverse();
    delay(150);
    right();
    delay(150);
  }
  else if (ls==HIGH&&cs==LOW&&rs==LOW){
    reverse();
    delay(150);
    left();
    delay(150);
  }
  else if (ls==LOW&&cs==LOW&&rs==LOW){
    reverse();
    delay(150);
    left();
    delay(150);
  }
}

void forward(){
  analogWrite(lmt1,127);
  digitalWrite(lmt2,LOW);
  analogWrite(rmt1,127);
  digitalWrite(rmt2,LOW);
}

void reverse(){
  digitalWrite(lmt1,LOW);
  analogWrite(lmt2,127);
  digitalWrite(rmt1,LOW);
  analogWrite(rmt2,127);
}

void left(){
  digitalWrite(lmt1,LOW);
  analogWrite(lmt2,127);
  analogWrite(rmt1,127);
  digitalWrite(rmt2,LOW);
}

void right(){
  analogWrite(lmt1,127);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  analogWrite(rmt2,127);
}

void stp(){
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,LOW);
}

void stpleft(){
  digitalWrite(lmt1,LOW);
  digitalWrite(lmt2,LOW);
  analogWrite(rmt1,127);
  digitalWrite(rmt2,LOW);
}

void stpright(){
  analogWrite(lmt1,127);
  digitalWrite(lmt2,LOW);
  digitalWrite(rmt1,LOW);
  digitalWrite(rmt2,LOW);
  
}

