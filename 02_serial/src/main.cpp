#include <Arduino.h>
#include <SoftwareSerial.h>
#include "config.h"


SoftwareSerial Serial(RX_PIN, TX_PIN);

int measure();

void setup()
{
  pinMode(IRLED_PIN, OUTPUT);
  pinMode(IRDIODE_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Connection ready...");
}

void loop()
{
  Serial.println(measure)
}


// Get value from ir sensor
int measure()
{
  digitalWrite(IRLED_PIN, HIGH);
  digitalWrite(IRDIODE_PIN, HIGH);
  delay(10);

  int measure = analogRead(IRSENS_PIN);

  digitalWrite(IRDIODE_PIN, LOW);
  digitalWrite(IRLED_PIN, LOW);
  delay(10);

  return measure;
}