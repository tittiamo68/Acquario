void Temp18B20(){
  sensors.requestTemperatures();
  lcd.setCursor(0, 3);
  lcd.print("Temp. H2o: ");
  lcd.print (sensors.getTempCByIndex(0));
  int TempH2o=sensors.getTempCByIndex(0);
  
  if(TempH2o < 25){
  digitalWrite(Riscaldatore,HIGH); // Riscaldatore On
  digitalWrite(Alarm,LOW); // Alarm Off
  }
  else if(TempH2o > 30){
  digitalWrite(Riscaldatore,LOW); // Riscaldatore Off
  digitalWrite(Alarm,HIGH); // Alarm On
  }
  else{
    // optimal temperature
    digitalWrite(Riscaldatore,LOW); // Riscaldatore Off
    digitalWrite(Alarm,LOW); // Alarm Off
  }
}
void TempDHT(){
     int16_t t = dht.readTemperature(TEMPTYPE); // read temperature
     lcd.setCursor(11,3);
     lcd.print("Air:"); 
     lcd.print(t);// Print temperature
}

