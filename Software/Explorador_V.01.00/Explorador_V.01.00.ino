
// -----------------------------------------------------------------------------
// 
// Nombre:  Explorador_V.01.00.ino
// Version: 1.0
// Fecha:   01/04/2017
//
//
//           COMO UNIR EL ROBOT A LA WIFI DESDE LA QUE SE LE VA A CONTROLAR
//
// 1 - Conectarse a la WIFI interna de gestion del Arduino:  Arduino-Uno-WIFI-cc7760
// 2 - Acceder a 192.168.240.1/home.html
// 3 - Unir el Robot a la WIFI deseada desde la pagina que se muestra
// 4 - Apuntar la IP que ha asignado la WIFI al Robot porque es la IP que luego
//     se utilizará para acceder al Robot.
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
#include "explorador.h"




// ----------------------------------------------------------------
// Variables Globales
// ----------------------------------------------------------------
                   
byte  ledEstado;   // Variable actualizada con la funcion void  setLeds       (void)
float distancia;   // Variable actualizada con la funcion void  getDistancia  (void)
byte  bateria;     // Variable actualizada con la funcion void  getBateria    (void)
float temperatura; // Variable actualizada con la funcion void getTemperatura (void)
float humedad;     // Variable actualizada con la funcion void getHumedad     (void)

char  buffPeticion [IDE_MAX_CAR_SOLICITUD_WEB+1]; // Buffer donde se recibe la peticion web de hacer algo

byte flagBuscaLuz;  // Variable que indica si se esta ejecutando el modo busca luz 
                    // False NO se esta ejecutando el modo bsca luz
                    // True  SI se esta ejecutando el modo bsca luz


// ----------------------------------------------------------------
//
// void setup(void)
//
// ----------------------------------------------------------------

void setup(void)
{
    
  
  Serial.begin(9600);       // Puerto serie, se utiliza para salida Debug
  
  ledEstado   = 0;
  distancia   = 0;
  bateria     = 0;
  temperatura = 0;
  humedad     = 0;

  flagBuscaLuz = false;

  pinMode(IDE_HW_LEDS,OUTPUT);
  pinMode(IDE_HW_M1_DIR,OUTPUT);
  pinMode(IDE_HW_M2_DIR,OUTPUT);
  pinMode(IDE_HW_SENSOR_PING,OUTPUT);
  pinMode(IDE_HW_M1_SF,INPUT);
  pinMode(IDE_HW_M2_SF,INPUT);
   
  
  // -------------------------------------------------------------
  //
  // Inicializar conexion Wifi
  //
  // -------------------------------------------------------------
     
  serialDebug(IDE_MSG_WIFI_INI,true);
  Wifi.begin();
  serialDebug(IDE_MSG_WIFI_OK,true);
    
    
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
  // ----------------------------------------------------------------
  // Llamada a la  funcion getDatos() para mantener acctualizadas las  
  // variables globales que controlan los sensores.
  // ----------------------------------------------------------------
  getDatos();

  // ----------------------------------------------------------------
  // Llamada a  la  funcion leePeticion() para  comprobar  si  se  ha
  // recibido algo via web.
  // ----------------------------------------------------------------
  leePeticion();       

  // ----------------------------------------------------------------
  // Comprueba si se debe ejecutar el modo Busca Luz
  // ----------------------------------------------------------------
  if ( flagBuscaLuz==true )
     {
       modoBuscaLuz();
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
// void leePeticion (void)
//
// Comprueba si se ha recibido algo via web y en ese caso lo 
// recupera en el buffer buffPeticion, comprueba que el tamaño no 
// se pase de IDE_MAX_CAR_SOLICITUD_WEB y se lo pasa a la funcion
// void procesaPeticion (void)
//
// ----------------------------------------------------------------

void leePeticion (void)
{
  char c;
  int  nCar;
  
  
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



// ----------------------------------------------------------------
//
// void procesaPeticion (void)
// Determina si en la peticion que se ha recibido y que esta almacenada
// en buffPeticion hay algun comando que se deba ejecutar
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
  
  else if (s.indexOf("AV0")        !=-1) {  motorAvance();     }
  else if (s.indexOf("RE0")        !=-1) {  motorRetroceso();  }
  else if (s.indexOf("PA0")        !=-1) {  motorParo();       }
  else if (s.indexOf("DE0")        !=-1) {  motorDerecha();    }
  else if (s.indexOf("IZ0")        !=-1) {  motorIzquierda();  }
  else if (s.indexOf("LD0")        !=-1) {  setLeds();         }
  else if (s.indexOf("DT0")        !=-1) {  webDatos();        }
    
  else if (s.indexOf("BL0")        !=-1) {  setModoBuscaLuz(); }
    
  else                                   { webNoExiste();   }  
  
  
}



// ---------------------------------------------------------
//
// void setModoBuscaLuz(void)
// Activa o Desactiva el modo busca luz
//
// ---------------------------------------------------------

void setModoBuscaLuz(void)
{
  if  ( flagBuscaLuz==false ) 
      { // ---------------------------------------------------------
        // ACTIVA el modo busca luz
        // ---------------------------------------------------------
        flagBuscaLuz = true;
      }
  else
      { // ---------------------------------------------------------
        // DESACTIVA el modo busca luz
        // ---------------------------------------------------------
        flagBuscaLuz = false;
      }
  
  webDatos();
}



// ---------------------------------------------------------
//
// void modoModoBuscaLuz(void)
// Ejecuta el modo Busca Luz
//
// ---------------------------------------------------------

void modoBuscaLuz(void)
{





}










// ---------------------------------------------------------
//
// void serialDebug(const __FlashStringHelper* msgP,byte opc)
//
// Envia por el puerto serie el string que recibe en el 
// parametro msg
// El parametro opc indica:
// . True  Enviar el string con salto de linea al final
// . False Enviar el string sin salto de linea al final
//
// ---------------------------------------------------------
 
void serialDebug(const __FlashStringHelper* msg,byte opc)
{
  if ( opc==false ) { Serial.print  (msg); }
  else              { Serial.println(msg); }
}








