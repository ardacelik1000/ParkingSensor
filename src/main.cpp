#include <Arduino.h>
int triggerPin = 5;
int echoPin = 6;
int buzzer = 11; 
long zaman;
int mesafe;
void setup()
{
  pinMode(3,OUTPUT);
  pinMode(9,OUTPUT); 
  pinMode(10 ,OUTPUT); 
  pinMode(triggerPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}

void loop(){ 
  
  int i=0;
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2); 
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  zaman = pulseIn(echoPin, HIGH);
  mesafe = zaman * 0.034 / 2; 
  Serial.print(mesafe);
  if (mesafe <12) {  
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    digitalWrite(3,HIGH); 
    tone(buzzer,250);
  } 
  else if (mesafe > 18 && mesafe<= 25) {  
    digitalWrite(3,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    while (i<2){
      i++; 
      tone(buzzer,450);
      delay(200);
      noTone(buzzer);
      delay(200);
    }
    delay(2000); 
  }
  else if (mesafe >= 12 && mesafe<= 18) { 
    digitalWrite(3,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,HIGH);
    while (i<2) { 
      i++;
      tone(buzzer,450);
      delay(200);
      noTone(buzzer);
      delay(200);
    }
    delay(200);
  }
  else if (mesafe>25 ) { 
    digitalWrite(9,LOW);
    digitalWrite(3,LOW);
    digitalWrite(10,HIGH);
    noTone(buzzer);
  }
}

