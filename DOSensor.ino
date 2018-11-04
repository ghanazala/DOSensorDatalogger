bool sensorFlag = false;
bool commandFlag = false;

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
  sensorFlag = sensor_string_complete1;
  sensorFlag &= sensor_string_complete2;
  sensorFlag &= sensor_string_complete3;
  if (sensorFlag){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(rtc.getTimeStr());
    lcd.setCursor(0,1);
    lcd.print("DO1:");
    lcd.print(sensorstring1);
    lcd.setCursor(0,2);
    lcd.print("DO2:");
    lcd.print(sensorstring2);
    lcd.setCursor(0,3);
    lcd.print("DO3:");
    lcd.print(sensorstring3);
    sensorFlag = false;
    sensorstring1 = "";
    sensorstring2 = "";
    sensorstring3 = "";
    sensor_string_complete1 = false;
    sensor_string_complete2 = false;
    sensor_string_complete3 = false;
  }
}

void clearCalibration(){
  Serial1.print("Cal,clear\r");
  Serial2.print("Cal,clear\r");
  Serial3.print("Cal,clear\r");
  delay(1000);
  commandFlag = sensor_string_complete1 && sensorstring1=="*OK";
  commandFlag &= sensor_string_complete2 && sensorstring2=="*OK";
  commandFlag &= sensor_string_complete3 && sensorstring3=="*OK";
  if(commandFlag){
    Serial.println("COMMAND OK");
    sensorFlag = false;
    sensorstring1 = "";
    sensorstring2 = "";
    sensorstring3 = "";
    sensor_string_complete1 = false;
    sensor_string_complete2 = false;
    sensor_string_complete3 = false;
  }
}

void singleCalibration(){
  Serial1.print("Cal\r");
  Serial2.print("Cal\r");
  Serial3.print("Cal\r");
  delay(1000);
  commandFlag = sensor_string_complete1 && sensorstring1=="*OK";
  commandFlag &= sensor_string_complete2 && sensorstring2=="*OK";
  commandFlag &= sensor_string_complete3 && sensorstring3=="*OK";
  if(commandFlag){
    Serial.println("COMMAND OK");
    sensorFlag = false;
    sensorstring1 = "";
    sensorstring2 = "";
    sensorstring3 = "";
    sensor_string_complete1 = false;
    sensor_string_complete2 = false;
    sensor_string_complete3 = false;
  }
}

void dualCalibration(){
  Serial1.print("Cal,0\r");
  Serial2.print("Cal,0\r");
  Serial3.print("Cal,0\r");
  delay(1000);
  commandFlag = sensor_string_complete1 && sensorstring1=="*OK";
  commandFlag &= sensor_string_complete2 && sensorstring2=="*OK";
  commandFlag &= sensor_string_complete3 && sensorstring3=="*OK";
  if(commandFlag){
    Serial.println("COMMAND OK");
    sensorFlag = false;
    sensorstring1 = "";
    sensorstring2 = "";
    sensorstring3 = "";
    sensor_string_complete1 = false;
    sensor_string_complete2 = false;
    sensor_string_complete3 = false;
  }
}

