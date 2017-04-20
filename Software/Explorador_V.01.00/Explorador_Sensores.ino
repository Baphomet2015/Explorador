
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
  unsigned long int tActual;
  
  getDistancia_PING();  // Lee el sensor de ultrasonidos
  getBateria();         // Lee el nivel de la bateria


  tActual = millis();  
  if ( (tActual - temporizador) > IDE_PAUSA_SENSORES_LENTOS )
     {
       temporizador = tActual;
       getTemperatura();     // Lee el sensor de temperatura
       getHumedad();         // Lee el sensor de humedad
     }
  
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
  
  long int val;
  byte i;
  
  
  // ----------------------------------------------------------------
  // Toma 10 muestras del nivel de la bateria y calcula el valor
  // medio, esto se hace para obtener un valor mas "estable"
  // ----------------------------------------------------------------
  
  val = 0;
  for ( i=0;i<10;i++ )
      {
        val += analogRead(IDE_HW_BATERIA);
      }
  val /= 10;
 
    
  if ( val < IDE_MIN_BATERIA )
     { // ----------------------------------------------------------------
       // Si el valor leido esta por debajo de un valor minimo (el que esta
       // definido en IDE_MIN_BATERIA ) se da como 0% de bateria
       // ----------------------------------------------------------------
       bateria = 0;
     }
  else
     { // ----------------------------------------------------------------
       // Calcula el valor de la carga de la bateria en %
       // ----------------------------------------------------------------
        bateria = map(val,IDE_MIN_BATERIA,1023,0,100);
     }

  Serial.println(bateria,DEC);

}


























