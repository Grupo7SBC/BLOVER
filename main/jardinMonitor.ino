#include "WiFi.h"
#include <ThingsBoard.h>

const char* ssid = "ssid";
const char* password = "pass";

#define THINGSBOARD_SERVER "iot.etsisi.upm.es"  //Ingresar en la web iot.etsisi.upm.es:8080 para visualizar datos
#define TOKEN "j62WfFjWDk8gRsnGPVdm"    //Token de acceso al dispositivo de thingsboard


#include "DHT.h"



WiFiClient espClient;
ThingsBoard tb(espClient);

// PINOUT de esp32 wroom32

#define Humedad_Tierra1 33
#define Humedad_Tierra2 35
#define Humedad_Tierra3 39
#define Humedad_Tierra4 34
#define Humedad_Tierra5 37
#define Humedad_Tierra6 38
#define fotoSensor 32
#define Agua 36
#define relay 17

#define DHTPIN 23
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

float lastH1 = 1000;
float lastH2 = 1000;
float lastH3 = 1000;
float lastH4 = 1000;
float lastH5 = 1000;
float lastH6 = 1000;
float lastL = 1000;
float lastHa = 1000;
float lastA = 1000;
float lastT = 1000;


//Lectura de valores
//Entradas analogica de 0 a 4096, se realiza una normalizacion a porcentaje

void leer_HTierra1() {
   float sensorValue = analogRead(Humedad_Tierra1);
   sensorValue = sensorValue/40.96;       
   Serial.println("Humedad en tierra 1:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH1)> 10){
    lastH1 = sensorValue;       
    tb.sendTelemetryFloat("Humedad_tierra_1", sensorValue);
    if(sensorValue < 40)           //Se envia señal al relay si hay poca humedad
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW);       //Se envia señal al relay cuando ya no hace falta regar mas
   }
   
}

void leer_HTierra2() {
   float sensorValue = analogRead(Humedad_Tierra2);
   sensorValue = sensorValue/40.96;
   Serial.println("Humedad en tierra 2:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH2)> 10){
    lastH2 = sensorValue;       
    tb.sendTelemetryFloat("Humedad_tierra_2", sensorValue);
    if(sensorValue < 40)           
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW); 
   } 
}

void leer_HTierra3() {
   float sensorValue = analogRead(Humedad_Tierra3);
   sensorValue = sensorValue/40.96;
   Serial.println("Humedad en tierra 3:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH3)> 10){
    lastH3 = sensorValue;       
    tb.sendTelemetryFloat("Humedad_tierra_3", sensorValue);
    if(sensorValue < 40)           
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW); 
   }
}

void leer_HTierra4() {
   float sensorValue = analogRead(Humedad_Tierra4);
   sensorValue = sensorValue/40.96;
   Serial.println("Humedad en tierra 4:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH4)> 10){
    lastH4 = sensorValue;       
    tb.sendTelemetryFloat("Humedad_tierra_4", sensorValue);
    if(sensorValue < 40)           
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW); 
   }
}

void leer_HTierra5() {
   float sensorValue = analogRead(Humedad_Tierra5);
   sensorValue = sensorValue/40.96;
   Serial.println("Humedad en tierra 5:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH5)> 10){
    lastH5 = sensorValue;      
    tb.sendTelemetryFloat("Humedad_tierra_5", sensorValue);
    if(sensorValue < 40)           
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW); 
   }
}

void leer_HTierra6() {
   float sensorValue = analogRead(Humedad_Tierra6);
   sensorValue = sensorValue/40.96;
   Serial.println("Humedad en tierra 6:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastH6)> 10){
    lastH6 = sensorValue;       
    tb.sendTelemetryFloat("Humedad_tierra_6", sensorValue); 
    if(sensorValue < 40)           
      digitalWrite(relay, HIGH);
    if(sensorValue < 80) 
      digitalWrite(relay, LOW);
   }
}

void leer_HAire() {
   float sensorValue = dht.readHumidity();
   Serial.println("Humedad en aire:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastHa)> 10){
    lastHa = sensorValue;      
    tb.sendTelemetryFloat("Humedad_aire", sensorValue);
   } 
}

void leer_Agua() {
   float sensorValue = analogRead(Agua);
   sensorValue = sensorValue/40.96;
   Serial.println("Nivel del agua:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastA)> 10){
    lastA = sensorValue;       
    tb.sendTelemetryFloat("Nivel_agua", sensorValue);
   } 
}

void leer_Temperatura() {
   float sensorValue = dht.readTemperature();
   Serial.println("Temperatura:"); 
   Serial.println(sensorValue);
   if (abs(sensorValue - lastT)> 2){
    lastT = sensorValue;       
    tb.sendTelemetryFloat("Temperatura", sensorValue); 
   }
}

//Se lee la intensidad de luz, y se establecen 3 niveles, bajo, medio y alto (0, 1 y 2)

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
   if (abs(sensorValue - lastL)> 1){
    lastL = sensorValue;      
    tb.sendTelemetryFloat("Temperatura", nivel); 
   }
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
  pinMode(relay, OUTPUT);

  dht.begin();
  Serial.begin(115200);  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { //Se conecta al punto de acceso a internet
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  Serial.println(WiFi.localIP()); 
}

void loop() {
 
        if (!tb.connected()) {
              //Conexion con Thingsboard
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
              leer_HTierra1();      //Lectura de sensores
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
