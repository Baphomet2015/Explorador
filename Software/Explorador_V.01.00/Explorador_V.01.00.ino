
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

#include <Wire.h>
#include <ArduinoWiFi.h>
//#include <EEPROM_24XX1025.h>
//#include <I2C16.h>
#include "explorador.h"




// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------

byte status;
char buffPeticion [IDE_MAX_CAR_SOLICITUD_WEB+1];




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
       // Inicializar coenxion Wifi
       // ------------------------------------------- 
       serialDebug(IDE_MSG_WIFI_INI,true);
       Wifi.begin();
       serialDebug(IDE_MSG_WIFI_OK,true);
       
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
       //if ( Wifi.connected() )
          {
            buffPeticion[0] = '\0';
            nCar            = 0;
            while( Wifi.available() && ( nCar>=0 ) )
                 {
                   c = Wifi.read();
                   buffPeticion[nCar] = c;  
                   nCar++;
                   buffPeticion[nCar]   = '\0';  
                   if ( nCar>=IDE_MAX_CAR_SOLICITUD_WEB )
                      {
                        webError();
                        nCar = -1;
                        Wifi.flush();
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
       webError();
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
  String s = String(buffPeticion);
    
  Serial.println(s); 
  
       if (s.indexOf("home.html")  !=-1) { webHome();       }
  else if (s.indexOf("cab.html")   !=-1) { webCab();        }
  else if (s.indexOf("pie.html")   !=-1) { webPie();        }
  else if (s.indexOf("datos.html") !=-1) { webDatos();      }
  else if (s.indexOf("menu1.html") !=-1) { webMenu1();       }
  else if (s.indexOf("menu2.html") !=-1) { webMenu2();       }
  else if (s.indexOf("fn.js")      !=-1) { webJavascript(); }
  else                                   { webNoExiste();   }  
  
  
}



// ---------------------------------------------------------
//
// void serialDebug(const __FlashStringHelper* msgP,byte opc)
//
// ---------------------------------------------------------
 
void serialDebug(const __FlashStringHelper* msg,byte opc)
{
  if ( opc==false ) { Serial.print  (msg); }
  else              { Serial.println(msg); }
}



