#include <SoftwareSerial.h>
#include <DHT.h>

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

bool flag = false;
float now_sensing =0;

int motor = 9;

unsigned long past = 0;
unsigned long pasttime =0;

void setup()
{
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  dht.begin();
  pasttime = millis();
  digitalWrite(motor, HIGH);
}

void loop()
{
  float temperature = dht.readTemperature();

  if(!isnan(temperature)){
    now_sensing = temperature;
  }

  if(Serial.available()){
    if(!flag){
      flag = true;
      digitalWrite(motor, LOW);
      past = millis();
    }
  }

  if(millis() - past >= 5000){
    if(flag){
      digitalWrite(motor, HIGH);
      flag = false;
    }
  }

  if(millis() - pasttime >= 5000){
    String str = String(temperature, 1);
    Serial.println(str);
    pasttime = millis();
  }
}
