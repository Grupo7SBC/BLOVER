# BLOVER

BLOVER es un proyecto basado en IoT que pretende monotorizar un jardín botánico, en concreto,
el proyecto esta orientado a un jardín vertical.

El proyecto está en un ambiente universitarío, en un jardín tipo jardín vertical en una de las 
paredes del edificio. Tiene un tipo de sistema de riesgo en cascada, el agua sobrante cae a un 
reicpiente que indica el final de riego. El proyecto planteado tratrá de monitorizar todas las
variables necesarias, y de hacer uso de las distintas alertas que proporciona thingsboard.

Para su realización se ha usado un dispositivo ESP32 y la colaboración de la plataforma IoT thingsboard. 
El sistema se ocupa de evalua el estado de la maceta, es decir, la temperatura y humedad en el ambiente, 
el nivel de luz al que están expuestas las plantas, la humedad en tierra por cada maceta distinta y el control
de nivel del agua pra la parada de riego.

Los materiales que se han utilizado han sido:
  - 1 x Placa de desarrollo ESP32 Wroom32
  - 1 x Sensor de temperatura y humedad en aire DHT22
  - 1 x Sensor de detección de agua 
  - 6 x Sensor de humedad en tierra YL-69
  - 1 x Resistencia fotosensora
  
Software utilizado y recursos:
  - Arduino IDE
  - Librerías de ESP32 y ESP8266 para Arduino

Este proyecto está llevado a cabo en la Universidad Politécnica de Madrid para la asignatura
Sistemas Basados en Computador por: 
Alejandro Ventura Gómez, Ángel Rodríguez Cruz, Daniel Jimenez Carrilo y Mehdi Carreau Allagui.
