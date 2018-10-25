long deltaSecond, deltaMinute, deltaHour;
void deltaTimeToString(long deltaTime){
  Serial.print("DELTATIME: ");Serial.println(deltaTime);
  deltaHour = deltaTime/3600;
  deltaMinute = (deltaTime-(deltaHour*3600))/60;
  deltaSecond = (deltaTime-(deltaHour*3600)-(deltaMinute*60));
}

void showDeltaString(int col, int row){
  lcd.setCursor(col, row);
  if(deltaHour<10){
    lcd.print("0");
    lcd.print(deltaHour);
  }
  else{
    lcd.print(deltaHour);
  }
  lcd.print(":");
  if(deltaMinute<10){
    lcd.print("0");
    lcd.print(deltaMinute);
  }
  else{
    lcd.print(deltaMinute);
  }
  lcd.print(":");
  if(deltaSecond<10){
    lcd.print("0");
    lcd.print(deltaSecond);
  }
  else{
    lcd.print(deltaSecond);
  }
}

