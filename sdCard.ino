long count;
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

void writeHeader(){
  dataFile = SD.open("DATALOG.csv", FILE_WRITE);
  if(dataFile){
    dataFile.print("New Reading at ");
    dataFile.print(curTime);
    dataFile.print(" ");
    dataFile.println(curDate);
    dataFile.println("No,Time,Date,DO 1,DO 2,DO 3");
    dataFile.close();
  }
  count = 1;
}

void writeDataSensor(){
  dataFile = SD.open("DATALOG.csv", FILE_WRITE);
  if(dataFile){
    dataFile.print(count);dataFile.print(",");
    dataFile.print(curTime);dataFile.print(",");
    dataFile.print(curDate);dataFile.print(",");
    dataFile.print(DO1);dataFile.print(",");
    dataFile.print(DO2);dataFile.print(",");
    dataFile.println(DO3);
    dataFile.close();
  }
  count++;
}

