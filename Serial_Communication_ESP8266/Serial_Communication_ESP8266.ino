/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <ArduinoJson.h>
// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YdqC19Uq2tQDbOC4-9xL8hEgV6eeZ9Fv";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "SmS_jiofi";
char pass[] = "sms123458956";

int pin;
int pin_status;
BLYNK_WRITE(V1)
{
  pin = 22;
  pin_status = param.asInt();
}

BLYNK_WRITE(V2)
{
  pin = 23;
  pin_status = param.asInt();
}

BLYNK_WRITE(V3)
{
  pin = 24;
  pin_status = param.asInt();
}

BLYNK_WRITE(V4)
{
  pin = 25;
  pin_status = param.asInt();
}

BLYNK_WRITE(V5)
{
  pin = 26;
  pin_status = param.asInt();
}

BLYNK_WRITE(V6)
{
  pin = 27;
  pin_status = param.asInt();
}

BLYNK_WRITE(V7)
{
  pin = 28;
  pin_status = param.asInt();
}

BLYNK_WRITE(V8)
{
  pin = 29;
  pin_status = param.asInt();
}

BLYNK_WRITE(V9)
{
  pin = 30;
  pin_status = param.asInt();
}

BLYNK_WRITE(V10)
{
  pin = 31;
  pin_status = param.asInt();
}

BLYNK_WRITE(V11)
{
  pin = 32;
  pin_status = param.asInt();
}


BLYNK_WRITE(V12)
{
  pin = 33;
  pin_status = param.asInt();
}

BLYNK_WRITE(V13)
{
  pin = 34;
  pin_status = param.asInt();
}

BLYNK_WRITE(V14)
{
  pin = 35;
  pin_status = param.asInt();
}

BLYNK_WRITE(V15)
{
  pin = 36;
  pin_status = param.asInt();
}

BLYNK_WRITE(V16)
{
  pin = 37;
  pin_status = param.asInt();
}

BLYNK_WRITE(V17)
{
  pin = 38;
  pin_status = param.asInt();
}

BLYNK_WRITE(V18)
{
  pin = 39;
  pin_status = param.asInt();
}

BLYNK_WRITE(V19)
{
  pin = 40;
  pin_status = param.asInt();
}

BLYNK_WRITE(V20)
{
  pin = 41;
  pin_status = param.asInt();
}

BLYNK_WRITE(V21)
{
  pin = 42;
  pin_status = param.asInt();
}

BLYNK_WRITE(V22)
{
  pin = 43;
  pin_status = param.asInt();
}

BLYNK_WRITE(V23)
{
  pin = 44;
  pin_status = param.asInt();
}

BLYNK_WRITE(V24)
{
  pin = 45;
  pin_status = param.asInt();
}

BLYNK_WRITE(V25)
{
  pin = 46;
  pin_status = param.asInt();
}

BLYNK_WRITE(V26)
{
  pin = 47;
  pin_status = param.asInt();
}

BLYNK_WRITE(V27)
{
  pin = 48;
  pin_status = param.asInt();
}

BLYNK_WRITE(V28)
{
  pin = 49;
  pin_status = param.asInt();
}

BLYNK_WRITE(V29)
{
  pin = 50;
  pin_status = param.asInt();
}

BLYNK_WRITE(V30)
{
  pin = 51;
  pin_status = param.asInt();
}

BLYNK_WRITE(V31)
{
  pin = 52;
  pin_status = param.asInt();
}

BLYNK_WRITE(V32)
{
  pin = 53;
  pin_status = param.asInt();
}


String message = "";
bool messageReady = false;

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
}

void loop()
{
  while(Serial.available()) 
  {
    message = Serial.readString();
    messageReady = true;
  }
  
  // Only process message if there's one
  if(messageReady) 
  {
    // The only messages we'll parse will be formatted in JSON
    DynamicJsonDocument doc(1024); // ArduinoJson version 6+
    // Attempt to deserialize the message
    DeserializationError error = deserializeJson(doc,message);
    if(error) 
    {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.c_str());
      messageReady = false;
      return;
    }
    
    if(doc["type"] == "request") 
    {
      doc["type"] = "response";
      // Get data from virtual pin
      doc["led"] = pin;
      doc["status"] = pin_status;
      
      serializeJson(doc,Serial);  // { "type":"response","led":22,"status": 1 }  
    }
    messageReady = false;
  Blynk.run();
}
}
