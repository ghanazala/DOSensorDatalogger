String oldDate = "", oldTime = "", tanggal, waktu;
void showDatetime(int col, int row){
  tanggal = rtc.getDateStr(FORMAT_SHORT);
  waktu = rtc.getTimeStr();
  if(oldTime != waktu || oldDate != tanggal ){
    lcd.clear();
    lcd.setCursor(col, row);
    lcd.print(rtc.getTimeStr());
    lcd.print(" -- ");
    lcd.print(rtc.getDateStr(FORMAT_SHORT));
  }
  oldTime = waktu;
  oldDate = tanggal;
}

void showClock(int col, int row){
  waktu = rtc.getTimeStr();
  if(oldTime != waktu ){
    lcd.clear();
    lcd.setCursor(col, row);
    lcd.print(rtc.getTimeStr());
  }
  oldTime = waktu;
}

