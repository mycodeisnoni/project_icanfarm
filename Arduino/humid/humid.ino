#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

bool flag = false;    // 현재 작동상태 기록
float now_sensing = 0;        // 현재 센싱값

int sensor = 0;       // 토양습도센서
int motor = 9;        // 워터펌프

int R_max = 1023;
int R_min = 0;
int R_current = 500;
int difference = R_max - R_current;

int past = 0;       //  모터 작동을 위한 시간 기록
int pasttime = 0;   // 10분마다의 전송을 위한 시간 기록 


// 모터 on
void run_motor()
{
  Serial.print(" motor start!! ");
  digitalWrite(motor, HIGH); 
}

// 모터 off
void stop_motor()
{
  Serial.print(" motor stop!! ");
  digitalWrite(motor, LOW);
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
  pasttime = millis();
}
 
void loop()
{
  sensor = analogRead(A0);    // 센싱
  now_sensing = (float)(1023 - sensor) / 1023 * 100;
  Serial.println(now_sensing);
  delay(1000);

  if (Serial.available()) { // 작동 명령 전달
    if(!flag){    // 미작동중 상태라면
      flag = true;    // 작동 플래그 처리
      run_motor();
      past  = millis();
    }
  }

  if(millis() - past >= 20000){ // 20초 작동 후 종료
    stop_motor();
    flag = false;
  }

  if(millis() - pasttime >= 600000){  // 10분 마다 송신
    SendMessage();
    pasttime = millis();
  } 
}
