// Hoofdbestand dat met de HMI communiceert
#include <Arduino.h>
#include <ArduinoJson.h>

// Print een status- en waardetekst naar de Serial
// status -> een code die kan worden geïnterpreteerd door de HMI-applicatie
// value -> de waarde die extra context kan geven
void toJava(int status, String value){
    // Maakt een nieuw json object
    StaticJsonDocument<200> returnJson;

    // Zet de juiste waardes
    returnJson["code"] = status;
    returnJson["value"] = value;

    // Print het json object naar de Serial
    serializeJson(returnJson, Serial);
}

//Comms voorbeeld
/*
    int waarde = 420;
    toJava(200, String(420), ""); --> {"code":200,"value":"420"}

    Sring tekst = "NOODSTOP INGEDRUKT";'
    toJava(500, tekst, ""); --> {"code":500,"value":"NOODSTOP INGEDRUKT"}
*/

StaticJsonDocument<200> fromJava() {
  StaticJsonDocument<200> json;

  if (Serial.available() > 0) {
    // Leest de bytes van de seriële poort
    // char buffer[200];
    // int bytesRead = Serial.readBytes(buffer, sizeof(buffer));

    String txt = Serial.readString();

    // Decodeer de bytes naar een JSON-document
    DeserializationError error = deserializeJson(json, txt);

    // Controleer of de decoding gelukt is
    if (error) {
        Serial.println("Fout bij decoderen van JSON: " + String(error.c_str()));
        digitalWrite(9, HIGH);
    } else {
        // Geef het JSON-document terug
        digitalWrite(8, HIGH);
        return json;
    }
  }

  // Als er geen gegevens zijn, geef dan een leeg JSON-document terug
  return json;
}