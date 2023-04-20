#include <Arduino.h>
#include <comms.h>
#include <emergencyStop.h>

const int stopButtton = 8;

void setup() {
  pinMode(stopButtton, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // checkStop(stopButtton);

  if(fromJava()["status"] == 200){
    digitalWrite(8, HIGH);
  };
}