


/*--------------------------------------------------------------
http://forum.arduino.cc/index.php?topic=227548.0
--------------------------------------------------------------*/


#include <SD.h>

#include <SPI.h>

#include <WiFi.h>

byte mac[6] ; //physical mac address

char ssid[] = "2WIRE814"; // your network SSID (name)

char pass[] = "xxxxxxxxx"; // your network password

int keyIndex = 1;

WiFiServer server(80); //server port

String readString;

//////////////////////

void setup(){

Serial.begin(9600);

// disable w5100 while setting up SD

pinMode(10,OUTPUT);

digitalWrite(10,HIGH);

Serial.print("Starting SD..");

if(!SD.begin(4)) Serial.println("failed");

else Serial.println("ok");

WiFi.begin(ssid, pass);

//delay(2000);

server.begin();

Serial.println("Ready");

}

void loop(){

// Create a client connection

WiFiClient client = server.available();

if (client) {

while (client.connected()) {

if (client.available()) {

char c = client.read();

//read char by char HTTP request

if (readString.length() < 100) {

//store characters to string

readString += c;

//Serial.print(c);

}

//if HTTP request has ended

if (c == '\n') {

///////////////

Serial.println(readString); //print to serial monitor for debuging

client.println("HTTP/1.1 200 OK"); //send new page

//client.println("Content-Type: text/html");

client.println("Content-Type: image/jpeg");

//client.println("Content-Type: image/gif");

//client.println("Content-Type: application/x-javascript");

//client.println("Content-Type: text");

client.println();

//File myFile = SD.open("boom.htm");

File myFile = SD.open("pic.jpg");

//File myFile = SD.open("BLUEH_SL.GIF");

//File myFile = SD.open("SERVOSLD.HTM");

if (myFile) {

byte clientBuf[64];

int clientCount = 0;

while(myFile.available())

{

clientBuf[clientCount] = myFile.read();

clientCount++;

if(clientCount > 63)

{

// Serial.println("Packet");

client.write(clientBuf,64);

clientCount = 0;

}

}

//final <64 byte cleanup packet

if(clientCount > 0) client.write(clientBuf,clientCount);

// close the file:

myFile.close();

}

delay(1);

//stopping client

client.stop();

readString="";

}

}

}

}

}