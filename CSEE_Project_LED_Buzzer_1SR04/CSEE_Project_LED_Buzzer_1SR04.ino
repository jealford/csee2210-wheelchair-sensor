/*
 * CSEE 2210 - Final Project
 * 4/25/2019
 * 
 * Takes input from 4 SR-04 ultrasonic sensors and flashes and LED
 * and activates a buzzer when the sensors detect an object within 
 * a certain threshold.
 * 
 * Authors: Jake Alford and Ricardo Zacarias
 */

#include "SR04.h" //library for ultrasonic sensors

//pair of side sensors
#define TRIG_PIN 12 // white to white
#define ECHO_PIN 11 // red to orange
#define TRIG_PIN2 8 // white to white
#define ECHO_PIN2 9 // red to orange

//pair of front sensors
#define TRIG_PIN3 13 // white to white
#define ECHO_PIN3 14 // red to orange
#define TRIG_PIN4 15 // white to white
#define ECHO_PIN4 16 // red to orange

//side sensors
SR04 sr04R = SR04(ECHO_PIN, TRIG_PIN);
SR04 sr04L = SR04(ECHO_PIN2, TRIG_PIN2);
long rDist;
long lDist;

//front sensors
SR04 sr04RF = SR04(ECHO_PIN3, TRIG_PIN3);
SR04 sr04LF = SR04(ECHO_PIN4, TRIG_PIN4);
long rFDist;
long lFDist;

//pins for LED and buzzer
int led = 4;
int buzzer = 2;

void setup() {
  Serial.begin(9600);
  delay(100);
  pinMode(led, OUTPUT); //initialize the LED pin as output
  pinMode(buzzer, OUTPUT); //initialize the buzzer pin as an output
}

void loop() {
  //get distance data in from sensors
  rDist = sr04R.Distance();
  lDist = sr04L.Distance();
  rFDist = sr04RF.Distance();
  lFDist = sr04LF.Distance();

/*
 * The five thresholds for the buzzer and LED to be triggered at. 
 * As the obstacle gets closer to the sensor, the speed of the buzzer
 * and LED goes up to warn the user that they are gettting closer to the 
 * obstacle. At the closest threshold, the buzzer and LED will be on at
 * a full, constant rate.
 */
  
  if ((rDist < 25 && rDist >= 20) ||  
      (lDist < 25 && lDist >= 20) ||
      (rFDist < 20 && rFDist >= 15) ||
      (lFDist < 20 && lFDist >= 15)
      ){
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

  else if((rDist < 20 && rDist >= 15) ||  
      (lDist < 20 && lDist >= 15) ||
      (rFDist < 20 && rFDist >= 15) ||
      (lFDist < 20 && lFDist >= 15)
      ){ 
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

  if ((rDist < 15 && rDist >= 10) ||  
      (lDist < 15 && lDist >= 10) ||
      (rFDist < 15 && rFDist >= 10) ||
      (lFDist < 15 && lFDist >= 10)
      ){
    for (int i = 0; i < 5000; i++) {
      digitalWrite(buzzer, HIGH);
      analogWrite(led, 125);
    }
    for (int i = 0; i < 10000; i++) {
      digitalWrite(buzzer, LOW);
      analogWrite(led, 0);
    }
  }

  else if (rDist < 10 || lDist < 10 ||
          rFDist < 10 || lFDist <10) {
    digitalWrite(buzzer, HIGH);
    analogWrite(led, 125);
  }

  else {
    analogWrite(led, 0);
    digitalWrite(buzzer, LOW);
  }
  delay(100);
}
