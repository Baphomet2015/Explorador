
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
#define IDE_HW_M1_IN2               5    // Motor derecho, velocidad
#define IDE_HW_M2_IN2               6    // Motor izquierdo, velocidad

#define IDE_HW_M1_IN1              13    // Motor derecho, direccion
#define IDE_HW_M2_IN1              12    // Motor izquierdo, direccion

#define IDE_HW_M1_M2_EN             8    // Motores, inhibicion
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

#define IDE_HW_MODO_TRX            A3    // Interruptor del modo de comunicacion WIF/BlueTooth
                                         // Interruptor ON  --> Comunicacion por BlueTooth
                                         // Interruptor OFF --> Comunicacion por WIFI

#define IDE_DELAY_ERROR            1000  // Pausa de error (ms)
#define IDE_MAX_CAR_SOLICITUD      50    // Numero maximo de caracteres que puede tener una peticion
#define IDE_MAX_CAR_BLUETOOTH      3

#define IDE_MSG_WIFI_OK               F("WIFI inicializacion OK")
#define IDE_MSG_WEB_PERROR            F("Peticion web NO valida")
#define IDE_MSG_WEB_POK               F("Peticion web OK")
#define IDE_MSG_WEB_NOEXISTE          F("Pagina no existe")
#define IDE_MSG_WEB_ID_ROBOT          F("Explorador V1.0")

#define IDE_MSG_BLUETOOTH_OK          F("BLUETOOTH inicializacion OK")
#define IDE_MSG_BLUETOOTH_CMD_ERROR   F("ER")
#define IDE_MSG_BLUETOOTH_CMD_OK      F("OK")

#define IDE_PAUSA_SALUDO           500
#define IDE_PAUSA_SENSORES_LENTOS  10000L // Pausa en milisengundos para leer los sensores de temperatura y humedad
#define IDE_PAUSA_CAR_RX           2000   // Pausa en microsegundos para lectura de caracteres en recepcion por Bluetooth

#define IDE_TRX_WIFI               0  
#define IDE_TRX_BLUETOOTH          1  

#define IDE_MOTOR_AVANCE           HIGH // Motor Sentido avance  , se aplica a los pines IN1
#define IDE_MOTOR_RETROCESO        LOW  // Motor SentidoRETROCESO, se aplica a los pines IN1

#define IDE_MOTOR_AVANCE_RAPIDO    10   // Motor avance rapido, se aplica a los pines IN2      
#define IDE_MOTOR_AVANCE_MEDIO     127  // Motor avance medio , se aplica a los pines IN2    
#define IDE_MOTOR_AVANCE_LENTO     180  // Motor avance lento, se aplica a los pines IN2    

#define IDE_MOTOR_RETROCESO_RAPIDO 240  // Motor retroceso rapido, se aplica a los pines IN2 
#define IDE_MOTOR_RETROCESO_MEDIO  127  // Motor retorceso medio, se aplica a los pines IN2 
#define IDE_MOTOR_RETROCESO_LENTO  80   // Motor retroceso lento, se aplica a los pines IN2 







