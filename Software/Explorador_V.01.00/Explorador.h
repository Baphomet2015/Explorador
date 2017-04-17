
// ----------------------------------------------------------------
//
// Nombre:  Explorador.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Fichero cabecera con los defines de la aplicacion
//
// ----------------------------------------------------------------
                                    
#define IDE_HW_STH15_SCK            2    // Sensor de temperatura/humedad SCK
#define IDE_HW_STH15_DATA           3    // Sensor de temperatura/humedad DATA

#define IDE_HW_LEDS                 4    // LEDs blancos delanteros

                                         // -------------------------------------------
                                         // Conexion controlador de los motores 
#define IDE_HW_M1_VEL               5    // Motor derecho, velocidad
#define IDE_HW_M2_VEL               6    // Motor izquierdo, velocidad
#define IDE_HW_M1_DIR              13    // Motor derecho, direccion
#define IDE_HW_M2_DIR              12    // Motor izquierdo, direccion
#define IDE_HW_MOTORES_EN           8    // Motores, inhibicion
                                         // IMPORTANTE:
                                         // puentes que trae el controlados
                                         // El resto de señales del MC33926 utilizan los
       

#define IDE_HW_SENSOR_PING          7    // PING: Sensor ultrasonidos
#define IDE_PAUSA_PING              5    // Pausa utilizada en el PING para el control      
     
                                    
#define IDE_HW_BATERIA             A0    // Nivel de carga de la bateria
#define IDE_MIN_BATERIA            818   // Nivel minimo de la bateria equvale a 4V

#define IDE_HW_CELULA_DER          A1    // Celula fotoelectrica derecha
#define IDE_HW_CELULA_IZQ          A2    // Celula fotoelectrica izquierda
#define IDE_HW_M1_SF                9    // Motores derecho,   status                                    
#define IDE_HW_M2_SF               10    // Motores izquierdo, status                                    

#define IDE_DELAY_ERROR            1000  // Pausa de error (ms)
#define IDE_MAX_CAR_SOLICITUD_WEB  50    // Numero maximo de caracteres que puede tener una peticion web

#define IDE_MSG_WIFI_INI           F("WIFI iniciando conexion...")
#define IDE_MSG_WIFI_OK            F("WIFI inicializacion OK")
#define IDE_MSG_WEB_PERROR         F("Peticion web NO valida")
#define IDE_MSG_WEB_POK            F("Peticion web OK")
#define IDE_MSG_WEB_NOEXISTE       F("Pagina no existe")
#define IDE_MSG_WEB_ID_ROBOT       F("Explorador V1.0")


#define IDE_MSG_CMD_LEDS           F("LED")

#define IDE_PAUSA_SALUDO           500



