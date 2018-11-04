#include <LiquidCrystal.h>
#include <DS3231.h>
#include <SD.h>
#include <SPI.h>

#define up 3
#define down 2
#define enter 4

File dataFile;
const int8_t pinCS = 53;
LiquidCrystal lcd(9, 8, 10, 11, 12, 13);
DS3231  rtc(20, 21);
volatile byte state = LOW;
int8_t menu, submenu, flag0, flag1, lastSubmenu, lastMenu, intervalMenu, lastIntervalMenu, calMenu, lastCalMenu;
long deltaTime=0;
String timeStamp = "";
String sensorstring1 = "";
String sensorstring2 = "";
String sensorstring3 = "";
boolean sensor_string_complete1 = false;
boolean sensor_string_complete2 = false;
boolean sensor_string_complete3 = false;

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial2.begin(9600);
  Serial3.begin(9600);
  sensorstring1.reserve(30);
  sensorstring2.reserve(30);
  sensorstring3.reserve(30);
  rtc.begin();
  lcd.begin(20, 4);
  pinMode(up, INPUT_PULLUP);
  pinMode(down, INPUT_PULLUP);
  pinMode(enter, INPUT_PULLUP);
  pinMode(pinCS, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(2), int2Handler, RISING);
  attachInterrupt(digitalPinToInterrupt(3), int3Handler, RISING);
  while(!sdCard_init()){
  }
}

void loop() {
  if(submenu==0){
    showDatetime(0,0);
    switch(menu){
      case 0:
        lcd.setCursor(0,1);
        lcd.print("-->SET INTERVAL<--");
        lcd.setCursor(0,2);
        lcd.print("   KALIBRASI   ");
        lcd.setCursor(0,3);
        lcd.print("   START DATALOG  ");
        break;
      case 1:
        lcd.setCursor(0,1);
        lcd.print("   SET INTERVAL   ");
        lcd.setCursor(0,2);
        lcd.print("-->KALIBRASI<--");
        lcd.setCursor(0,3);
        lcd.print("   START DATALOG  ");
        break;
      case 2:
        lcd.setCursor(0,1);
        lcd.print("   SET INTERVAL  ");
        lcd.setCursor(0,2);
        lcd.print("   KALIBRASI  ");
        lcd.setCursor(0,3);
        lcd.print("-->START DATALOG<--");
        break;
      default:
        lcd.print("Menu Error");
        break;
    }
    flag0=0;
    while(digitalRead(enter)){
      flag0=1;
    }
    if(flag0==1){
      menu++;
    }
    if(menu > 2){
      menu=0;
    }
  }
  if(submenu==1){
    if(lastSubmenu != submenu){
      lcd.clear();
    }
    switch(menu){
      case 0:
        if(lastIntervalMenu!=intervalMenu){
          lcd.clear();
        }
        lastIntervalMenu = intervalMenu;
        switch(intervalMenu){
          case 0:
            lcd.setCursor(0,0);
            lcd.print("Set Interval Log:");
            lcd.setCursor(0,1);
            lcd.print("HH:MM:SS");
            deltaTimeToString(deltaTime);
            showDeltaString(0,2);
            lcd.setCursor(0,3);
            lcd.print("^^");
            flag1=0;
            while(digitalRead(enter)){
              flag1=1;
            }
            if(flag1==1){
              intervalMenu++;
              if(intervalMenu>2){
                intervalMenu=0;
                submenu=0;
              }
            }
            break;
          case 1:
            lcd.setCursor(0,0);
            lcd.print("Set Interval Log:");
            lcd.setCursor(0,1);
            lcd.print("HH:MM:SS");
            lcd.setCursor(0,2);
            deltaTimeToString(deltaTime);
            showDeltaString(0,2);
            lcd.setCursor(3,3);
            lcd.print("^^");
            flag1=0;
            while(digitalRead(enter)){
              flag1=1;
            }
            if(flag1==1){
              intervalMenu++;
              if(intervalMenu>2){
                intervalMenu=0;
                submenu=0;
              }
            }
            break;
          case 2:
            lcd.setCursor(0,0);
            lcd.print("Set Interval Log:");
            lcd.setCursor(0,1);
            lcd.print("HH:MM:SS");
            lcd.setCursor(0,2);
            deltaTimeToString(deltaTime);
            showDeltaString(0,2);
            lcd.setCursor(6,3);
            lcd.print("^^");
            flag1=0;
            while(digitalRead(enter)){
              flag1=1;
            }
            if(flag1==1){
              intervalMenu++;
              if(intervalMenu>2){
                intervalMenu=0;
                submenu=0;
              }
            }
            break;
        }
        break;
      case 1:
        if(lastCalMenu!=calMenu){
          lcd.clear();
        }
        lastCalMenu = calMenu;
        switch(calMenu){
          case 0:
            lcd.setCursor(0,0);
            lcd.print(">>Clear Calbiration");
            showDataSensor();
            break;
          case 1:
            lcd.setCursor(0,0);
            lcd.print(">>Single Calibration");
            showDataSensor();
            break;
          case 2:
            lcd.setCursor(0,0);
            lcd.print(">>Dual Calbiration");
            showDataSensor();
            break;
        }
        flag1=0;
        while(digitalRead(enter)){
          flag1=1;
        }
        if(flag1){
          calMenu++;
          if(calMenu>2){
            calMenu=0;
          }
        }
        break;
      case 2:
        //timeStamp = calculateTimeStamp(deltaTime);
        lcd.setCursor(8,0);
        lcd.print(" >> ");
        lcd.setCursor(12,0);
        lcd.print("timeStam");
        /*
        if(rtc.getTimeStr() == timeStamp){
          write all data to SDCard
        }*/
        showDataSensor();
        break;
      default:
        submenu=1;
        break;
    }
  }
  lastSubmenu = submenu;
}
//TOMBOL KANAN
void int2Handler()
{
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 200)
 {
     if(submenu==0){
       submenu++;
       if(submenu>1){
         submenu=1;
       }
     }
     //SET INTERVAL
     else if(submenu==1 && menu==0){
        if(intervalMenu==0){
          deltaTime+=3600;
        }
        else if(intervalMenu==1){
          deltaTime+=60;
        }
        else if(intervalMenu==2){
          deltaTime+=1;
        }
     }
     //SET CALIBRATION
     else if(submenu==1 && menu ==1){
        if(calMenu==0){
          clearCalibration();
        }
        else if(calMenu==1){
          singleCalibration();
        }
        else if(calMenu==2){
          dualCalibration();
        }
     }
 }
 last_interrupt_time = interrupt_time;
}
//TOMBOL TENGAH
void int3Handler()
{
 static unsigned long last_interrupt_time = 0;
 unsigned long interrupt_time = millis();
 // If interrupts come faster than 200ms, assume it's a bounce and ignore
 if (interrupt_time - last_interrupt_time > 200)
 {
   if(submenu==1 && menu==0){
    if(intervalMenu==0 && deltaTime>=3600){
      deltaTime-=3600;
    }
    else if(intervalMenu==1 && deltaTime>=60){
      deltaTime-=60;
    }
    else if(intervalMenu==2 && deltaTime>0){
      deltaTime-=1;
    }
   }
   else{
    submenu--;
    if(submenu<0){
      submenu=0;
    }
   }

 }
 last_interrupt_time = interrupt_time;
}

