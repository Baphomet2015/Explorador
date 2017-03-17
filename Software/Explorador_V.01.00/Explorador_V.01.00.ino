
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

//#include <UnoWiFiDevEd.h>
#include <aruinoWifi.h>
#include <SPI.h>
#include <SD.h>
#include "explorador.h"




// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------

byte ctrlProg;
char buffPeticion [IDE_MAX_CAR_SOLICITUD_WEB+1];
char buffPROGMEM  [IDE_MAX_STR_PROGMEM      +1];  



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
       // Inicializar tarjeta SD  
       // ------------------------------------------- 

       SerialString_PROGMEM(IDE_MSG_SD_INI,true);
              
       if (SD.begin(IDE_HW_SD_CSPIN)==false)
          {
            SerialString_PROGMEM(IDE_MSG_SD_ERROR,true);
            ctrlProg = true;
          }
       else
          { 
            testFicheros();
            if (ctrlProg==false)
                SerialString_PROGMEM(IDE_MSG_SD_OK,true);
          }
     }

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
// void testFicheros(void)
//
// ----------------------------------------------------------------

void testFicheros(void)
{
  getString_PROGMEM(IDE_FICHERO_WEB_01);
  if ( SD.exists(buffPROGMEM)==false )
     { ctrlProg = true;
       SerialString_PROGMEM(IDE_MSG_GEN_FICHERO,false);
       SerialString_PROGMEM(IDE_FICHERO_WEB_01,true);
     }   
  
  getString_PROGMEM(IDE_FICHERO_WEB_02);
  if ( SD.exists(buffPROGMEM)==false )
     { ctrlProg = true;
       SerialString_PROGMEM(IDE_MSG_GEN_FICHERO,false);
       SerialString_PROGMEM(IDE_FICHERO_WEB_02,true);
     }   

  getString_PROGMEM(IDE_FICHERO_WEB_03);
  if ( SD.exists(buffPROGMEM)==false )
     { ctrlProg = true;
       SerialString_PROGMEM(IDE_MSG_GEN_FICHERO,false);
       SerialString_PROGMEM(IDE_FICHERO_WEB_03,true);
     }   
  
  getString_PROGMEM(IDE_FICHERO_WEB_04);
  if ( SD.exists(buffPROGMEM)==false )
     { ctrlProg = true;
       SerialString_PROGMEM(IDE_MSG_GEN_FICHERO,false);
       SerialString_PROGMEM(IDE_FICHERO_WEB_04,true);
     }   

  getString_PROGMEM(IDE_FICHERO_WEB_05);
  if ( SD.exists(buffPROGMEM)==false )
     { ctrlProg = true;
       SerialString_PROGMEM(IDE_MSG_GEN_FICHERO,false);
       SerialString_PROGMEM(IDE_FICHERO_WEB_05,true);
     }   
}




// ----------------------------------------------------------------
//
// procesaPeticion
//
// ----------------------------------------------------------------

void procesaPeticion(char* buffPeticion)
{
  //String s = String(buffPeticion);
  //char*  f;
  
  Serial.println(buffPeticion);       


  


  
 //      if ( s.indexOf(buffPROGMEM)>0 ) { enviarFichero(buffPROGMEM,false); }
 // else if ( s.indexOf(F(IDE_FICHERO_WEB_02))>0 ) { enviarFichero(IDE_FICHERO_WEB_02,false); }
 // else if ( s.indexOf(F(IDE_FICHERO_WEB_03))>0 ) { enviarFichero(IDE_FICHERO_WEB_03,true);  }
 // else if ( s.indexOf(F(IDE_FICHERO_WEB_04))>0 ) { enviarFichero(IDE_FICHERO_WEB_04,false); }
 // else if ( s.indexOf(F(IDE_FICHERO_WEB_05))>0 ) { enviarFichero(IDE_FICHERO_WEB_05,false); }
  
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
       SerialString_PROGMEM(IDE_MSG_WEB_FICHERO,false);
       Serial.println(nFichero);
       while ( dataFile.available() )
             {
               Wifi.print(dataFile.read());
             }
       Wifi.print(DELIMITER); // very important to end the communication !!!
     }
 
  dataFile.close();
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
// void getString_PROGMEM( const char* msgP)
//
// Recupera un string almacenado en la memoria deprograma
//
// Ver "https://www.arduino.cc/en/Reference/PROGMEM"
// 
// ---------------------------------------------------------
 
void getString_PROGMEM( const char* msgP)
{
  char c;
  byte ind;
  byte max;
  
  max = strlen_P(msgP); 
    
  if ( max<IDE_MAX_STR_PROGMEM ) 
     {
       for ( ind=0;ind<max; )
           {
             c = pgm_read_byte_near(msgP);
             buffPROGMEM[ind++] = c;
             buffPROGMEM[ind  ] = '\0';
             msgP++;
           }
     }
  else
     {
       buffPROGMEM[0] = '\0';
     }
 }


