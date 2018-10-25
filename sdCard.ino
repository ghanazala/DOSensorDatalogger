bool sdCard_init(){
  if (!SD.begin(pinCS)) {
    lcd.print("Empty");
    lcd.setCursor(0, 0);
    lcd.print("--------------------");
    lcd.setCursor(0, 1);  
    lcd.print("Please Insert sdCard");
    lcd.setCursor(0, 2);  
    lcd.print(" Then Reset Device");
    lcd.setCursor(0, 3);  
    lcd.print("--------------------");  
    return false;  
  }
  return true;
}

