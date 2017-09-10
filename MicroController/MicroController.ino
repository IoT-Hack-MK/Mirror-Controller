#include <Servo.h>
#include <math.h>

#define X_MIN 62
#define X_MAX 76

#define Y_MIN 80
#define Y_MAX 90

Servo servoX;
Servo servoY;

int pos = 90;

char ch;

void setup() {
  servoX.attach(9);
  servoY.attach(10);

  Serial.begin(115200);

  pinMode(12, OUTPUT);
  analogWrite(12, 0);

}

void loop() {
  if (Serial.available()) {
    ch = Serial.read();
    if (ch == 'l') {
        analogWrite(12, 255);
    }
      if (ch == 'o') {
        analogWrite(12, 0);
    }
    if (ch == 's') {
      Serial.println("Scanning");
      for (int y = Y_MIN; y < Y_MAX; y++) {

        for (int x = X_MIN; x < X_MAX; x++) {

          servoX.write(x);
          Serial.print(x);
          Serial.print(" ");

          servoY.write(y);
          Serial.println(y);
          delay(25);


        }
      }

    }
    if (ch == 'h') {
      Serial.println("Returning to Home Position");
      servoX.write(69);
      servoY.write(86);
    }


  }
  //double circleSpeed = 200.0;
  //servoX.write(20*(sin(millis()/circleSpeed) + 1)+40);
  //servoX.write(100);//

  //76 to 62 deg middle is 69
  //96 to 76 for Y, middle is about 86
}

