
void Lamp(){
  LampOn1= EEPROM.read(0);
  LampOff1 = EEPROM.read(1);
  LampOn2 = EEPROM.read(2);
  LampOff2 = EEPROM.read(3);
  LampOn3 = EEPROM.read(4);
  LampOff3 = EEPROM.read(5);

     DateTime now = RTC.now();
     if ( now.hour() >= LampOn1 && now.hour() <= LampOff1 )
        {
         digitalWrite(Lamp1,HIGH);// Lamp 1 On
          }
    else{
         digitalWrite(Lamp1,LOW); // lamp 1 Off
        }
     if ( now.hour() >= LampOn2 && now.hour() <= LampOff2 )
        {
         digitalWrite(Lamp2,HIGH); // Lamp 2 On
         }
    else{
         digitalWrite(Lamp2,LOW); // Lamp 2 Off
        }
     if ( now.hour() >= LampOn3 && now.hour() <= LampOff3 )
        {
         digitalWrite(Lamp3,HIGH); // Lamp 3 On
         }
    else{
         digitalWrite(Lamp3,LOW); // Lamo 3 Off
        }            
} 

