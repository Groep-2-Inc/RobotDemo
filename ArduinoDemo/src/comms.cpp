// Hoofdbestand dat met de HMI communiceert
#include <Arduino.h>
#include <ArduinoJson.h>

// Print een status- en waardetekst naar de Serial
// status -> een code die kan worden geïnterpreteerd door de HMI-applicatie
// value -> de waarde die extra context kan geven
void toJava(int status, String value){
    // Maakt een nieuw json object
    StaticJsonDocument<200> json;

    // Zet de juiste waardes
    json["code"] = status;
    json["value"] = value;

    // Print het json object naar de Serial
    serializeJson(json, Serial);
}

//Comms voorbeeld
/*
int waarde = 420;
toJava(200, String(420), ""); --> {"code":200,"value":"420"}

Sring tekst = "NOODSTOP INGEDRUKT";'
toJava(500, tekst, ""); --> {"code":500,"value":"NOODSTOP INGEDRUKT"}
*/