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

String calcStampTime(String waktu, long delta){
  long waktuInSec, jam, menit, detik;
  String strjam, strmenit, strdetik;
  waktuInSec = waktu.substring(0,2).toInt()*3600+waktu.substring(3,5).toInt()*60+waktu.substring(6,8).toInt();
  waktuInSec+=delta;
  jam = waktuInSec/3600;
  menit = (waktuInSec-(jam*3600))/60;
  detik = (waktuInSec-(jam*3600)-(menit*60));
  if(jam>9){
    strjam = String(jam);
  }
  else{
    strjam = "0"+String(jam);
  }
  if(menit>9){
    strmenit = String(menit);
  }
  else{
    strmenit = "0"+String(menit);
  }
  if(detik>9){
    strdetik = String(detik);
  }
  else{
    strdetik = "0"+String(detik);
  }
  return strjam+":"+strmenit+":"+strdetik;
}

