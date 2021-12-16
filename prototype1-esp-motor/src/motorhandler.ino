#include <Stepper.h>

#define LA 5
#define LB 4
#define LC 0
#define LD 2

#define RA 14
#define RB 12
#define RC 13
#define RD 15

#define speed 100
#define stepsPerRevolution 100

Stepper myStepperLeft(stepsPerRevolution, LA, LB, LC, LD);
Stepper myStepperRight(stepsPerRevolution, RA, RB, RC, RD);


void initializeMotors(){
  pinMode(LA,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(LC,OUTPUT);
  pinMode(LD,OUTPUT);
  pinMode(RA,OUTPUT);
  pinMode(RB,OUTPUT);
  pinMode(RC,OUTPUT);
  pinMode(RD,OUTPUT);

  if (speed > 0) {
    myStepperLeft.setSpeed(speed);
    myStepperRight.setSpeed(speed);
  }
}

void motorsForward(){
    myStepperRight.step(1);
    myStepperLeft.step(1);
}

void motorsBackward() {
//    myStepperRight.step(-1);
//     myStepperLeft.step(-1);
}

void motorsTurnLeft() {
    myStepperRight.step(1);
}

void motorsTurnRight() {
    myStepperLeft.step(1);
}


