#include "Arduino.h"
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>


int BAUDRATE = 9600;

#define A 4
#define B 0
#define C 2
#define D 14
#define NUMBER_OF_STEPS_PER_REV 512

#define MINIMAL_DELAY 1

const char *ssid = "ScaryDary";
const char *password = "testtest123";

ESP8266WebServer server(80);

boolean direction = true;

void handleBackward() {
  direction = false;
}

void handleForward() {
  direction = true;
}


void setup() {
  delay(3000);
  Serial.begin(BAUDRATE);
  Serial.println("START");
  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);

  WiFi.softAP(ssid, password);
  server.on("/backward", HTTP_GET, handleBackward);
  server.on("/forward", HTTP_GET, handleForward); // when the server receives a request with /data/ in the string then run the handleSentVar function
  server.begin();
}


void write(int a,int b,int c,int d){
  digitalWrite(A,a);
  digitalWrite(B,b);
  digitalWrite(C,c);
  digitalWrite(D,d);
}

void forwardOneStep(){
  write(1,0,0,0);
  delay(MINIMAL_DELAY);
  write(1,1,0,0);
  delay(MINIMAL_DELAY);
  write(0,1,0,0);
  delay(MINIMAL_DELAY);
  write(0,1,1,0);
  delay(MINIMAL_DELAY);
  write(0,0,1,0);
  delay(MINIMAL_DELAY);
  write(0,0,1,1);
  delay(MINIMAL_DELAY);
  write(0,0,0,1);
  delay(MINIMAL_DELAY);
  write(1,0,0,1);
  delay(MINIMAL_DELAY);
}

void reverseOneStep() {
  write(1,0,0,1);
  delay(MINIMAL_DELAY);
  write(0,0,0,1);
  delay(MINIMAL_DELAY);
  write(0,0,1,1);
  delay(MINIMAL_DELAY);
  write(0,0,1,0);
  delay(MINIMAL_DELAY);
  write(0,1,1,0);
  delay(MINIMAL_DELAY);
  write(0,1,0,0);
  delay(MINIMAL_DELAY);
  write(1,1,0,0);
  delay(MINIMAL_DELAY);
  write(1,0,0,0);
}

void loop(){
  server.handleClient();
  if (direction){
    forwardOneStep();
  }
  else{
    reverseOneStep();
  }
}
