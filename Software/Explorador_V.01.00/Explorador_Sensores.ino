
// ----------------------------------------------------------------
// 
// Fichero: Explorador_Sensores.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Funciones relacionadas con el control de los sensores, en general
// NOTA:
// Las funciones de control del sensor de ultrasonidos y del sensor
// de temperatura/humedad estan en otros ficheros
// 
// ----------------------------------------------------------------

#include "explorador.h"


// ----------------------------------------------------------------
//
// void getDatos(void)
//
// ----------------------------------------------------------------

void getDatos(void)
{
  
  getDistancia_PING();
  
  getBateria();
  
  
  
  
  
}

  
  
  
  
// ----------------------------------------------------------------
//
// void setLeds(void)
//
// ----------------------------------------------------------------

void setLeds(void)
{
  
  if ( ledEstado==0 ) 
     {
       ledEstado = 1;
       digitalWrite(IDE_HW_LEDS,LOW);
     }  
  else 
     {
       ledEstado = 0;
       digitalWrite(IDE_HW_LEDS,HIGH);
     }      
  webDatos();
}



// ----------------------------------------------------------------
//
// void getBateria (void)
//
// ----------------------------------------------------------------

void getBateria (void)
{
  
  int val;
  
  val = analogRead(IDE_HW_BATERIA);
  
  if ( val < IDE_MIN_BATERIA )
     {
       bateria = 0;
     }
  else
     {
       bateria = map(val,IDE_MIN_BATERIA,1023,0,100);
     }

  //Serial.println(bateria,DEC);

}


























