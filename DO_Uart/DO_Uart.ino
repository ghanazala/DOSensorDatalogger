String inputstring = "";
String sensorstring1 = "";
String sensorstring2 = "";
String sensorstring3 = "";
boolean input_string_complete = false;
boolean sensor_string_complete1 = false;
boolean sensor_string_complete2 = false;
boolean sensor_string_complete3 = false;
float DO;
//a string to hold incoming data from the PC
//a string to hold the data from the Atlas Scientific product
//have we received all the data from the PC
//have we received all the data from the Atlas Scientific product
//used to hold a floating point number that is the DO
void setup() {
Serial.begin(9600);
Serial1.begin(9600);
//Serial2.begin(9600);
//Serial3.begin(9600);
inputstring.reserve(10);
sensorstring1.reserve(30);
//sensorstring2.reserve(30);
//sensorstring3.reserve(30);
}
//set up the hardware
//set baud rate for the hardware serial port_0 to 9600
//set baud rate for software serial port_3 to 9600
//set aside some bytes for receiving data from the PC
//set aside some bytes for receiving data from Atlas Scientific product
void serialEvent() {
inputstring = Serial.readStringUntil(13);
input_string_complete = true;
}
void serialEvent1() {
sensorstring1 = Serial1.readStringUntil(13);
sensor_string_complete1 = true;
}
//void serialEvent2() {
//sensorstring2 = Serial2.readStringUntil(13);
//sensor_string_complete2 = true;
//}
//void serialEvent3() {
//sensorstring3 = Serial3.readStringUntil(13);
//sensor_string_complete3 = true;
//}
//if the hardware serial port_0 receives a char
//read the string until we see a <CR>
//set the flag used to tell if we have received a completed string from the PC
//if the hardware serial port_3 receives a char
//read the string until we see a <CR>
//set the flag used to tell if we have received a completed string from the PC
void loop(){
  if (input_string_complete == true) {
    Serial1.print(inputstring);
    Serial1.print('\r');
//    Serial2.print(inputstring);
//    Serial2.print('\r');
//    Serial3.print(inputstring);
//    Serial3.print('\r');
    inputstring = "";
    input_string_complete = false;
  }
//here we go...
//if a string from the PC has been received in its entirety
//send that string to the Atlas Scientific product
//send that string to the Atlas Scientific product
//clear the string
//reset the flag used to tell if we have received a completed string from the PC
  if (sensor_string_complete1 == true) {
    Serial.print("DO1: ");
    Serial.println(sensorstring1);
  }
//  if (sensor_string_complete2 == true) {
//    Serial.print("DO2: ");
//    Serial.println(sensorstring2);
//  }
//  if (sensor_string_complete3 == true) {
//    Serial.print("DO3: ");
//    Serial.println(sensorstring3);
//  }
  sensorstring1 = "";
//  sensorstring2 = "";
//  sensorstring3 = "";
  sensor_string_complete1 = false;
//  sensor_string_complete2 = false;
//  sensor_string_complete3 = false;
}
