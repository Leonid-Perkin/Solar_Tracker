#include <ESP8266WiFi.h>
#include <SPI.h>
#include <NTPClient.h>
#include <WiFiUdp.h>
#include <Servo.h>
#define DIV_R1 10000 
#define DIV_R2 1000
Servo servo;
const char* ssid = ""; // Название wifi
const char* password = ""; // Пароль wifi
const long utcOffsetInSeconds = 10800;
WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds); // конфигураци времени
int servo_p = 90;
const int potPin = 5;
int potValue = 0;
void setup() { 
  servo.attach(14);
  Serial.begin(9600);
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(16, OUTPUT);
  pinMode(potPin, INPUT);
  timeClient.begin();
}

void loop() {
  timeClient.update();
  //Serial.println(timeClient.getHours());
  potValue = analogRead(potPin)* ((DIV_R1 + DIV_R2) / DIV_R2) / 1024;
  if (potValue<12){
    digitalWrite(16, HIGH);
  }
  else{
    digitalWrite(16, LOW);
  }
  switch(int(timeClient.getHours()))
{
    case 0:
        servo_p = 75;
    case 1:
        servo_p = 75;
    case 2:
        servo_p = 75;
    case 3:
        servo_p = 75;
    case 4:
        servo_p = 75;
    case 5:
        servo_p = 75;
    case 6:
        servo_p = 75;
    case 7:
        servo_p = 77;
    case 8:
        servo_p = 77;
    case 9:
        servo_p = 80;
    case 10:
        servo_p = 85;
    case 11:
        servo_p = 87;
    case 12:
        servo_p = 90;
    case 13:
        servo_p = 90;
    case 14:
        servo_p = 95;
    case 15:
        servo_p = 95;
    case 16:
        servo_p = 100;
    case 17:
        servo_p = 105;    
    case 18:
        servo_p = 75;
    case 19:
        servo_p = 75;
    case 20:
        servo_p = 75;
    case 21:
        servo_p = 75;
    case 22:
        servo_p = 75;
    case 23:
        servo_p = 75;
        
}
  servo.write(servo_p);
  Serial.print(servo_p);
  Serial.print(" ");
  Serial.print(int(timeClient.getHours()));
  Serial.print(" ");
  Serial.println(potValue);
}
//the code was written by Leonid Perkin 
