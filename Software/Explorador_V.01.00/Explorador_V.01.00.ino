
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
//  Si se utiliza el IDE 1.7.x se debe utilizar la version de libreria ArduinoWiFi.h       e incluir #include <ArduinoWiFi.h>
//  Si se utiliza el IDE 1.8.x se debe utilizar la version de libreria UNOWiFiDev.Edition  e incluir #include <UnoWiFiDevEd.h>
//  
// NOTA: 
//  Esta versión de programa solo fnciona con Arduino
//  UNO WIFI Developer Edition  
//
// ----------------------------------------------------------------


#include <UnoWiFiDevEd.h>
#include <avr/pgmspace.h>
#include <I2C16.h>           
#include <EEPROM_24XX1025.h>
#include "explorador.h"




// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------

byte ctrlProg;
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
  ctrlProg = false;         // Para iniciar por defecto
  Serial.begin(9600);       // Puerto serie, salida Debug

  pinMode(IDE_HW_LEDS,OUTPUT);
  pinMode(IDE_HW_MDER_DIR,OUTPUT);
  pinMode(IDE_HW_MIZQ_DIR,OUTPUT);
  pinMode(IDE_HW_PING,OUTPUT);

  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------


  if ( ctrlProg==false)
     { // ------------------------------------------- 
       // Inicializar coenxion Wifi
       // -------------------------------------------       
       SerialString_PROGMEM(IDE_MSG_WIFI_INI,true);
       Wifi.begin();
       SerialString_PROGMEM(IDE_MSG_WIFI_OK,true);
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

   
  if (ctrlProg==false )
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
                        if ( nCar>=IDE_MAX_CAR_SOLICITUD_WEB )
                           {
                             SerialString_PROGMEM(IDE_MSG_WEB_PERROR,true);
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
       SerialString_PROGMEM(IDE_MSG_GEN_ERROR,true);
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
  
  Serial.println(buffPeticion);       


  
   generaRespuesta();
  
}









// ---------------------------------------------------------
//
// void generaRespuesta(void)
//
//
// ---------------------------------------------------------

void generaRespuesta(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));
  
  Wifi.println(F("<head><style>"));
  Wifi.println(F("div {background-color: yellow; border: 1px solid black; padding: 5px; margin: 5px; width: 50px; border-radius: 20px; text-align: center; font-weight:bold;}"));
  Wifi.println(F("</style></head>"));
  
  Wifi.println(F("<body>"));
  
  Wifi.println(F("<div>"));
  Wifi.println(F("LED ON"));
  Wifi.println(F("</div>"));

  Wifi.println(F("<form action=\"/arduino/webserver/on\" method=\"get\">"));
  Wifi.println(F("<input type=\"submit\" value=\"Switch ON\" />"));
  Wifi.println(F("</form>"));
  
  Wifi.println(F("</body>"));
  
  Wifi.println(F("</html>"));
  
  Wifi.print(DELIMITER); // very important to end the communication !!!
}



// ---------------------------------------------------------
//
// void SerialString_PROGMEM( const char* msgP,byte opc)
//
// Copia el string pedido en el buffer global buffPROGMEM
//
// ---------------------------------------------------------
 
void SerialString_PROGMEM(const char* msgP,byte opc)
{
  char c;
  byte ind;
  byte max;
  
  max = strlen_P(msgP); 
  ind = 0;
    
  for ( ;ind<max; )
      {
        c = pgm_read_byte_near(msgP);
        if ( ind<(max-1) )
           {
             Serial.print(c);
           }
        else
           {
             if ( opc==false ) { Serial.print  (c); }
             else              { Serial.println(c); }
           }
        msgP++;
        ind++;
     }
     
 Serial.flush();     
}





// ---------------------------------------------------------
//
// void cargaInfoWeb(void)
//
//
// ---------------------------------------------------------
 
void cargaInfoWeb(void)
{






}




