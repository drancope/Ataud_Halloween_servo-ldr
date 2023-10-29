//#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  pinMode(A0, INPUT);
  //Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int valor = analogRead(A0);
  //Serial.print("sensor = ");
  //Serial.println(valor);
   if (valor > 600) {
    myservo.write(10);                  // sets the servo position according to the scaled value
    delay(2015);      
    digitalWrite(LED_BUILTIN, HIGH);
  } else {                    // waits for the servo to get there
    myservo.write(100);                  // sets the servo position according to the scaled value                          // waits for the servo to get there
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(500);
}