
// ----------------------------------------------------------------
// 
// Fichero:  Explorador_web.ino
// Version: 1.0
// Fecha:   01/04/2017
//
// Funciones que implementan el interfaz WEB
//
// ----------------------------------------------------------------

#include "explorador.h"


// ----------------------------------------------------------------
//
// void webHome(void)
//
// ----------------------------------------------------------------

void webHome(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();

  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));
  Wifi.println(F("</head>"));

  Wifi.println(F("<frameset rows=\"25,*,25\" frameborder=\"0\" border=\"0\" framespacing=\"2\">"));
  Wifi.println(F("<frame id=\"alto\" src=\"cab.html\" marginheight=\"0\" noresize/>"));
  Wifi.println(F("<frameset COLS=\"20%,60%\,20%\" frameborder=\"0\" border=\"0\" framespacing=\"2\">"));
  Wifi.println(F("<frame name=\"menu\"  src=\"menu1.html\" marginheight=\"0\" noresize/>"));
  Wifi.println(F("<frame name=\"datos\" src=\"datos.html\" marginheight=\"0\" noresize/>"));
  Wifi.println(F("<frame name=\"menu\"  src=\"menu2.html\" marginheight=\"0\" noresize/>"));
  Wifi.println(F("</frameset>"));
 
  Wifi.println(F("<frame name=\"alto\" src=\"pie.html\" marginheight=\"0\" noresize/>"));
  Wifi.println(F("</frameset>"));

  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}



// ----------------------------------------------------------------
//
// void webCab(void)
//
// ----------------------------------------------------------------

void webCab(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();

  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));

  Wifi.println(F("<title>Explorador V 1.0</title>"));

  Wifi.println(F("<style type=\"text/css\">")); 
  Wifi.println(F("#cabecera"));
  Wifi.println(F("{"));
  Wifi.println(F("background-color:#1872A0;")); 
  Wifi.println(F("color:#E0E0E0;")); 
  Wifi.println(F("text-align:center;"));
  Wifi.println(F("font-size:12pt;")); 
  Wifi.println(F("font-weight:bold;"));
  Wifi.println(F("font-family: Arial,Verdana,Geneva,sans-serif;")); 
  Wifi.println(F("padding: 3 3 3 10px;")); 
  Wifi.println(F("}"));
  Wifi.println(F("</style>"));
  Wifi.println(F("</head>"));

  Wifi.println(F("<body>"));
  Wifi.println(F("<div id=\"cabecera\">Explorador V 1.0</div>"));
  Wifi.println(F("</body>"));

  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}



// ----------------------------------------------------------------
//
// void webPie(void)
//
// ----------------------------------------------------------------

void webPie(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();


  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));

  Wifi.println(F("<title>Explorador V 1.0</title>"));

  Wifi.println(F("<style type=\"text/css\">")); 
  Wifi.println(F("#pie"));
  Wifi.println(F("{"));
  Wifi.println(F("background-color:#1872A0;")); 
  Wifi.println(F("color:#FFFFFF;")); 
  Wifi.println(F("text-align:center;")); 
  Wifi.println(F("font-size:10pt;")); 
  Wifi.println(F("font-weight:normal;"));
  Wifi.println(F("font-family: Arial,Verdana,Geneva,sans-serif;")); 
  Wifi.println(F("padding: 3 3 3 10px;"));
  Wifi.println(F("}"));
  Wifi.println(F("</style>"));
  Wifi.println(F("</head>"));

  Wifi.println(F("<body>"));
  Wifi.println(F("<div id=\"pie\">Potter Systems, 2017</div>"));
  Wifi.println(F("</body>"));

  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}



// ----------------------------------------------------------------
//
// void webDatos(void)
//
// ----------------------------------------------------------------

