int LED_PINS[] = {2, 3, 4, 5, 6, 7, 8};

void setup() {
  for(int i=0; i < 7; i++){
    pinMode(LED_PINS[i], OUTPUT);
  }

  Serial.begin(9600); // used to receive digits from the Java application
}

void toonGetal(int getal){
  int GETALLEN[10][7]{
    //A    B     C     D     E     F     G
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, LOW}, // 0
    {LOW, HIGH, HIGH, LOW, LOW, LOW, LOW}, // 1
    {HIGH, HIGH, LOW, HIGH, HIGH, LOW, HIGH}, // 2
    {HIGH, HIGH, HIGH, HIGH, LOW, LOW, HIGH}, // 3
    {LOW, HIGH, HIGH, LOW, LOW, HIGH, HIGH}, // 4
    {HIGH, LOW, HIGH, HIGH, LOW, HIGH, HIGH}, // 5
    {HIGH, LOW, HIGH, HIGH, HIGH, HIGH, HIGH}, // 6
    {HIGH, HIGH, HIGH, LOW, LOW, LOW, LOW}, // 7
    {HIGH, HIGH, HIGH, HIGH, HIGH, HIGH, HIGH}, // 8
    {HIGH, HIGH, HIGH, LOW, LOW, HIGH, HIGH} // 9
  };

  for(int i=0; i < 7; i++){
    digitalWrite(LED_PINS[i], GETALLEN[getal][i]);
  }
}

void loop() {
  if (Serial.available() > 0) {
    byte incomingByte = 0;
    incomingByte = Serial.read();

    toonGetal(incomingByte);
  }
}