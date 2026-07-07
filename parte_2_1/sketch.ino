#include <ESP32Servo.h>

Servo servo;

const int servoPin = 18;
const int potPin = 34;

void setup() {

  Serial.begin(115200);

  servo.attach(servoPin);

}

void loop() {

  int leitura = analogRead(potPin);

  int angulo = map(leitura,0,4095,0,180);

  servo.write(angulo);

  Serial.print("ADC: ");
  Serial.print(leitura);

  Serial.print("  Angulo: ");
  Serial.println(angulo);

  delay(20);

}