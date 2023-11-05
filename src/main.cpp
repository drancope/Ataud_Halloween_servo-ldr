//#include <Wire.h>
#include <Arduino.h>
#include <Servo.h>
#define TARGET 1 // 0 = nano; 1 = pro-mini; 2 = esp8266
#if TARGET == 0
  #define UMBRAL 200
  #define PINMOTOR 9
#elif TARGET == 1
  #define UMBRAL 800
  #define PINMOTOR 9
#else
  #define UMBRAL 200
  #define PINMOTOR 3
#endif

Servo myservo;  // create servo object to control a servo

void setup() {
  myservo.attach(PINMOTOR);  // attaches the servo on pin 9 to the servo object
  pinMode(A0, INPUT);
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  int valor = analogRead(A0);
  Serial.print("sensor = ");
  Serial.println(valor);
   if (valor > UMBRAL) {
    myservo.write(5);                  // sets the servo position according to the scaled value
    digitalWrite(LED_BUILTIN, HIGH);
    delay(2015);      
  } else {                    // waits for the servo to get there
    myservo.write(160);                   // sets the servo position according to the scaled value                          // waits for the servo to get there
    digitalWrite(LED_BUILTIN, LOW);
  }
  delay(500);
}