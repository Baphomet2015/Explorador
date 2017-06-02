
// ----------------------------------------------------------------
// 
// Fichero:  Explorador_Bluetooth.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Funciones que implementan el interfaz BlueTooth
//
// ----------------------------------------------------------------

#include "explorador.h"


// ---------------------------------------------------------
//
// void btNoExiste(void)
//
// ---------------------------------------------------------

void btNoExiste(void)
{
  serialDebug(IDE_MSG_BLUETOOTH_CMD_ERROR,true);
}


// ---------------------------------------------------------
//
// void btOk(void)
//
// ---------------------------------------------------------

void btOk(void)
{
  serialDebug(IDE_MSG_BLUETOOTH_CMD_OK,true);
}
