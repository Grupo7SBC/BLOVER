#include "WiFi.h"
#include <ThingsBoard.h>

const char* ssid = "ssid";
const char* password = "pass";

#define THINGSBOARD_SERVER "iot.etsisi.upm.es"
#define TOKEN "j62WfFjWDk8gRsnGPVdm"

//#define THINGSBOARD_SERVER "demo.thingsboard.io"
//#define TOKEN "SBJoNixagNeIe0Mbf1lS"

#include "DHT.h"



WiFiClient espClient;
ThingsBoard tb(espClient);

#define Humedad_Tierra1 33
#define Humedad_Tierra2 35
#define Humedad_Tierra3 39
#define Humedad_Tierra4 34
#define Humedad_Tierra5 37
#define Humedad_Tierra6 38
#define fotoSensor 32
#define Agua 36

#define DHTPIN 23
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void leer_HTierra1() {
   float sensorValue = analogRead(Humedad_Tierra1);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 1:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_1", sensorValue); 
}

void leer_HTierra2() {
   float sensorValue = analogRead(Humedad_Tierra2);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 2:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_2", sensorValue); 
}

void leer_HTierra3() {
   float sensorValue = analogRead(Humedad_Tierra3);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 3:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_3", sensorValue); 
}

void leer_HTierra4() {
   float sensorValue = analogRead(Humedad_Tierra4);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 4:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_4", sensorValue); 
}

void leer_HTierra5() {
   float sensorValue = analogRead(Humedad_Tierra5);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 5:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_5", sensorValue); 
}

void leer_HTierra6() {
   float sensorValue = analogRead(Humedad_Tierra6);
   sensorValue = sensorValue/40;
   Serial.println("Humedad en tierra 6:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_tierra_6", sensorValue); 
}

void leer_HAire() {
   float sensorValue = dht.readHumidity();
   Serial.println("Humedad en aire:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Humedad_aire", sensorValue); 
}

void leer_Agua() {
   float sensorValue = analogRead(Agua);
   sensorValue = 100*sensorValue/4095;
   Serial.println("Nivel del agua:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Nivel_agua", sensorValue); 
}

void leer_Temperatura() {
   float sensorValue = dht.readTemperature();
   Serial.println("Temperatura:"); 
   Serial.println(sensorValue);      
   tb.sendTelemetryFloat("Temperatura", sensorValue); 
}

void leer_Luz() {
   float sensorValue = analogRead(fotoSensor);
   float nivel = 0;
   if (sensorValue < 30)
	nivel = 0;
   else if (sensorValue >= 30 && sensorValue < 800)
	nivel = 1;
   else
	nivel = 2;
   Serial.println("Nivel de luz:"); 
   Serial.println(nivel);      
   tb.sendTelemetryFloat("Temperatura", nivel); 
}

void setup() 
{
  Serial.begin(9600);               
  pinMode(Humedad_Tierra1, INPUT);
  pinMode(Humedad_Tierra2, INPUT);
  pinMode(Humedad_Tierra3, INPUT);
  pinMode(Humedad_Tierra4, INPUT);
  pinMode(Humedad_Tierra5, INPUT);
  pinMode(Humedad_Tierra6, INPUT);
  pinMode(Agua, INPUT);
  pinMode(DHTPIN, INPUT);

  dht.begin();
  Serial.begin(115200);  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP()); 
}

void loop() {
  // reads the input on analog pin A0 (value between 0 and 1023)
        if (!tb.connected()) {
  // Connect to the ThingsBoard
        Serial.print("Connecting to: ");
        Serial.print(THINGSBOARD_SERVER);
        Serial.print(" with token ");
        Serial.println(TOKEN);
        if (!tb.connect(THINGSBOARD_SERVER, TOKEN)) {
            Serial.println("Failed to connect");
            return;
          }
  }
      else {
              leer_HTierra1();
              delay(500);
              leer_HTierra2();
              delay(500);
              leer_HTierra3();
              delay(500);
              leer_HTierra4();
              delay(500);
              leer_HTierra5();
              delay(500);
              leer_HTierra6();
              delay(500);
              leer_HAire();
              delay(500);
              leer_Agua();
              delay(500);
              leer_Temperatura();
	      delay(500);
	      leer_Luz();
      }
      delay(1000);   
}