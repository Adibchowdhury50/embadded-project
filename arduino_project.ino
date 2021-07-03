#define RELAY_ON 0
#define RELAY_OFF 1
#define RELAY_1 4
#include <Servo.h>
Servo servo1;
int trigPin = 9;
int trigPin1 = 10;
int echoPin = 8;
int echoPin1 = 11;
long distance;
long distance1;
long duration;
char data = 0;
int const buzzPin = 2;
void setup() {
// Set pin as output.
pinMode(RELAY_1, OUTPUT);
// Initialize relay one as off so that on reset it would be off by default
digitalWrite(RELAY_1, RELAY_OFF);
Serial.begin(9600);
Serial.print("Type: 1 to turn on bulb. 0 to turn it off!");
pinMode(trigPin, OUTPUT); // trig pin will have pulses output
pinMode(echoPin, INPUT); // echo pin should be input to get pulse width
pinMode(buzzPin, OUTPUT);

{
servo1.attach(7); 
 pinMode(trigPin1, OUTPUT);
 pinMode(echoPin1, INPUT);
}
} 
void loop() {
if (Serial.available() > 0) {
data = Serial.read(); //Read the incoming data and store it into variable data
Serial.print(data); //Print Value inside data in Serial monitor
Serial.print("\n"); //New line
if(data == '1'){
digitalWrite(RELAY_1, RELAY_ON);
Serial.println("Bulb is now turned ON.");
}
else if(data == '0'){
digitalWrite(RELAY_1, RELAY_OFF);
Serial.println("Bulb is now turned OFF.");
}
}
int duration, distance;
// Output pulse with 1ms width on trigPin
digitalWrite(trigPin, HIGH);
delay(1);
digitalWrite(trigPin, LOW);
// Measure the pulse input in echo pin
duration = pulseIn(echoPin, HIGH);
// Distance is half the duration devided by 29.1 (from datasheet)
distance = (duration/2) / 29.1;
// if distance less than 0.5 meter and more than 0 (0 or less means over range)
if (distance <= 12 && distance >= 0) {
// Buzz
digitalWrite(buzzPin, HIGH);
} else {
// Don't buzz
digitalWrite(buzzPin, LOW);
}
// Waiting 60 ms won't hurt any one
delay(60);
{
  ultra();
  servo1.write(0);
  if(distance1 <= 8){
  servo1.write(180);
  }
}
}
void ultra(){
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration = pulseIn(echoPin1, HIGH);
  distance1 = duration*0.034/2;
  }
