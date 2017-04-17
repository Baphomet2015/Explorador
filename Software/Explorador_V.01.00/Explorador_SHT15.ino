
// ----------------------------------------------------------------
//
// Fichero: Explorador_SHT15.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Funciones relacionadas con el sensor de temperatura/humedad
// 
// ----------------------------------------------------------------

#include "explorador.h"


// ----------------------------------------------------------------
//
// float getTemperature(int SHT_dataPin,int SHT_clockPin)
// Return Temperature in Celsius
//
// ----------------------------------------------------------------

float getTemperature(int SHT_dataPin,int SHT_clockPin)
{
  int val;
  
  
  SHT_sendCommand(B00000011, SHT_dataPin, SHT_clockPin);
  SHT_waitForResult(SHT_dataPin);

  val = SHT_getData(SHT_dataPin, SHT_clockPin);
  SHT_skipCrc(SHT_dataPin, SHT_clockPin);
  return ((float)val * 0.01 - 40); //convert to celsius
}



// ----------------------------------------------------------------
//
// float getHumidity(int SHT_dataPin,int SHT_clockPin)
//
// ----------------------------------------------------------------

float getHumidity(int SHT_dataPin,int SHT_clockPin)
{
  int val;
  
  //Return  Relative Humidity
  SHT_sendCommand(B00000101, SHT_dataPin, SHT_clockPin);
  SHT_waitForResult(SHT_dataPin);
  val = SHT_getData(SHT_dataPin, SHT_clockPin);
  SHT_skipCrc(SHT_dataPin, SHT_clockPin);
  
  return (-4.0 + 0.0405 * val + -0.0000028 * val * val); 
}



// ----------------------------------------------------------------
//
// void SHT_sendCommand(int command, int dataPin, int clockPin)
//
// ----------------------------------------------------------------

void SHT_sendCommand(int command, int dataPin, int clockPin)
{
  // Send a command to the SHTx sensor transmission start
  pinMode(dataPin , OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  digitalWrite(dataPin , HIGH);
  digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin , LOW);
  digitalWrite(clockPin, LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(dataPin , HIGH);
  digitalWrite(clockPin, LOW);

  // Shift out the command (the 3 MSB are address and must be 000, the last 5 bits are the command)
  shiftOut(dataPin, clockPin, MSBFIRST, command);

  // Verify we get the right ACK
  digitalWrite(clockPin, HIGH);
  pinMode(dataPin, INPUT);

  //if (digitalRead(dataPin)) Serial.println("ACK error 0");
  digitalWrite(clockPin, LOW);
  //if (!digitalRead(dataPin)) Serial.println("ACK error 1");
}



// ----------------------------------------------------------------
//
// void SHT_waitForResult(int dataPin)
//
// ----------------------------------------------------------------

void SHT_waitForResult(int dataPin)
{
  int i;
  int ack; //Acknowledgement
  
  // Wait for the SHTx answer
  pinMode(dataPin, INPUT);

  // Need to wait up to 2 seconds for the value
  for ( i=0;i<1000; ++i )
      {
        delay(2);
        ack = digitalRead(dataPin);
        if (ack == LOW) break;
      }

  //if (ack == HIGH) Serial.println("ACK error 2");
}



// ----------------------------------------------------------------
//
// int SHT_getData(int dataPin, int clockPin)
//
// ----------------------------------------------------------------

int SHT_getData(int dataPin, int clockPin)
{
  byte MSB;
  byte LSB;
  
  // Get data from the SHTx sensor
  // Get the MSB (most significant bits)
  pinMode(dataPin,  INPUT);
  pinMode(clockPin, OUTPUT);
  MSB = shiftIn(dataPin, clockPin, MSBFIRST);

  // Send the required ACK
  pinMode(dataPin, OUTPUT);
  digitalWrite(dataPin,  HIGH);
  digitalWrite(dataPin,  LOW);
  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);

  // Get the LSB (less significant bits)
  pinMode(dataPin, INPUT);
  LSB = shiftIn(dataPin, clockPin, MSBFIRST);
  
  return ((MSB << 8) | LSB); //combine bits
}



// ----------------------------------------------------------------
//
// void SHT_skipCrc(int dataPin, int clockPin)
//
// ----------------------------------------------------------------

void SHT_skipCrc(int dataPin, int clockPin)
{
  // skip CRC data from the SHTx sensor
  pinMode(dataPin , OUTPUT);
  pinMode(clockPin, OUTPUT);
  
  digitalWrite(dataPin , HIGH);
  digitalWrite(clockPin, HIGH);
  digitalWrite(clockPin, LOW);
}