void webDatos(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();

  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));

  Wifi.println(F("<style type=\"text/css\">")); 
  Wifi.println(F("#datos")); 
  Wifi.println(F("{"));  
  Wifi.println(F(" width:100%;")); 
  Wifi.println(F(" height:200px;"));  
  Wifi.println(F(" background-color:#1882C4;")); 
  Wifi.println(F(" color:#FFFFFF;")); 
  Wifi.println(F(" text-align: left;"));  
  Wifi.println(F(" font-weight:bold;")); 
  Wifi.println(F(" font-size:12pt;"));  
  Wifi.println(F(" font-family: Arial,Verdana,Geneva,sans-serif;")); 
  Wifi.println(F(" margin: auto;"));   
  Wifi.println(F("}"));  
  Wifi.println(F("</style>"));
  Wifi.println(F("</head>"));


  Wifi.println(F("<body>"));

  Wifi.println(F("<div id=\"datos\">")); 
  Wifi.println(F("<table width=\"50%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\" style=\"left:25px; top:25px; position:relative;\">"));

 
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">MOVIMIENTO:</p></td>"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">0</p></td>"));
  Wifi.println(F("</tr>"));
  
  // ----------------------------------------------------------------
  // Envia la temperatura
  // ----------------------------------------------------------------
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">TEMPERATURA:</p></td>"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">"));
  Wifi.print(temperatura);
  Wifi.println(F("&#176;C</p></td>"));
  Wifi.println(F("</tr>"));
  
  // ----------------------------------------------------------------
  // Envia la humedad
  // ----------------------------------------------------------------
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">HUMEDAD:</p></td>"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">"));
  Wifi.print(humedad);
  Wifi.println(F("%</p></td>"));
  Wifi.println(F("</tr>"));
  
  // ----------------------------------------------------------------
  // Envia la distancia
  // ----------------------------------------------------------------
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">DISTANCIA:</p></td>"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">"));
  Wifi.print(distancia);
  Wifi.println(F("cm</p></td>"));
  Wifi.println(F("</tr>"));
 
  // ----------------------------------------------------------------
  // Envia el nivel de la bateria
  // ----------------------------------------------------------------
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">BATERIA:</p></td>"));
  Wifi.print(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">"));
  Wifi.print(bateria);
  Wifi.println(F("%</p></td>"));
  Wifi.println(F("</tr>"));
  
  // ----------------------------------------------------------------
  // Envia el estado de los leds
  // ----------------------------------------------------------------
  Wifi.println(F("<tr valign=\"top\">"));
  Wifi.println(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">LEDS:</p></td>"));
  Wifi.print(F("<td width=\"50%\" nowrap ><p style=\"margin: 0px 0px 0px 0px;\">"));
  if(ledEstado==1) { Wifi.print("OFF"); }
  else             { Wifi.print("0N");  }
  Wifi.println(F("</p></td>"));
  Wifi.println(F("</tr>"));



  Wifi.println(F("</table>"));
  Wifi.println(F("</div>"));

  Wifi.println(F("</body>"));
 
  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}



// ----------------------------------------------------------------
//
// void webMenu1(void)
//
// ----------------------------------------------------------------

void webMenu1(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();

  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));
  Wifi.println(F("<style type=\"text/css\">")); 
  Wifi.println(F("#menu1"));
  Wifi.println(F("{")); 
  Wifi.println(F(" width: 100%;")); 
  Wifi.println(F(" height:200px;")); 
  Wifi.println(F(" background-color:#A2811C;")); 
  Wifi.println(F(" text-align: center;"));
  Wifi.println(F(" float:left;")); 
  Wifi.println(F(" margin: auto;")); 
  Wifi.println(F("}")); 
  Wifi.println(F("</style>"));

  Wifi.println(F("<script type=\"text/JavaScript\" src=\"fn.js\"></script>"));

  Wifi.println(F("</head>"));

  Wifi.println(F("<body>"));
  Wifi.println(F("<div id=\"menu1\">"));  
  Wifi.println(F("<form action=\"arduino/webserver/\" target=\"datos\" id=\"FRM1\" method=\"get\">"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"AV\"    type=\"button\" onclick=\"fn1('AV0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"RE\"    type=\"button\" onclick=\"fn1('RE0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"PA\"    type=\"button\" onclick=\"fn1('PA0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DE\"    type=\"button\" onclick=\"fn1('DE0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"IZ\"    type=\"button\" onclick=\"fn1('IZ0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"LED\"   type=\"button\" onclick=\"fn1('LD0')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DATOS\" type=\"button\" onclick=\"fn1('DT0')\"></div>"));
  Wifi.println(F("</form>"));
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));

  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}


