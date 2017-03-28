

// ----------------------------------------------------------------
//
// void webFormulario(void)
//
// ----------------------------------------------------------------

void webFormulario(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/html"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
 
  Wifi.println(F("<!DOCTYPE html>"));
  Wifi.println(F("<html>"));
  Wifi.println(F("<head>"));
  Wifi.println(F("<title>Explorador V 1.0</title>"));
  
  Wifi.println(F("<link   type=\"text/css\"        href=\"estilos.css\" rel=\"stylesheet\">"));
  Wifi.println(F("<script type=\"text/JavaScript\" src=\"fn.js\"></script>")); 
      
  Wifi.println(F("</head>"));

  Wifi.println(F("<body>"));
  Wifi.println(F("<div id=\"contenedor\">")); 
  Wifi.println(F("<div id=\"cabecera\">Explorador V 1.0</div>")); 
  Wifi.println(F("<div id=\"cuerpo\">"));  
  Wifi.println(F("<div id=\"lateral\">")); 
  Wifi.println(F("<form action=\"arduino/webserver/\" id=\"FRM0\" method=\"get\">"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"AV\"    type=\"button\" onclick=\"fn('AV')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"RE\"    type=\"button\" onclick=\"fn('RE')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"PA\"    type=\"button\" onclick=\"fn('PA')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DE\"    type=\"button\" onclick=\"fn('DE')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"IZ\"    type=\"button\" onclick=\"fn('IZ')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"LED\"   type=\"button\" onclick=\"fn('LD')\"></div>"));
  Wifi.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DATOS\" type=\"button\" onclick=\"fn('DT')\"></div>"));
  Wifi.println(F("</form>"));
  Wifi.println(F("</div>"));

  Wifi.println(F("</div>")); 
  Wifi.println(F("<div id=\"pie\">Potter Systems</div>")); 
  Wifi.println(F("</div>")); 
  Wifi.println(F("</body>")); 
  Wifi.println(F("</html>")); 
  Wifi.print(DELIMITER); // very important to end the communication !!!
}


// ----------------------------------------------------------------
//
// void webCss(void)
//
// ----------------------------------------------------------------

void webCss(void)
{
  Wifi.println(F("HTTP/1.1 200 OK"));
  Wifi.println(F("Content-Type: text/css"));
  Wifi.println(F("Connection: close"));
  Wifi.println();
 
 
  Wifi.println(F("BODY"));
  Wifi.println(F("{"));
  Wifi.println(F("font: 8pt Arial,Verdana,Geneva,sans-serif;"));
  Wifi.println(F("margin: 10 0 10 0px;"));
  Wifi.println(F("text-align: center;"));
  Wifi.println(F("background-color: #FFFFFF;"));
  Wifi.println(F("}")); 
 
  Wifi.println(F("#contenedor"));
  Wifi.println(F("{"));
  Wifi.println(F(" text-align: left;")); 
  Wifi.println(F(" width: 80%;")); 
  Wifi.println(F(" margin: auto;")); 
  Wifi.println(F("}")); 

  Wifi.println(F("#cabecera"));
  Wifi.println(F("{"));
  Wifi.println(F("background-color:#1872A0;"));
  Wifi.println(F("color:#E0E0E0;"));
  Wifi.println(F("text-align:center;")); 
  Wifi.println(F("font-size:12pt;"));
  Wifi.println(F("font-weight:bold;"));
  Wifi.println(F("padding: 3 3 3 10px;"));
  Wifi.println(F("}"));

  Wifi.println(F("#cuerpo"));
  Wifi.println(F("{"));
  Wifi.println(F("margin: 10 0 10 0px;"));
  Wifi.println(F("}"));

  Wifi.println(F("#lateral"));
  Wifi.println(F("{"));
  Wifi.println(F("width:20%;"));
  Wifi.println(F("height:200px;"));
  Wifi.println(F("background-color:#1882A0;"));
  Wifi.println(F("text-align: center;"));
  Wifi.println(F("float:left;"));
  Wifi.println(F("}"));

  Wifi.println(F("#principal"));
  Wifi.println(F("{"));
  Wifi.println(F("width:100%;"));
  Wifi.println(F("height:200px;")); 
  Wifi.println(F("background-color:#1882C4;"));
  Wifi.println(F("color:#FFFFFF;"));
  Wifi.println(F("text-align: left;")); 
  Wifi.println(F("font-size:10pt;")); 
  Wifi.println(F("font-weight:bold;")); 
  Wifi.println(F("}")); 

  Wifi.println(F("#pie"));
  Wifi.println(F("{"));
  Wifi.println(F("background-color:#1872A0;"));
  Wifi.println(F("color:#FFFFFF;"));
  Wifi.println(F("text-align:center;")); 
  Wifi.println(F("font-size:12pt;")); 
  Wifi.println(F("font-weight:bold;")); 
  Wifi.println(F("padding: 3 3 3 10px;")); 
  Wifi.println(F("}"));
  Wifi.println();
 
  Wifi.print(DELIMITER); // very important to end the communication !!!
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
  
  Wifi.println(F("function fn(v)"));
  Wifi.println(F("{"));
  //Wifi.println(F("document.write(v);"));
  Wifi.println(F("document.getElementById(\"FRM0\").action += v;"));
  Wifi.println(F("document.getElementById(\"FRM0\").submit();"));
  Wifi.println(F("}"));
  Wifi.println();
 
  Wifi.print(DELIMITER); // very important to end the communication !!!
}



// ---------------------------------------------------------
//
// void webFormulario(void)
//
// ---------------------------------------------------------

void webFormulario_viejo(void)
{
  webIniHtml();

  Wifi.println(F("<body>"));
  Wifi.println(F("<div style=\"color:#A00000;\";>"));
  Wifi.println(IDE_MSG_WEB_ID_ROBOT);
  Wifi.println(F("</div>"));
  
  Wifi.println(F("<form action=\"/arduino/webserver/xx\" id=\"FRM0\" method=\"get\">"));
  Wifi.println(F("<input type=\"submit\" value=\"Switch OFF\" />"));
  Wifi.println(F("</form>"));

  
  Wifi.println(F("</body>"));

  webFinHtml();
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

