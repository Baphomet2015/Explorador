
// -----------------------------------------------------------------------------
// 
// Nombre:  Explorador_V.01.00.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// ATENCION:
// Esta aplicación se DEBE compilar con el IDE 1.7.11 de Arduino
//
//
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

char  buffPeticion [IDE_MAX_CAR_SOLICITUD+1]; // Buffer donde se recibe la peticion de hacer algo

byte flagBuscaLuz;      // Variable que indica si se esta ejecutando el modo busca luz 
                        // False NO se esta ejecutando el modo bsca luz
                        // True  SI se esta ejecutando el modo bsca luz

byte modoComunicacion;  // IDE_TRX_WIFI:      Comunicacion por WIFI
                        // IDE_TRX_BLUETOOTH: Comunicación por BlueTooth
                        
byte estadoMotores;
                        

unsigned long int temporizador; // Temporizador para leer los sensores de temperatura y humedad


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
  temporizador = 0L;
  
  pinMode(IDE_HW_LEDS,OUTPUT);
  
  pinMode(IDE_HW_M1_IN1,OUTPUT);
  pinMode(IDE_HW_M1_IN2,OUTPUT);
  pinMode(IDE_HW_M2_IN1,OUTPUT);
  pinMode(IDE_HW_M2_IN2,OUTPUT);
  pinMode(IDE_HW_M1_M2_EN,OUTPUT);
  
  pinMode(IDE_HW_SENSOR_PING,OUTPUT);
  pinMode(IDE_HW_M1_SF,INPUT);
  pinMode(IDE_HW_M2_SF,INPUT);
   
  
  // -------------------------------------------------------------
  //
  // Inicializar conexion Wifi
  //
  // -------------------------------------------------------------
     
  Wifi.begin();
   
  getModoComunicacion(); // Mira como esta el interruptor de modo de comunicacion (WIFI/BlueTooth)
  getTemperatura();      // Inicia la variable de temperatura
  getHumedad();          // Inicia la variable de humedad
  
  iniMotores();
  
  
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


  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // Llamada a  la  funcion comunicacion_WIFI() para comprobar si  se
       // ha recibido algo via web.
       // ----------------------------------------------------------------
       comunicacion_WIFI();       
     }
  else
     { // ----------------------------------------------------------------
       // Comunicacion por BlueTooth
       // 
       // 
       // ----------------------------------------------------------------
       comunicacion_BlueTooth();            
     }

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
// void comunicacion_WIFI (void)
//
// Comprueba si se ha recibido algo via web ( por WIFI ) y  en  ese
// caso lo recupera en  el buffer buffPeticion, comprobando que  el
// tamaño no se pase de IDE_MAX_CAR_SOLICITUD_WEB y se lo pasa a la
// funcion void procesaPeticion (void)
//
// ----------------------------------------------------------------

void comunicacion_WIFI (void)
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
         // maximo IDE_MAX_CAR_SOLICITUD caracteres
         // -----------------------------------------------------
         c = Wifi.read();
         buffPeticion[nCar] = c;  
         nCar++;
         buffPeticion[nCar]   = '\0';  
         if ( nCar>=IDE_MAX_CAR_SOLICITUD )
            {
              webError();
              nCar = -1;
              Wifi.flush();
            }                
       }      
            
  if ( nCar>0 ) 
     { 
       procesa_WIFI();
     }
}



// ----------------------------------------------------------------
//
// void procesa_WIFI (void)
// Determina si en la peticion que se ha recibido y que esta almacenada
// en buffPeticion hay algun comando que se deba ejecutar
//
// ----------------------------------------------------------------

void procesa_WIFI(void)
{
  String s = String(buffPeticion);
    
  //Serial.println(s); 
  
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


// ----------------------------------------------------------------
//
// void comunicacion_BlueTooth(void)
//
// Comprueba si se ha recibido algo via bluetooth
//
// ----------------------------------------------------------------

void comunicacion_BlueTooth(void)
{

  char c;
  int  nCar;
    
  buffPeticion[0] = '\0';
  nCar            = 0;
  while( Serial.available()>0  )
       {
         // -----------------------------------------------------
         // Lee los caracteres que se han recibido y los almacena
         // en el buffer buffPeticion
         // -----------------------------------------------------
         c = Serial.read();
         delayMicroseconds(IDE_PAUSA_CAR_RX);           
         buffPeticion[nCar] = c;  
         nCar++;
         buffPeticion[nCar] = '\0';  
         if ( nCar==IDE_MAX_CAR_BLUETOOTH )
            {
              Serial.flush();
              break;
            }    
       }      

  if ( nCar==IDE_MAX_CAR_BLUETOOTH ) 
     { // -----------------------------------------------------
       // Se han recibido tres caracteres, lo pasa a la funcion
       // que procesa comandos desde bluetooth
       // -----------------------------------------------------
       procesa_BlueTooth();
     }
  
}




// ---------------------------------------------------------
//
// void procesa_BlueTooth(void)
// 
//
// ---------------------------------------------------------

void procesa_BlueTooth()
{

  String s = String(buffPeticion);
      
       if (s.indexOf("AV0")        !=-1) {  motorAvance();     }
  else if (s.indexOf("RE0")        !=-1) {  motorRetroceso();  }
  else if (s.indexOf("PA0")        !=-1) {  motorParo();       }
  else if (s.indexOf("DE0")        !=-1) {  motorDerecha();    }
  else if (s.indexOf("IZ0")        !=-1) {  motorIzquierda();  }
  else if (s.indexOf("LD0")        !=-1) {  setLeds();         }
  else if (s.indexOf("DT0")        !=-1) {                     }
  else if (s.indexOf("BL0")        !=-1) {  setModoBuscaLuz(); }
    
  else                                   {  btNoExiste();      }  
  
  
  
  
  
  
  
  

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
// void getModoComunicacion(void)
// Lee el estado del interruptor que indica el modo de 
// comunicacion y actualiza la variable global "modoComunicacion"
//
// modoComunicacion = IDE_TRX_WIFI      Por WIFI
// modoComunicacion = IDE_TRX_BLUETOOTH Por BlueTooth
//
// ---------------------------------------------------------

void getModoComunicacion(void)
{

  if ( analogRead(IDE_HW_MODO_TRX)>100 )
     {
       modoComunicacion = IDE_TRX_BLUETOOTH;
       serialDebug(IDE_MSG_BLUETOOTH_OK,true);
     }
  else
     {
       modoComunicacion = IDE_TRX_WIFI;       
       serialDebug(IDE_MSG_WIFI_OK,true);
     }
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








