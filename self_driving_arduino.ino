#include <Servo.h>


// 오른쪽 모터
int ENA = 11;
int IN1 = 10;
int IN2 = 9;

// 왼쪽 모터
int ENB = 4;
int IN3 = 6;
int IN4 = 5;

//서보 모터
int servo = 3;
void setup()
{
  pinMode(ENA,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
}

void loop()
{
  //오른쪽모터 회전 → 역회전은 HIGH/LOW만 바꿔 주면 댐
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 255);
  delay(1000);
  analogWrite(ENA,0);
  delay(1000);


  //왼쪽모터 회전
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, 255);
  delay(1000);
  analogWrite(ENB,0);
  delay(1000);
}