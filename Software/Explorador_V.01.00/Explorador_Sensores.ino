
// ----------------------------------------------------------------
// 
// Fichero:  Explorador_Sensores.ino
//
//
// ----------------------------------------------------------------


#include "explorador.h"



  

void cambiarLed(void)
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






void datos(void)
{
  
  
  distancia = getDistancia_PING();
  Serial.println(distancia,DEC);
  webDatos();
  
}