// ----------------------------------------------------------------
//
// void webMenu2(void)
//
// ----------------------------------------------------------------

void webMenu2(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();

  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));

  Wifi.println(F("<head>"));
  Wifi.println(F("<style type=\"text/css\">")); 
  Wifi.println(F("#menu2"));
  Wifi.println(F("{")); 
  Wifi.println(F(" width: 100%;")); 
  Wifi.println(F(" height:200px;")); 
  Wifi.println(F(" background-color:#A2811C;")); 
  Wifi.println(F(" text-align: center;"));
  Wifi.println(F(" float:left;")); 
  Wifi.println(F(" margin: auto;")); 
  Wifi.println(F("}")); 
  Wifi.println(F("</style>"));

  Wifi.println(F("<script type=\"text/JavaScript\" src=\"fn.js\"></script>"));

  Wifi.println(F("</head>"));

  Wifi.println(F("<body>"));
  Wifi.println(F("<div id=\"menu2\">"));  
  Wifi.println(F("<form action=\"arduino/webserver/\" target=\"datos\" id=\"FRM2\" method=\"get\">"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"BUSCA LUZ\"    type=\"button\" onclick=\"fn1('BL0')\"></div>"));



  Wifi.println(F("</form>"));
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));

  Wifi.println(F("</html>"));

  Wifi.print(DELIMITER); 
}



// ----------------------------------------------------------------
//
// void webJavascript(void)
//
// ----------------------------------------------------------------

void webJavascript(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/JavaScript"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
  
  Wifi.println(F("function fn1(v)"));
  Wifi.println(F("{"));
//Wifi.println(F("document.write(v);"));
  Wifi.println(F("document.getElementById(\"FRM1\").action += v;"));
  Wifi.println(F("document.getElementById(\"FRM1\").submit();"));
  Wifi.println(F("}"));
  Wifi.println();

  Wifi.println(F("function fn2(v)"));
  Wifi.println(F("{"));
//Wifi.println(F("document.write(v);"));
  Wifi.println(F("document.getElementById(\"FRM2\").action += v;"));
  Wifi.println(F("document.getElementById(\"FRM2\").submit();"));
  Wifi.println(F("}"));
  Wifi.println();
 
  Wifi.print(DELIMITER);
}



// ---------------------------------------------------------
//
// void WebError(void)
//
// ---------------------------------------------------------

void webError()
{
  serialDebug(IDE_MSG_WEB_PERROR,true);
  
  webIniHtml();
  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#FF0000;\";>"));
  Wifi.println(IDE_MSG_WEB_PERROR);
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));
  webFinHtml();
}



// ---------------------------------------------------------
//
// void WebOk(void)
//
// ---------------------------------------------------------

void webOk()
{
  serialDebug(IDE_MSG_WEB_POK,true);
  
  webIniHtml();
  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#00A000;\";>"));
  Wifi.println(IDE_MSG_WEB_POK);
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));
  webFinHtml();
 }




// ---------------------------------------------------------
//
// void webNoExiste(void)
//
// ---------------------------------------------------------

void webNoExiste()
{
  serialDebug(IDE_MSG_WEB_NOEXISTE,true);
  
  webIniHtml();
  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#00A000;\";>"));
  Wifi.println(IDE_MSG_WEB_NOEXISTE);
  Wifi.println(F("</div>"));
  Wifi.println(F("</body>"));
  webFinHtml();
 }


// ---------------------------------------------------------
//
// void webIniHtml(void)
//
// ---------------------------------------------------------

void webIniHtml(void)
{
 
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
  
  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));
  Wifi.println(F("<head>"));
  Wifi.println(F("<title>"));
  Wifi.println(IDE_MSG_WEB_ID_ROBOT);
  Wifi.println(F("</title>"));
  Wifi.println(F("</head>"));
}



// ---------------------------------------------------------
//
// void webFinHtml(void)
//
// ---------------------------------------------------------

void webFinHtml(void)
{
  Wifi.println(F("</html>"));
  Wifi.print(DELIMITER); // very important to end the communication !!!
}

