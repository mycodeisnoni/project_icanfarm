#include <Wire.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

const int pin7 = 7;
const int pin8 = 8;
bool flag = true;

unsigned long pasttime =0;

void setup()
{
  Serial.begin(9600);
  if(!sgp.begin()){
    Serial.println("ERROR");
    while(1);
  }
  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);

  pasttime = millis();
}

void loop()
{
  //Serial.println(sgp.eCO2);
  if(Serial.available()){
    if(x == "1"){
      if(!flag){
        flag = true;
        digitalWrite(pin7, HIGH);
        digitalWrite(pin8, HIGH);
      }
    }
    else{
      if(flag){
        flag = false;
        digitalWrite(pin7, LOW);
        digitalWrite(pin8, LOW);
      }
    }
  }

  if(!sgp.IAQmeasure()){
    return;
  }

  if(millis() - pasttime >= 10000){
    Serial.println(sgp.eCO2);
    pasttime = millis();
  }
}