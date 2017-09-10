#include <Servo.h>
#include <math.h>

Servo servoX;  
Servo servoY;

int pos = 0;   

char ch;

void setup() {
  servoX.attach(9);
  servoY.attach(10);  
  
  Serial.begin(115200);

  pinMode(12,OUTPUT);
  analogWrite(12,10);
  
}

void loop() {
  //if (Serial.available()) {
 //ch = Serial.read();
 
  //}
  double circleSpeed = 200.0;
  servoX.write(20*(sin(millis()/circleSpeed) + 1)+40);
  
  servoY.write(1*(cos(millis()/circleSpeed) + 1)+10);
}
 
