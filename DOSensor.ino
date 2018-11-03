bool flag = false;

void serialEvent1() {
  sensorstring1 = Serial1.readStringUntil(13);
  sensor_string_complete1 = true;
}
void serialEvent2() {
  sensorstring2 = Serial2.readStringUntil(13);
  sensor_string_complete2 = true;
}
void serialEvent3() {
  sensorstring3 = Serial3.readStringUntil(13);
  sensor_string_complete3 = true;
}

void showDataSensor(){
  flag = sensor_string_complete1;
  flag &= sensor_string_complete2;
  flag &= sensor_string_complete3;
  if (flag){
    lcd.clear();
    lcd.setCursor(0,1);
    lcd.print("DO1:");
    lcd.print(sensorstring1);
    lcd.setCursor(0,2);
    lcd.print("DO2:");
    lcd.print(sensorstring2);
    lcd.setCursor(0,3);
    lcd.print("DO3:");
    lcd.print(sensorstring3);
    flag = false;
    sensorstring1 = "";
    sensorstring2 = "";
    sensorstring3 = "";
    sensor_string_complete1 = false;
    sensor_string_complete2 = false;
    sensor_string_complete3 = false;
  }
}

void clearCalibration(){
  Serial1.print()
}

void singleCalibration(){
  
}

void dualCalibration(){
  
}

