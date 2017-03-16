
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

#define IDE_HW_SD_CSPIN           1 // SD: Chip Select






#define IDE_DELAY_ERROR           1000  // Pausa de error (ms)
#define IDE_MAX_CAR_SOLICITUD_WEB 100   // Numero maximo de caracteres que puede tener una peticion web


const char IDE_MSG_SD_INI      [] PROGMEM = "SD Card inicializando...";
const char IDE_MSG_SD_ERROR    [] PROGMEM = "SD card inicializacion ERROR";
const char IDE_MSG_SD_OK       [] PROGMEM = "SD card inicializacion OK";
const char IDE_MSG_WIFI_INI    [] PROGMEM = "Iniciando conexión WIFI...";
const char IDE_MSG_WIFI_ERROR  [] PROGMEM = "WIFI inicializacion ERROR";
const char IDE_MSG_WIFI_OK     [] PROGMEM = "WIFI inicializacion OK";
const char IDE_MSG_GEN_ERROR   [] PROGMEM = "ERROR";
const char IDE_MSG_WEB_PERROR  [] PROGMEM = "Peticion web NO valida";
const char IDE_MSG_WEB_FICHERO [] PROGMEM = "Enviando ";

const char IDE_FICHERO_WEB_01 [] PROGMEM = "styles.css";
const char IDE_FICHERO_WEB_02 [] PROGMEM = "index.html";
const char IDE_FICHERO_WEB_03 [] PROGMEM = "datos.html";
const char IDE_FICHERO_WEB_04 [] PROGMEM = "error.html";


// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------
byte   status;
String buffPeticion= "";





// ----------------------------------------------------------------
//
// setup
//
// ----------------------------------------------------------------

void setup()
{
  
  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------
  status = false;           // Para iniciar por defecto
  Serial.begin(9600);       // Puerto serie, salida Debug

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
// loop
//
// ----------------------------------------------------------------

void loop()
{
  char c;
  int  nCar;
  
 
  if (status==false )
     { // ----------------------------------
       //
       // ----------------------------------
       if ( Wifi.connected() )
          {
            buffPeticion = "";
            nCar          = 0;
            while( Wifi.available() )
                 {
                   if (nCar>=0 ) 
                      { 
                        c = Wifi.read();
                        buffPeticion = buffPeticion + (char)c;  
                        nCar++;
                        if ( nCar>IDE_MAX_CAR_SOLICITUD_WEB )
                           {
                             Serial.println(IDE_MSG_WEB_PERROR);
                             nCar = -1;
                           }
                      }
            }
       if ( nCar>0 ) 
          { 
            procesaPeticion();
          }


             
          }
       
     }
  else
     { // ----------------------------------
       // Se ha producido algun error
       // ----------------------------------
       Serial.println(IDE_MSG_GEN_ERROR);
       delay(IDE_DELAY_ERROR);
     }

}



// ----------------------------------------------------------------
//
// procesaPeticion
//
// ----------------------------------------------------------------

void procesaPeticion(void)
{

  Serial.println(buffPeticion);       
            
       if ( buffPeticion.indexOf(IDE_FICHERO_WEB_01)>0 ) { enviarFichero(IDE_FICHERO_WEB_01,false); }
  else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_02)>0 ) { enviarFichero(IDE_FICHERO_WEB_02,false); }
  else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_03)>0 ) { enviarFichero(IDE_FICHERO_WEB_03,true);  }
  else                                                   { enviarFichero(IDE_FICHERO_WEB_04,false); }

  
}





// ----------------------------------------------------------------
//
// void enviarFichero(char* nFichero,byte opcDatos)
//
// ----------------------------------------------------------------

void enviarFichero(char* nFichero,byte opcDatos)
{
  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open(nFichero);
  
  if ( dataFile )
     {
       Serial.print(IDE_MSG_WEB_FICHERO);
       Serial.println(nFichero);
       while ( dataFile.available() )
             {
               Wifi.print(dataFile.read());
             }
       Wifi.print(DELIMITER); // very important to end the communication !!!
     }
 
  dataFile.close();
}


