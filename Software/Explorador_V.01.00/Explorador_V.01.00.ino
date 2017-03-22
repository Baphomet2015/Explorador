
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
#include <EEPROM_24XX1025.h>
#include <I2C16.h>
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
            while( Wifi.available() )
                 {
                   if (nCar>=0 ) 
                      { 
                        c = Wifi.read();
                        buffPeticion[nCar++] = c;  
                        buffPeticion[nCar]   = '\0';  
                        if ( nCar>=IDE_MAX_CAR_SOLICITUD_WEB )
                           {
                             webError();
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
       webError();
       delay(IDE_DELAY_ERROR);
     }

}




// ----------------------------------------------------------------
//
// procesaPeticion
//
// ----------------------------------------------------------------

void procesaPeticion(char* buffPeticion)
{
  String s = String(buffPeticion);
  char*  f;
  
  Serial.println(s);   
      
 webOk();
  
  //webFormulario();

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



// ---------------------------------------------------------
//
// void WebError(void)
//
// ---------------------------------------------------------

void webError()
{
  serialDebug(IDE_MSG_WEB_PERROR,true);
  
  webIniHtml();
  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#FF0000;\";>"));
  Wifi.println(IDE_MSG_WEB_PERROR);
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));
  webFinHtml();
}



// ---------------------------------------------------------
//
// void WebOk(void)
//
// ---------------------------------------------------------

void webOk()
{
  serialDebug(IDE_MSG_WEB_POK,true);
  
  webIniHtml();
  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#00A000;\";>"));
  Wifi.println(IDE_MSG_WEB_POK);
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));
  webFinHtml();
 }




// ---------------------------------------------------------
//
// void webFormulario(void)
//
// ---------------------------------------------------------

void webFormulario(void)
{
  webIniHtml();

  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#A00000;\";>"));
  Wifi.println(IDE_MSG_WEB_ID_ROBOT);
  Wifi.println(F("</div>"));
  
  Wifi.println(F("<form action=\"/arduino/webserver/xx\" id=\"FRM0\" method=\"get\">"));
  Wifi.println(F("<input type=\"submit\" value=\"Switch OFF\" />"));
  Wifi.println(F("</form>"));

  
  Wifi.println(F("</body>"));

  webFinHtml();
}



// ---------------------------------------------------------
//
// void webIniHtml(void)
//
// ---------------------------------------------------------

void webIniHtml(void)
{
 
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));
  Wifi.println(F("<head>"));
  Wifi.println(F("<title>"));
  Wifi.println(IDE_MSG_WEB_ID_ROBOT);
  Wifi.println(F("</title>"));
  Wifi.println(F("</head>"));
}



// ---------------------------------------------------------
//
// void webFinHtml(void)
//
// ---------------------------------------------------------

void webFinHtml(void)
{
  Wifi.println(F("</html>"));
  Wifi.print(DELIMITER); // very important to end the communication !!!
}

