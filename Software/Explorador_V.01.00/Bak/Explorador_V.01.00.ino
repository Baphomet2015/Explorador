
// -----------------------------------------------------------------------------
// 
// Nombre:  Explorador.ino
// Version: 1.0
// Fecha:   01/02/2017
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
#include "explorador.h"




// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------

byte status;




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

  pinMode(IDE_HW_LEDS,OUTPUT);
  pinMode(IDE_HW_MDER_DIR,OUTPUT);
  pinMode(IDE_HW_MIZQ_DIR,OUTPUT);
  pinMode(IDE_HW_PING,OUTPUT);

  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------

  if ( status==false)
     { // ------------------------------------------- 
       // Inicializar tarjeta SD  
       // ------------------------------------------- 
       Serial.println(IDE_MSG_SD_INI);
       if (SD.begin(IDE_HW_SD_CSPIN)==false)
          {
            Serial.println(IDE_MSG_SD_ERROR);
            status = true;
          }
       else
          { 
            testFicheros();
            if (status==false)
                Serial.println(IDE_MSG_SD_OK);
          }
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
  char buffPeticion[IDE_MAX_CAR_SOLICITUD_WEB+1];
 
  if (status==false )
     { // ----------------------------------
       //
       // ----------------------------------
       if ( Wifi.connected() )
          {
            buffPeticion[0] = '\0';
            nCar            = 0;
            while( Wifi.available() )
                 {
                   if (nCar>=0 ) 
                      { 
                        c = Wifi.read();
                        buffPeticion[nCar++] = c;  
                        buffPeticion[nCar]   = '\0';  
                        if ( nCar>IDE_MAX_CAR_SOLICITUD_WEB )
                           {
                             Serial.println(IDE_MSG_WEB_PERROR);
                             nCar = -1;
                           }
                      }
                 }
            
            if ( nCar>0 ) 
               { 
                 procesaPeticion(buffPeticion);
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
// void testFicheros(void)
//
// ----------------------------------------------------------------

void testFicheros(void)
{

  if ( SD.exists(IDE_FICHERO_WEB_01)==false )
     { status = true;
       Serial.print(IDE_MSG_GEN_FICHERO);
       Serial.println(IDE_FICHERO_WEB_01);
     } 

  if ( SD.exists(IDE_FICHERO_WEB_02)==false )
     { status = true;
       Serial.print(IDE_MSG_GEN_FICHERO);
       Serial.println(IDE_FICHERO_WEB_02);
     }  

  if ( SD.exists(IDE_FICHERO_WEB_03)==false )
     { status = true;
       Serial.print(IDE_MSG_GEN_FICHERO);
       Serial.println(IDE_FICHERO_WEB_03);
     } 

  if ( SD.exists(IDE_FICHERO_WEB_04)==false )
     { status = true;
       Serial.print(IDE_MSG_GEN_FICHERO);
       Serial.println(IDE_FICHERO_WEB_04);
     } 

  if ( SD.exists(IDE_FICHERO_WEB_05)==false )
     { status = true;
       Serial.print(IDE_MSG_GEN_FICHERO);
       Serial.println(IDE_FICHERO_WEB_05);
     }  
}




// ----------------------------------------------------------------
//
// procesaPeticion
//
// ----------------------------------------------------------------

void procesaPeticion(char* buffPeticion)
{

  Serial.println(buffPeticion);       
            
  //     if ( buffPeticion.indexOf(IDE_FICHERO_WEB_01)>0 ) { enviarFichero(IDE_FICHERO_WEB_01,false); }
  //else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_02)>0 ) { enviarFichero(IDE_FICHERO_WEB_02,false); }
  //else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_03)>0 ) { enviarFichero(IDE_FICHERO_WEB_03,true);  }
  //else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_04)>0 ) { enviarFichero(IDE_FICHERO_WEB_04,false); }
  //else if ( buffPeticion.indexOf(IDE_FICHERO_WEB_05)>0 ) { enviarFichero(IDE_FICHERO_WEB_05,false); }
  
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


