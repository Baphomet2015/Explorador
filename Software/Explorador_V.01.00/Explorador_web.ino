

// ----------------------------------------------------------------
//
// void webFormulario(void)
//
// ----------------------------------------------------------------

void webFormulario(void)
{
  
  Wifi.write(F("HTTP/1.1 200 OK"));
  Wifi.write(F("Content-Type: text/html"));
  
  Wifi.write(F("Connection: close"));
//Wifi.write(F("Connection: keep-alive"));
//Wifi.println();

  Wifi.write(F("<!DOCTYPE html>"));
  Wifi.write(F("<html>"));
  Wifi.write(F("<head>"));
  Wifi.write(F("<title>Explorador V 1.0</title>"));
  
  Wifi.write(F("<style type=\"text/css\">")); 
  Wifi.write(F("BODY"));
  Wifi.write(F("{"));
  Wifi.write(F("font: 8pt Arial,Verdana,Geneva,sans-serif;"));
  Wifi.write(F("margin: 10 0 10 0px;"));
  Wifi.write(F("text-align: center;"));
  Wifi.write(F("background-color: #FFFFFF;"));
  Wifi.write(F("}")); 
//%23%24 son #$
  Wifi.write(F("#contenedor"));
  Wifi.write(F("{"));
  Wifi.write(F(" text-align: left;")); 
  Wifi.write(F(" width: 80%;")); 
  Wifi.write(F(" margin: auto;")); 
  Wifi.write(F("}")); 

  Wifi.write(F("#cabecera"));
  Wifi.write(F("{"));
  Wifi.write(F("background-color:#1872A0;"));
  Wifi.write(F("color:#E0E0E0;"));
  Wifi.write(F("text-align:center;")); 
  Wifi.write(F("font-size:12pt;"));
  Wifi.write(F("font-weight:bold;"));
  Wifi.write(F("padding: 3 3 3 10px;"));
  Wifi.write(F("}"));

  Wifi.write(F("#cuerpo"));
  Wifi.write(F("{"));
  Wifi.write(F("margin: 10 0 10 0px;"));
  Wifi.write(F("}"));

  Wifi.write(F("#lateral"));
  Wifi.write(F("{"));
  Wifi.write(F("width:20%;"));
  Wifi.write(F("height:200px;"));
  Wifi.write(F("background-color:#1882A0;"));
  Wifi.write(F("text-align: center;"));
  Wifi.write(F("float:left;"));
  Wifi.write(F("}"));

  Wifi.write(F("#principal"));
  Wifi.write(F("{"));
  Wifi.write(F("width:100%;"));
  Wifi.write(F("height:200px;")); 
  Wifi.write(F("background-color:#1882C4;"));
  Wifi.write(F("color:#FFFFFF;"));
  Wifi.write(F("text-align: left;")); 
  Wifi.write(F("font-size:10pt;")); 
  Wifi.write(F("font-weight:bold;")); 
  Wifi.write(F("}")); 

  Wifi.write(F("#pie"));
  Wifi.write(F("{"));
  Wifi.write(F("background-color:#1872A0;"));
  Wifi.write(F("color:#FFFFFF;"));
  Wifi.write(F("text-align:center;")); 
  Wifi.write(F("font-size:12pt;")); 
  Wifi.write(F("font-weight:bold;")); 
  Wifi.write(F("padding: 3 3 3 10px;")); 
  Wifi.write(F("}"));
  Wifi.write(F("</style>"));

  Wifi.write(F("<script type=\"text/JavaScript\">"));
  Wifi.write(F("function fn(v)"));
  Wifi.write(F("{"));
  Wifi.write(F("document.write(v);"));
  Wifi.write(F("document.getElementById(\"FRM0\").action += v;"));
  Wifi.write(F("document.getElementById(\"FRM0\").submit();"));
  Wifi.write(F("}"));
  Wifi.write(F("</script>"));
  Wifi.write(F("</head>"));

  Wifi.write(F("<body>"));
  Wifi.write(F("<div id=\"contenedor\">")); 
  Wifi.write(F("<div id=\"cabecera\">Explorador V 1.0</div>")); 
  Wifi.write(F("<div id=\"cuerpo\">"));  
  Wifi.write(F("<div id=\"lateral\">")); 
  Wifi.write(F("<form action=\"arduino/webserver/\" id=\"FRM0\" method=\"get\">"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"AV\"    type=\"button\" onclick=\"fn('AV')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"RE\"    type=\"button\" onclick=\"fn('RE')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"PA\"    type=\"button\" onclick=\"fn('PA')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DE\"    type=\"button\" onclick=\"fn('DE')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"IZ\"    type=\"button\" onclick=\"fn('IZ')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"LED\"   type=\"button\" onclick=\"fn('LD')\"></div>"));
  Wifi.write(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DATOS\" type=\"button\" onclick=\"fn('DT')\"></div>"));
  Wifi.write(F("</form>"));
  Wifi.write(F("</div>"));

  Wifi.write(F("<div id=\"principal\">")); 
  Wifi.write(F("<table width=\"20%\" border=\"0\" cellpadding=\"0\" cellspacing=\"0\"  style=\"left:200px; top:50px; position:relative;\">"));

  Wifi.write(F("<tr valign=\"top\">")); 
  Wifi.write(F("<td width=\"70%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">MOVIMIENTO:</p></td>")); 
  Wifi.write(F("<td width=\"30%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">0</p></td>")); 
  Wifi.write(F("</tr>")); 
  Wifi.write(F("<tr valign=\"top\">")); 
  Wifi.write(F("<td width=\"70%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">TEMPERATURA:</p></td>")); 
  Wifi.write(F("<td width=\"30%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">0</p></td>")); 
  Wifi.write(F("</tr>")); 
  Wifi.write(F("<tr valign=\"top\">")); 
  Wifi.write(F("<td width=\"70%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">HUMEDAD:</p></td>")); 
  Wifi.write(F("<td width=\"30%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">0</p></td>")); 
  Wifi.write(F("</tr>")); 
  Wifi.write(F("<tr valign=\"top\">")); 
  Wifi.write(F("<td width=\"70%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">DISTANCIA:</p></td>")); 
  Wifi.write(F("<td width=\"30%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">0</p></td>")); 
  Wifi.write(F("</tr>")); 
  Wifi.write(F("<tr valign=\"top\">")); 
  Wifi.write(F("<td width=\"70%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">lEDS:</p></td>")); 
  Wifi.write(F("<td width=\"30%\" nowrap style=\"border-width : 0px;\"><p style=\"padding: 0px 0px 0px 0px; margin: 0px 0px 0px 0px;\">0</p></td>")); 
  Wifi.write(F("</tr>")); 
  Wifi.write(F("</table>")); 
  Wifi.write(F("</div>")); 
  Wifi.write(F("</div>")); 
  Wifi.write(F("<div id=\"pie\">Potter Systems</div>")); 
  Wifi.write(F("</div>")); 
  Wifi.write(F("</body>")); 
  Wifi.write(F("</html>")); 
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

