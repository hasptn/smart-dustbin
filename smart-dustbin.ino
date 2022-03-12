#include <Wire.h>
#include <Servo.h>
#define trigPin1 6
#define echoPin1 5
#define trigPin2 10
#define echoPin2 9

Servo myservo;

int ledhijau = A0;
int ledmerah = A1;
int buzzer = A2;

long duration1, distance1;
long duration2, distance2;

void setup()
{
  myservo.attach(3);
  pinMode(ledhijau, OUTPUT);
  pinMode(ledmerah, OUTPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, HIGH);
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
}

void loop()
{
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1 / 2) / 29.1;

  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2 / 2) / 29.1;

  if ((distance1 <= 15) && (distance2 <= 12))
  {
    digitalWrite(buzzer, HIGH);
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, HIGH);
    delay(1500);
    delay(1500);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, LOW);
    myservo.write(120);
  }

  if ((distance1 <= 15) && (distance2 >= 13))
  {
    myservo.write(0);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledhijau, HIGH);
    digitalWrite(ledmerah, LOW);
    delay(1500);
    delay(1500);
    digitalWrite(buzzer, LOW);
    digitalWrite(ledhijau, LOW);
    digitalWrite(ledmerah, LOW);
    myservo.write(120);
  }

  delay(200);
}
