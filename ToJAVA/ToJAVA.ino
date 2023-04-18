void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

int leesPotMeterwaarde(){
  int waarde = analogRead(A5);
  int resultaat = map(waarde, 0, 1023, 69, 421);
  Serial.print(resultaat);
  return resultaat;
}

void loop() {
  leesPotMeterwaarde();
}
