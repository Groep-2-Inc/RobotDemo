unsigned long startTijd = 0; // buiten loop

void setup() {
  // put your setup code here, to run once:
  pinMode(A5, INPUT);
  Serial.begin(9600);
}

int leesPotMeterwaarde(){
  int waarde = analogRead(A5);
  int resultaat = map(waarde, 0, 1023, 69, 421);
  Serial.println(resultaat);
  return resultaat;
}

void loop() {
  if(millis() - startTijd > 100){
    leesPotMeterwaarde();
    startTijd = millis();
  }
}
