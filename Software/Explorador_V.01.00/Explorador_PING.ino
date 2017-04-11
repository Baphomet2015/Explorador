// ----------------------------------------------------------------
// Nombre:  ping.ino
// Version: 1.0
// Fecha:   01/02/2017
//
//

// ----------------------------------------------------------------

#include "explorador.h"



float getDistancia_PING(void)
{
  unsigned long int pulso;
  float             distancia;
  
  pinMode(IDE_HW_SENSOR_PING ,OUTPUT);            // Pin de control del PING como salida
  digitalWrite(IDE_HW_SENSOR_PING, HIGH);         // Activado
  delayMicroseconds(IDE_PAUSA_PING);              // Espera
  digitalWrite(IDE_HW_SENSOR_PING, LOW);          // Desactivado
  
  pinMode(IDE_HW_SENSOR_PING ,INPUT);             // Pin de control del PING como entrada
  pulso     = pulseIn(IDE_HW_SENSOR_PING, HIGH);  // Lectura del pulso de salida del sensor
  distancia = ((float(pulso/1000.0))*34.32)/2;    // Paso de la medida a cm
  
  return( distancia );
}

