
// ----------------------------------------------------------------
// 
// Fichero: Explorador_Motores.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Funciones de control de los motores
//
// ----------------------------------------------------------------

#include "explorador.h"




// ----------------------------------------------------------------
//
// void motorAvance(void)
//
// ----------------------------------------------------------------

void iniMotores(void)
{
  
  motorParo();
  
  
  
  
  
}



// ----------------------------------------------------------------
//
// void motorAvance(void)
//
// ----------------------------------------------------------------

void motorAvance(void)
{
    
  if ( estadoMotores == LOW )
     {
       estadoMotores = HIGH;
       digitalWrite(IDE_HW_M1_M2_EN,estadoMotores);
     }
    
  analogWrite(IDE_HW_M1_IN2,IDE_MOTOR_AVANCE_MEDIO);
  analogWrite(IDE_HW_M2_IN2,IDE_MOTOR_AVANCE_MEDIO);
  
  digitalWrite(IDE_HW_M1_IN1,IDE_MOTOR_AVANCE );  
  digitalWrite(IDE_HW_M2_IN1,IDE_MOTOR_AVANCE );
  
   
  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // ----------------------------------------------------------------   
       webDatos();
    }
 else
    {
      // ----------------------------------------------------------------
      // Comunicacion por WIFI
      // ----------------------------------------------------------------   
      btOk();         
    }

}



// ----------------------------------------------------------------
//
// void motorRetroceso(void)
//
// ----------------------------------------------------------------

void motorRetroceso(void)
{
   if ( estadoMotores == LOW )
     {
       estadoMotores = HIGH;
       digitalWrite(IDE_HW_M1_M2_EN,estadoMotores);
     }
    
  analogWrite(IDE_HW_M1_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  analogWrite(IDE_HW_M2_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  
  digitalWrite(IDE_HW_M1_IN1,IDE_MOTOR_RETROCESO );  
  digitalWrite(IDE_HW_M2_IN1,IDE_MOTOR_RETROCESO );
  
    
  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // ----------------------------------------------------------------   
       webDatos();
    }
 else
    {
      // ----------------------------------------------------------------
      // Comunicacion por WIFI
      // ----------------------------------------------------------------   
      btOk();          
    }
  
}



// ----------------------------------------------------------------
//
// void motorParo(void)
//
// ----------------------------------------------------------------

void motorParo(void)
{
   
  estadoMotores = LOW;
  digitalWrite(IDE_HW_M1_M2_EN,estadoMotores);
   
  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // ----------------------------------------------------------------   
       webDatos();
    }
 else
    {
      // ----------------------------------------------------------------
      // Comunicacion por WIFI
      // ----------------------------------------------------------------   
      btOk();         
    } 

}



// ----------------------------------------------------------------
//
// void motorDerecha(void)
//
// ----------------------------------------------------------------

void motorIzquierda(void)
{
   if ( estadoMotores == LOW )
     {
       estadoMotores = HIGH;
       digitalWrite(IDE_HW_M1_M2_EN,estadoMotores);
     }
    
  analogWrite(IDE_HW_M1_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  analogWrite(IDE_HW_M2_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  
  digitalWrite(IDE_HW_M1_IN1,IDE_MOTOR_AVANCE );  
  digitalWrite(IDE_HW_M2_IN1,IDE_MOTOR_RETROCESO );
  
    
  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // ----------------------------------------------------------------   
       webDatos();
    }
 else
    {
      // ----------------------------------------------------------------
      // Comunicacion por WIFI
      // ----------------------------------------------------------------   
      btOk();          
    }

}



// ----------------------------------------------------------------
//
// void motorIzquierda(void)
//
// ----------------------------------------------------------------

void motorDerecha(void)
{
  
  if ( estadoMotores == LOW )
     {
       estadoMotores = HIGH;
       digitalWrite(IDE_HW_M1_M2_EN,estadoMotores);
     }
    
  analogWrite(IDE_HW_M1_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  analogWrite(IDE_HW_M2_IN2,IDE_MOTOR_RETROCESO_MEDIO);
  
  digitalWrite(IDE_HW_M1_IN1,IDE_MOTOR_RETROCESO );  
  digitalWrite(IDE_HW_M2_IN1,IDE_MOTOR_AVANCE );
  
    
  if ( modoComunicacion==IDE_TRX_WIFI ) 
     { // ----------------------------------------------------------------
       // Comunicacion por WIFI
       // ----------------------------------------------------------------   
       webDatos();
    }
 else
    {
      // ----------------------------------------------------------------
      // Comunicacion por WIFI
      // ----------------------------------------------------------------   
      btOk();          
    }
   
}



