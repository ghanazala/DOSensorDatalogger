void showClock(int col, int row){
  tanggal = rtc.getDateStr(FORMAT_SHORT);
  waktu = rtc.getTimeStr();
  if(oldDate != tanggal || oldTime != waktu ){
    lcd.clear();
    lcd.setCursor(col, row);
    lcd.print(rtc.getDateStr(FORMAT_SHORT));
    lcd.print(" -- ");
    lcd.print(rtc.getTimeStr());
  }
  oldDate = tanggal;
  oldTime = waktu;
}

