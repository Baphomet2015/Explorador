
// -----------------------------------------------------------------------------
//
// Descarga directa de la libreria UnoWiFiDevEd.h (aunque no es preciso porque
// se descarga desde el IDE en la opcion Programa->Incluir Liberia->Gestionar Libreria):
// http://www.arduinolibraries.info/libraries/arduino-uno-wi-fi-dev-ed-library
// https://github.com/arduino-libraries/UnoWiFi-Developer-Edition-Lib/tree/master/src

// Guia de uso de la libreria UnoWiFiDevEd:
// 
//
// ACCESO a esta aplicacion:
// http://<IP>/arduino/webserver/ 
// http://<hostname>.local/arduino/webserver/
// 
//
// IMPORTANTE:
//  Si se utiliza el IDE 1.7.x se debe utilizar la version de libreria ArduinoWiFi.h
//  e incluir #include <ArduinoWiFi.h>
//  Si se utiliza el IDE 1.8.x se debe utilizar la version de libreria UNOWiFiDev.Edition
//  e incluir #include <UnoWiFiDevEd.h>
//  
// NOTA: 
//  Esta versión de programa solo fnciona con Arduino
//  UNO WIFI Developer Edition  
//
// ----------------------------------------------------------------



#include <UnoWiFiDevEd.h>
#include <SPI.h>
#include <SD.h>



// ----------------------------------------------------------------
//
// Defines y variables globales
//
// ----------------------------------------------------------------

#define IDE_HW_SD_CSPIN  1 // SD: Chip Select

const char IDE_MSG_SD_INI     [] PROGMEM = "SD Card inicializando...";
const char IDE_MSG_SD_ERROR   [] PROGMEM = "SD card inicializacion ERROR";
const char IDE_MSG_SD_OK      [] PROGMEM = "SD card inicializacion OK";
const char IDE_MSG_WIFI_INI   [] PROGMEM = "Iniciando conexión WIFI...";
const char IDE_MSG_WIFI_ERROR [] PROGMEM = "WIFI inicializacion ERROR";
const char IDE_MSG_WIFI_OK    [] PROGMEM = "WIFI inicializacion OK";

const char IDE_FICHERO_WEB_01 [] PROGMEM = "index.html";
const char IDE_FICHERO_WEB_02 [] PROGMEM = "styles.css";

byte status;

// ----------------------------------------------------------------
//
//
//
// ----------------------------------------------------------------

void setup()
{
  
  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------
  status = false;           // Para iniciar por defecto
  Serial.begin(9600);       // Para depuracion

  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------

  if ( status==false)
     { // ------------------------------------------- 
       // Inicializar tarjeta SD  
       // ------------------------------------------- 
       Serial.println(IDE_MSG_SD_INI);
       if (SD.begin(IDE_HW_SD_CSPIN)==false) { Serial.println(IDE_MSG_SD_ERROR); status = true; }
       else                                  { Serial.println(IDE_MSG_SD_OK);                   }
     }

  if ( status==false)
     { // ------------------------------------------- 
       // Inicializar coenxion Wifi
       // ------------------------------------------- 
       Serial.println(IDE_MSG_WIFI_INI);
       Wifi.begin();
       Serial.println(IDE_MSG_WIFI_OK);
     }





   
 


   
}








// ----------------------------------------------------------------
//
//
//
// ----------------------------------------------------------------

void loop()
{
  char c;
  String command;

  command = "";
  while( Wifi.available() )
       {
         c = Wifi.read();
         command = command + (char)c;  
       }
  if ( command.length()>0 ) 
     { 
       Serial.println(command);
     }
     
  delay(50);
}



















void process(WifiData client)
{




  
}




