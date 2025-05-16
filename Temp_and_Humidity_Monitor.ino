//==========================================
//MAX72xx Dot Matrix Display & DHT11 Sensor
//==========================================
#include <Wire.h>
#include <MD_MAX72xx.h>
#include <MD_Parola.h>
#include <SPI.h>
#include <DHT.h>
//------------------------------------------------------------
MD_Parola disp = MD_Parola(MD_MAX72XX::FC16_HW, 10, 4);
DHT dht(7, DHT11);
const int kipas = 8;
//------------------------------------------------------------
float temp, hum; String tempString, humString;
char message[60]="";
//==================================================================================
void setup()
{
  pinMode(2,INPUT); pinMode(3,INPUT);pinMode(kioas,OUTPUT);
  disp.begin(); dht.begin();

  disp.displayText("NT TRONIX", PA_LEFT, 40, 40, PA_SCROLL_LEFT,PA_SCROLL_LEFT);
}
//==================================================================================
void loop()
{  
  while(!disp.displayAnimate());  
  dispTemp();
  dispHum();  
  disp.displayClear();
}
//==================================================================================
void dispTemp()
{
    temp  = dht.readTemperature(true);
    if(temp >35){
        digitalWrite(kipas, HIGH);
    }else{
    digitalWrite(kipas, LOW);
}
    temp = (temp-32)*5;
    temp = temp/9;
    tempString  = "Temperature = " + String(temp) + "C";
    tempString.toCharArray(message, 30);
    disp.displayText(message, PA_LEFT, 50, 2000, PA_SCROLL_LEFT,PA_SCROLL_LEFT);
    while(!disp.displayAnimate());  
}
//==================================================================================
void dispHum()
{
    hum  = dht.readHumidity(true);
    humString  = "Humidity = " + String(hum) + "%";
    humString.toCharArray(message, 30);
    disp.displayText(message, PA_LEFT, 50, 2000, PA_SCROLL_LEFT,PA_SCROLL_LEFT);
    while(!disp.displayAnimate());
}

