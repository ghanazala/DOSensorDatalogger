String oldDate = "", oldTime = "";
void showDatetime(String waktu, String tanggal, int col, int row){
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

