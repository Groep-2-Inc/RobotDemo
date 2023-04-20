#include <Arduino.h>
#include <comms.h>
#include <emergencyStop.h>

const int stopButtton = 8;

void setup() {
  pinMode(stopButtton, INPUT);

  Serial.begin(9600);
}

void loop() {
  checkStop(stopButtton);
}