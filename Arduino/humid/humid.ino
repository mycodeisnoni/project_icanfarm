#include <LiquidCrystal.h>

 
bool flag = false;    // 현재 작동상태 기록
bool order = false;   // 작동 명령 여부
float now = 0;        // 현재 센싱값

int sensor = 0;       // 토양습도센서
int motor = 9;        // 워터펌프

int R_max = 1023;
int R_min = 0;
int R_current = 500;
int difference = R_max - R_current;


// 제어 함수
void run_motor()
{
  Serial.print(" run_motor now!! ");
  
}

// 송신함수 
void SendMessage()
{
  Serial.print(" SendMessage : ");
 
}
 
void setup()
{
  Serial.begin(9600);
  pinMode(motor,OUTPUT);      // 모터핀설정

  
}
 
void loop()
{
  sensor = analogRead(A0);    // 센싱
  now = (float)(1023 - sensor) / 1023 * 100;
  //now = round(now * 10) / 10;
  Serial.println(now);
  delay(1000);


  if (Serial.available()) { // 시리얼 버퍼에 데이터가 있는 경우 : 작동 명령
  order = true;  
  if(order){  // 작동 명령이 떨어지면
    if(!flag){    // 미작동중 상태라면
      flag = true;    // 작동 플래그 처리



    }
  }


  }


  
}
