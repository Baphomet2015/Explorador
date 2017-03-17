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
                                     // IMPORTANTE:
                                     // puentes que trae el controlados
                                     // El resto de señales del MC33926 utilizan los

#define IDE_HW_PING                7 // PING: Sensor ultrasonidos
#define IDE_HW_SD_CSPIN           10 // SD: Chip Select
                                    
#define IDE_HW_BATERIA            A0 // Nivel de carga de la bateria
#define IDE_HW_CELULA_DER         A1 // Celula fotoelectrica derecha
#define IDE_HW_CELULA_IZQ         A2 // Celula fotoelectrica izquierda
#define IDE_HW_MDER_STATUS        A3 // Motors derecho, status                                    
#define IDE_HW_MIZQ_STATUS        A4 // Motors izquierdo, status                                    

#define IDE_DELAY_ERROR           1000  // Pausa de error (ms)
#define IDE_MAX_CAR_SOLICITUD_WEB 100   // Numero maximo de caracteres que puede tener una peticion web


const char IDE_MSG_SD_INI      [] PROGMEM = "SD Card inicializando...";
const char IDE_MSG_SD_ERROR    [] PROGMEM = "SD card inicializacion ERROR";
const char IDE_MSG_SD_OK       [] PROGMEM = "SD card inicializacion OK";
const char IDE_MSG_WIFI_INI    [] PROGMEM = "Iniciando conexión WIFI...";
const char IDE_MSG_WIFI_ERROR  [] PROGMEM = "WIFI inicializacion ERROR";
const char IDE_MSG_WIFI_OK     [] PROGMEM = "WIFI inicializacion OK";
const char IDE_MSG_GEN_ERROR   [] PROGMEM = "ERROR";
const char IDE_MSG_GEN_FICHERO [] PROGMEM = "Falta fichero ";
const char IDE_MSG_WEB_PERROR  [] PROGMEM = "Peticion web NO valida";
const char IDE_MSG_WEB_FICHERO [] PROGMEM = "Enviando ";

const char IDE_FICHERO_WEB_01 [] PROGMEM = "styles.css";
const char IDE_FICHERO_WEB_02 [] PROGMEM = "index.html";
const char IDE_FICHERO_WEB_03 [] PROGMEM = "datos.html";
const char IDE_FICHERO_WEB_04 [] PROGMEM = "error.html";
const char IDE_FICHERO_WEB_05 [] PROGMEM = "img_404.png";


