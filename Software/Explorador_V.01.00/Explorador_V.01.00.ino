
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







// ----------------------------------------------------------------
//
//
//
// ----------------------------------------------------------------

void setup()
{
  byte status;
  
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
       Serial.println("SD Card inicializando...");
       if (SD.begin(IDE_HW_SD_CSPIN)==false) { Serial.println("SD card inicializacion ERROR"); status = true; }
       else                                  { Serial.println("SD card initializacion OK");                   }
     }

  if ( status==false)
     { // ------------------------------------------- 
       // Inicializar coenxion Wifi
       // ------------------------------------------- 
       Serial.println("Iniciando conexión WIFI...");
    //   if ( Wifi.begin()!=WL_CONNECTED ) { Serial.println("Server inicializacion ERROR"); status = true; }
    //   else                              { Serial.println("Server inicializacion OK");                   }
     }





   
 


   
}








// ----------------------------------------------------------------
//
//
//
// ----------------------------------------------------------------

void loop()
{

  while( Wifi.available() )
       {
         process(Wifi);
       }
  delay(50);
}



















void process(WifiData client)
{

  char c;

c = client.read();




  
}




