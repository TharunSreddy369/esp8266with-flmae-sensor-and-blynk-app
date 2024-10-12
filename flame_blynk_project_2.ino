
#include <ESP8266WiFi.h>  //Declarate ESP8266 Board Library

#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL3BqYPa3P5"
#define BLYNK_TEMPLATE_NAME "flame detection"
#define BLYNK_AUTH_TOKEN "fpDRhIaImNFhBOn1FYk0PjQpCTNUcLzM"



char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Abcd";  // put your mobile Wifi name 
char pass[] = "123456789";  //Put your Password of your connection passward

int buzzer = 2;//D4 pin in esp8266

int state = HIGH;
int flame_pin = 16;//D0 in esp 8266 board

unsigned long previousMillis = 0;

int flamval;

int Alert_Val = 0;

BlynkTimer timer;


void flame() {
  flamval = digitalRead(flame_pin);
  if (flamval != 0) {
    Blynk.virtualWrite(V1, LOW);
  } else {
    Blynk.virtualWrite(V1, HIGH);
  }
}


void alert_situation() {
  unsigned long currentMillis = millis();
  unsigned long previousMillis1;
  unsigned long previousMillis2;
  unsigned long previousMillis3;
  unsigned long previousMillis4;
  unsigned long previousMillis5;
  unsigned long previousMillis6;
  if (flamval != 1) {
  

    if (state != LOW) {
      tone(buzzer, 1000, 200);
      if (currentMillis - previousMillis1 >= 1000) {
        Blynk.logEvent("flame_detection");
      }
      previousMillis1 = currentMillis;
    }
    
  }
}
void setup() {
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass, "blynk.cloud",80);  //Connect the blynk to esp8266 board
  pinMode(buzzer, OUTPUT);
  pinMode(flame_pin, INPUT);
}

void loop() {
  Blynk.run();  //Run the Blynk
  flame();
  alert_situation();
}