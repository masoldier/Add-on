/* Arduino code for displaying LM35 
Temprature sensor reading on the serial monitor */

// connect OUT pin of sensor module to A0 of SPduino
const int tempPin = A0;

// initialize the required variables
int temp = 0;
float cel = 0;

void setup() 
{
  // set A0 as an INPUT pin
  pinMode(tempPin, INPUT);
  // begin serial communication
  Serial.begin(9600);
}

void loop() 
{
  // Get the temprature reading and store it in a variable
  temp = analogRead(A0);
 
  // convert sensor reading into degrees celsius
  float cel = (temp/1024.0)*500;
  
  // print the calculated value on the serial monitor
  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.println("*C");
  delay(1000);
}
