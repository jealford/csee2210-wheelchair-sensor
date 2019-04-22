#include "SR04.h"
#define TRIG_PIN 12 // white to white
#define ECHO_PIN 11 // red to orange
#define TRIG_PIN2 8 // white to white
#define ECHO_PIN2 9 // red to orange
SR04 sr04R = SR04(ECHO_PIN, TRIG_PIN);
SR04 sr04L = SR04(ECHO_PIN2, TRIG_PIN2);
long rDist;
long lDist;

int led = 4;
int buzzer = 2;

void setup() {
  Serial.begin(9600);
  delay(1000);
  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT); //initialize the buzzer pin as an output
}

void loop() {
  rDist = sr04R.Distance();
  lDist = sr04L.Distance();


  
  if ((rDist < 25 && rDist >= 20) ||  (lDist < 25 && lDist >= 20)){
    //analogWrite(led, 125);
    for (int i = 0; i < 19000; i++) {
      digitalWrite(buzzer, HIGH);
      analogWrite(led, 125);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(buzzer, LOW);
      analogWrite(led, 0);
    }
  }

  else if (rDist < 20 && rDist >= 15) {
    //analogWrite(led, 125);
    for (int i = 0; i < 10000; i++) {
      digitalWrite(buzzer, HIGH);
      analogWrite(led, 125);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(buzzer, LOW);
      analogWrite(led, 0);
    }
  }

  else if (rDist < 15 && rDist >= 10) {
    //analogWrite(led, 125);
    for (int i = 0; i < 5000; i++) {
      digitalWrite(buzzer, HIGH);
      analogWrite(led, 125);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(buzzer, LOW);
      analogWrite(led, 0);
    }
  }

  else if (rDist < 10) {
    digitalWrite(buzzer, HIGH);
    analogWrite(led, 125);
  }

  else {
    analogWrite(led, 0);
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
