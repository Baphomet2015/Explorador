

// ----------------------------------------------------------------
//
// void webFormulario(void)
//
// ----------------------------------------------------------------

void webFormulario(WifiData client)
{
  
  client.println(F("HTTP/1.1 200 OK"));
//client.println(F("Content-type: multipart/form-data"));
  client.println(F("Content-Type: text/html"));
//client.println(F("Content-Type: text/javascript"));
//client.println(F("Content-Length: 30000"));
  client.println(F("Connection: close"));
//client.println("Connection: keep-alive");
  client.println();
  Serial.println(IDE_MSG_WEB_POK);
  
  client.println(F("<!DOCTYPE html>"));
  client.println(F("<html>"));
  client.println(F("<head>"));
  client.println(F("<title>Explorador V 1.0</title>"));
  
  
  client.println(F("</head>"));

  client.println(F("<body>"));


  client.println(F("<form action=\"arduino/webserver/\" id=\"FRM0\" method=\"get\">"));
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"AV\"    type=\"button\" onclick=\"fn('AV')\"></div>"));
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"RE\"    type=\"button\" onclick=\"fn('RE')\"></div>")); 
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"PA\"    type=\"button\" onclick=\"fn('PA')\"></div>")); 
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DE\"    type=\"button\" onclick=\"fn('DE')\"></div>")); 
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"IZ\"    type=\"button\" onclick=\"fn('IZ')\"></div>")); 
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"LED\"   type=\"button\" onclick=\"fn('LD')\"></div>")); 
  client.println(F("<div><input style=\"color:#00A000; width:100px; height:25px;\" value=\"DATOS\" type=\"button\" onclick=\"fn('DT')\"></div>")); 
  client.println(F("</form>")); 
 











 
  client.println(F("</body>")); 
  client.println(F("</html>")); 
  Serial.println(IDE_MSG_WEB_POK);


  client.println(DELIMITER); // very important to end the communication !!!
  Serial.println(IDE_MSG_CMD_LEDS );
}






