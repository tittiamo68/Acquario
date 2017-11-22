void SetLamp1On(){
    LampOn1= EEPROM.read(0);
  while(digitalRead(P1)==HIGH){

   if(digitalRead(P2)==LOW)
  {
    if(LampOn1==23)
    {
      LampOn1=0;
    }
    else
    {
      LampOn1=LampOn1+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOn1==0)
    {
      LampOn1=23;
    }
    else
    {
      LampOn1=LampOn1-1;
    }
  }
  lcd.setCursor(0,0);
  lcd.print("Lamp1 On:");
  //lcd.setCursor(0,1);
  lcd.print(LampOn1,DEC);
  delay(200);
 }
}
void SetLamp1Off(){
    LampOff1= EEPROM.read(1);
  while(digitalRead(P1)==HIGH){

  if(digitalRead(P2)==LOW)
  {
    if(LampOff1==23)
    {
      LampOff1=0;
    }
    else
    {
      LampOff1=LampOff1+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOff1==0)
    {
      LampOff1=23;
    }
    else
    {
      LampOff1=LampOff1-1;
    }
  }
  lcd.setCursor(12,0);
  lcd.print("Off:");

  lcd.print(LampOff1,DEC);
  delay(200);
 }
}
void SetLamp2On(){
    LampOn2= EEPROM.read(2);
  while(digitalRead(P1)==HIGH){

   if(digitalRead(P2)==LOW)
  {
    if(LampOn2==23)
    {
      LampOn2=0;
    }
    else
    {
      LampOn2=LampOn2+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOn2==0)
    {
      LampOn2=23;
    }
    else
    {
      LampOn2=LampOn2-1;
    }
  }
  lcd.setCursor(0,1);
  lcd.print("Lamp2 On:");

  lcd.print(LampOn2,DEC);
  delay(200);
 }
}
void SetLamp2Off(){
    LampOff2= EEPROM.read(3);
  while(digitalRead(P1)==HIGH){

  if(digitalRead(P2)==LOW)
  {
    if(LampOff2==23)
    {
      LampOff2=0;
    }
    else
    {
      LampOff2=LampOff2+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOff2==0)
    {
      LampOff2=23;
    }
    else
    {
      LampOff2=LampOff2-1;
    }
  }
  lcd.setCursor(12,1);
  lcd.print("Off:");

  lcd.print(LampOff2,DEC);
  delay(200);
 }
}
void SetLamp3On(){
    LampOn3= EEPROM.read(4);
  while(digitalRead(P1)==HIGH){

   if(digitalRead(P2)==LOW)
  {
    if(LampOn3==23)
    {
      LampOn3=0;
    }
    else
    {
      LampOn3=LampOn3+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOn3==0)
    {
      LampOn3=23;
    }
    else
    {
      LampOn3=LampOn3-1;
    }
  }
  lcd.setCursor(0,2);
  lcd.print("Lamp3 On:");

  lcd.print(LampOn3,DEC);
  delay(200);
 }
}
void SetLamp3Off(){
    LampOff1= EEPROM.read(5);
  while(digitalRead(P1)==HIGH){

  if(digitalRead(P2)==LOW)
  {
    if(LampOff3==23)
    {
      LampOff1=0;
    }
    else
    {
      LampOff3=LampOff3+1;
    }
  }
   if(digitalRead(P3)==LOW)
  {
    if(LampOff3==0)
    {
      LampOff3=23;
    }
    else
    {
      LampOff3=LampOff3-1;
    }
  }
  lcd.setCursor(12,2);
  lcd.print("Off:");

  lcd.print(LampOff3,DEC);
  delay(200);
 }
}
