
// -----------------------------------------------------------------------------
// 
// Nombre:  Explorador_V.01.00.ino
// Version: 1.0
// Fecha:   01/04/2017
//
//
//           UNIR EL ROBOT A LA WIFI DESDE LA QUE SE LE VA A CONTROLAR
//
// 1 - Conectarse a la WIFI interna de gestion del Arduino:  Arduino-Uno-WIFI-cc7760
// 2 - Acceder a 192.168.240.1/home.html
// 3 - Unir el Robot a la WIFI deseada
// 4 - Apuntar la IP que ha asignado la WIFI al Robot porque es la IP que luego
//     se utilizará para acceder al Robot.
//
//
//                          ACCESO AL ROBOT
//
//              http://<IP>/arduino/webserver/home.html 
//              http://<hostname>.local/arduino/webserver/
// IP: Es la direccion IP que el WIFI haya asignado al Robot y que
//     se ha apuntado antes, al unir el Arduino a la Red.
//  
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

byte  ctrlApp;
byte  ledEstado;
float distancia;
byte  bateria;
char  buffPeticion [IDE_MAX_CAR_SOLICITUD_WEB+1];





// ----------------------------------------------------------------
//
// setup
//
// ----------------------------------------------------------------

void setup()
{
    
  
  Serial.begin(9600);       // Puerto serie, salida Debug
  
  ctrlApp   = false;       
  ledEstado = 0;
  distancia = 0;
  bateria   = 0;

  pinMode(IDE_HW_LEDS,OUTPUT);
  pinMode(IDE_HW_M1_DIR,OUTPUT);
  pinMode(IDE_HW_M2_DIR,OUTPUT);
  pinMode(IDE_HW_SENSOR_PING,OUTPUT);
  pinMode(IDE_HW_M1_SF,INPUT);
  pinMode(IDE_HW_M2_SF,INPUT);
   
  
  // -------------------------------------------------------------
  //
  // -------------------------------------------------------------

  if ( ctrlApp==false)
     { // ------------------------------------------- 
       // Inicializar conexion Wifi
       // ------------------------------------------- 
     
       serialDebug(IDE_MSG_WIFI_INI,true);
       Wifi.begin();
       serialDebug(IDE_MSG_WIFI_OK,true);
      
     }
     
   
   saludo();
   setLeds(); 
   
     
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
   
  if (ctrlApp==false )
     {
       
       // ----------------------------------------------------------------
       // Llamada a la funcion getdatos para mantener acctualizadas las  
       // variables globales que controlan los sensores.
       // ----------------------------------------------------------------
       getDatos();
       
       
       buffPeticion[0] = '\0';
       nCar            = 0;
       while( Wifi.available() && ( nCar>=0 ) )
            {
              // -----------------------------------------------------
              // Lee los caracteres que se han recibido y los almacena
              // en el buffer buffPeticion, SOLO se almacenan como
              // maximo IDE_MAX_CAR_SOLICITUD_WEB caracteres
              // -----------------------------------------------------
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
// saludo
//
// ----------------------------------------------------------------

void saludo(void)
{
  byte i;
  
  for( i=0;i<5;i++ )
     {
       digitalWrite(IDE_HW_LEDS,HIGH);
       delay(IDE_PAUSA_SALUDO);
       digitalWrite(IDE_HW_LEDS,LOW);
       delay(IDE_PAUSA_SALUDO);
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
  else if (s.indexOf("menu1.html") !=-1) { webMenu1();      }
  else if (s.indexOf("menu2.html") !=-1) { webMenu2();      }
  else if (s.indexOf("fn.js")      !=-1) { webJavascript(); }
  
  else if (s.indexOf("AV0")        !=-1) {  motorAvance();    }
  else if (s.indexOf("RE0")        !=-1) {  motorRetroceso(); }
  else if (s.indexOf("PA0")        !=-1) {  motorParo();      }
  else if (s.indexOf("DE0")        !=-1) {  motorDerecha();   }
  else if (s.indexOf("IZ0")        !=-1) {  motorIzquierda(); }
  else if (s.indexOf("LD0")        !=-1) {  setLeds();        }
  else if (s.indexOf("DT0")        !=-1) {  webDatos();       }
    
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



