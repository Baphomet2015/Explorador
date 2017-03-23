// ----------------------------------------------------------------
//
// Nombre:  explorador.ino
// Version: 1.0
// Fecha:   01/02/2017
//
// Defines y variables globales
//
// ----------------------------------------------------------------
                                    
#define IDE_HW_STH15_SCK           2 // Sensor de temperatura/humedad SCK
#define IDE_HW_STH15_DATA          3 // Sensor de temperatura/humedad DATA

#define IDE_HW_LEDS                4 // LEDs blancos delanteros

                                     // -------------------------------------------
                                     // Conexion controlador de los motores 
#define IDE_HW_MDER_VEL            5 // Motor derecho, velocidad
#define IDE_HW_MIZQ_VEL            6 // Motor izquierdo, velocidad
#define IDE_HW_MDER_DIR            8 // Motor derecho, direccion
#define IDE_HW_MIZQ_DIR            9 // Motor izquierdo, direccion
#define IDE_HW_MOTORES_CS         10 // Motores, inhibicion
                                     // IMPORTANTE:
                                     // puentes que trae el controlados
                                     // El resto de señales del MC33926 utilizan los

#define IDE_HW_PING                7 // PING: Sensor ultrasonidos
                                    
#define IDE_HW_BATERIA            A0 // Nivel de carga de la bateria
#define IDE_HW_CELULA_DER         A1 // Celula fotoelectrica derecha
#define IDE_HW_CELULA_IZQ         A2 // Celula fotoelectrica izquierda
#define IDE_HW_MDER_STATUS        A3 // Motors derecho, status                                    
#define IDE_HW_MIZQ_STATUS        A4 // Motors izquierdo, status                                    

#define IDE_DELAY_ERROR           1000  // Pausa de error (ms)
#define IDE_MAX_CAR_SOLICITUD_WEB 50    // Numero maximo de caracteres que puede tener una peticion web

#define IDE_MSG_WIFI_INI         F("WIFI iniciando conexion...")
#define IDE_MSG_WIFI_OK          F("WIFI inicializacion OK")
#define IDE_MSG_WEB_PERROR       F("Peticion web NO valida")
#define IDE_MSG_WEB_POK          F("Peticion web OK")
#define IDE_MSG_WEB_ID_ROBOT     F("Explorador V1.0")


#define IDE_MSG_CMD_LEDS         F("LED")




