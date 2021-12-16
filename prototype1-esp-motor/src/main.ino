#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

int BAUDRATE = 9600;

const char *ssid = "ScaryDary";
const char *password = "testtest123";

ESP8266WebServer server(80);

boolean direction = true;
boolean turnRight = false;
boolean turnLeft = false;

void handleBackward() {
    Serial.println("Backward");
    direction = false;
    turnRight = false;
    turnLeft = false;
}

void handleForward() {
    Serial.println("Forward");
    direction = true;
    turnRight = false;
    turnLeft = false;
}

void handleRight() {
    Serial.println("Right");
    turnLeft = false;
    turnRight = true;
}
void handleLeft() {
    Serial.println("Left");
    turnRight = false;
    turnLeft = true;
}


void setup() {
  delay(3000);
  Serial.begin(BAUDRATE);
  Serial.println("START");

  initializeMotors();

  WiFi.softAP(ssid, password);
  server.on("/backward", HTTP_GET, handleBackward);
  server.on("/forward", HTTP_GET, handleForward);
  server.on("/right", HTTP_GET, handleRight);
  server.on("/left", HTTP_GET, handleLeft);
  server.begin();
}


void loop(){
  server.handleClient();
  if (direction){
      if (turnLeft){
        motorsTurnLeft();
      }else if (turnRight){
        motorsTurnRight();
      }else{
        motorsForward();
      }
  }
  else{
    motorsBackward();
  }
}

