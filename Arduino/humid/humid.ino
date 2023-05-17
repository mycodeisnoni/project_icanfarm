#include <SoftwareSerial.h>

bool flag = false;
float now_string = 0;

int sensor = 0;
int motor = 9;

int R_max = 1023;
int R_min = 0;
int R_current = 500;
int difference = R_max - R_current;

int past =0;
int pasttime =0;

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pasttime = millis();
  digitalWrite(motor, HIGH);
}

void loop()
{
  sensor = analogRead(A0);
  float now_sensing = (float)(1023-sensor);

  if(Serial.available()){
    String str = Serial.readString();
    Serial.println(str);
    if(!flag){
      flag = true;
      digitalWrite(motor, LOW);
      past = millis();
    }
  }

  if(millis() - past >= 20000){
    if(flag){
      digitalWrite(motor, HIGH);
      flag = false;
    }
  }

  if(millis() - pasttime >= 600000){
    String str = String(now_sensing, 1);
    Serial.println(str);
    pasttime = millis();
  }
}
