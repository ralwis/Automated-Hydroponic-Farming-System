#define RELAY1 8                  //define relay numbers and their pins
#define RELAY2 9

#include <Wire.h>
#include <LiquidCrystal_I2C.h>    //include LCD library with I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

#include<Arduino.h>
#include <DHT.h>                  //include DHT11 library

#define DHTPIN 7                  //DHT11 data pin connect to Arduino pin 7
#define DHTTYPE DHT11             //DHT11 is used

DHT dht(DHTPIN, DHTTYPE);         //strat DHT library

String hum="Humidity:";
String temptext="Temp:";

void setup() {

  lcd.clear();                    //clear LCD
  lcd.init();                      
  lcd.init();
  lcd.backlight();                //ON LCD backlight
  lcd.setCursor(0,0);             //set cursor to 0,0
  lcd.print("AUTOMATED");
  lcd.setCursor(0,1);
  lcd.print("HYDROPONIC");
   dht.begin();

  pinMode(RELAY1,OUTPUT);
  pinMode(RELAY2,OUTPUT);
  
}

void loop() {


 float humidity = dht.readHumidity();     //read humidity
    delay(500);
    float temp = dht.readTemperature();   //read temperature
    delay(500);

   lcd.clear();
      lcd.setCursor(0,0);
      lcd.print(hum + humidity);          //display measured humidity
      lcd.setCursor(0,1);
      lcd.print(temptext+temp);           //display measured temperature
      delay (3000);

  if(temp>30){
    digitalWrite(RELAY1, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(RELAY1, LOW);
    delay(1000);
  }
delay(2000);

  if(humidity<70){
    digitalWrite(RELAY2, HIGH);
    delay(1000);
  }
  else{
    digitalWrite(RELAY2, LOW);
    delay(1000);
  }
delay(2000);
}
