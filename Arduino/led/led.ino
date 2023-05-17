#include <Wire.h>
#include "Adafruit_SGP30.h"

Adafruit_SGP30 sgp;

const int pin7 = 7;
const int pin8 = 8;
bool flag = false;
String x;

unsigned long pasttime = 0;   // 10분마다의 전송을 위한 시간 기록 

void setup()
{
  Serial.begin(9600);

  // sgp 센서 초기화
  if (!sgp.begin()) {
    Serial.println("SGP30 센서를 찾을 수 없습니다. 연결 상태를 확인하세요.");
    while (1);
  }

  pinMode(pin7, OUTPUT);
  pinMode(pin8, OUTPUT);
  digitalWrite(pin7, HIGH);
  digitalWrite(pin8, HIGH);

  pasttime = millis();  
}

void loop()
{
  if (Serial.available()) {
    if (x == "1"){
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

  // 이산화탄소 센싱
  if (!sgp.IAQmeasure()) {
    Serial.println("IAQ 측정 실패");
    return;
  }

  if(millis() - pasttime >= 600000){  // 10분 마다 송신
    Serial.println(sgp.eCO2); // 전송해야할 이산화탄소량 [ppm]
    pasttime = millis();
  }
}

