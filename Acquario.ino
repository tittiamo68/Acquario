/*
:Project:Acquario
:Author: Tiziano Bianchettin
:Date: 10/02/2017
:Revision: 1
:License: Public Domain
thanks to:
  http://arduinoenonsolo.blogspot.it/2012/12/orologio-con-arduino-e-il-ds1307.html
  http://www.mauroalfieri.it/
  http://www.danielealberti.it/
  http://www.maffucci.it/
  My electronics laboratory professor "Perito Carli"  
*/
//************libraries**************//
#include <Wire.h>
#include <RTClib.h>
#include <LiquidCrystal_I2C.h>
#include <EEPROM.h>
#include <OneWire.h> 
#include <DallasTemperature.h>
#include "DHT.h"
//************************************//
LiquidCrystal_I2C lcd(0x27,20,4); // Display  I2C 20 x 4
RTC_DS1307 RTC;
//************Setup a oneWire**************//
#define ONE_WIRE_BUS 2 
OneWire oneWire(ONE_WIRE_BUS); 
DallasTemperature sensors(&oneWire);
//************DHT********************//
#define DHTPIN 3
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
#define TEMPTYPE 0 //temperature °Celsius
//************Button*****************//
int P1=6; // Button SET MENU'
int P2=7; // Button +
int P3=8; // Button -
//**************Lamp***************//
int Lamp1=9;
int Lamp2=10;
int Lamp3=11;
int Riscaldatore=4;
int Alarm=13;
//************Variables**************//
int hourupg;
int minupg;
int yearupg;
int monthupg;
int dayupg;
int menu =0;
int setAll =0;
int LampOn1;
int LampOff1;
int LampOn2;
int LampOff2;
int LampOn3;
int LampOff3;

uint8_t alarmHours =0, alarmMinutes = EEPROM.read(0);  // Holds the current alarm time


void setup()
{
LampOn1= EEPROM.read(0);
LampOff1 = EEPROM.read(1);
LampOn2 = EEPROM.read(2);
LampOff2 = EEPROM.read(3);
LampOn3 = EEPROM.read(4);
LampOff3 = EEPROM.read(5);

  lcd.begin();
  lcd.backlight();
  lcd.clear();

  pinMode(P1,INPUT_PULLUP); // https://www.arduino.cc/en/Tutorial/InputPullupSerial
  pinMode(P2,INPUT_PULLUP);
  pinMode(P3,INPUT_PULLUP);

  pinMode(Lamp1,OUTPUT);
  pinMode(Lamp2,OUTPUT);
  pinMode(Lamp3,OUTPUT);    

  pinMode(Riscaldatore,OUTPUT);
  pinMode(Alarm,OUTPUT);
  Serial.begin(9600);
  Wire.begin();
  RTC.begin();
  sensors.begin();
  dht.begin();

  if (! RTC.isrunning()) {
    Serial.println("RTC is NOT running!");
    // Set the date and time at compile time
    RTC.adjust(DateTime(__DATE__, __TIME__));
  }
  // RTC.adjust(DateTime(__DATE__, __TIME__)); //removing "//" to adjust the time
    // The default display shows the date and time
  int menu=0;
}
 
void loop()
{ 

// check if you press the SET button and increase the menu index
  if(digitalRead(P1)== LOW) 
  {
   menu=menu+1;
  }
  if((digitalRead(P2)== LOW)&&(digitalRead(P3)== LOW))                                                                                                                                                                     
  {
    lcd.clear();
    SetLamp1On();
    SetLamp1Off();
    SetLamp2On();
    SetLamp2Off();
    SetLamp3On();
    SetLamp3Off();
    EEPROM.write(0, LampOn1);
    delay(200);
    EEPROM.write(1, LampOff1);
    delay(200);
    EEPROM.write(2, LampOn2);
    delay(200);
    EEPROM.write(3, LampOff2);
    delay(200);
    EEPROM.write(4, LampOn3);
    delay(200);
    EEPROM.write(5, LampOff3);
    delay(200);

    delay(1000);
    lcd.clear();
  }
// in which subroutine should we go?
  if (menu==0)
    {
     DisplayDateTime(); // void DisplayDateTime
     Lamp(); // Lamp control
     Temp18B20();
     TempDHT();
          }
  if (menu==1)
    {
    DisplaySetHour();
    }
  if (menu==2)
    {
    DisplaySetMinute();
    }
  if (menu==3)
    {
    DisplaySetYear();
    }
  if (menu==4)
    {
    DisplaySetMonth();
    }
  if (menu==5)
    {
    DisplaySetDay();
    }
  if (menu==6)
    {
    StoreAgg(); 
    delay(500);
    menu=0;
    }
    delay(100);
}



