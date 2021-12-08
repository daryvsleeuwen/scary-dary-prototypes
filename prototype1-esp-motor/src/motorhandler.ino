#define LA 5
#define LB 4
#define LC 0
#define LD 2

#define RA 14
#define RB 12
#define RC 13
#define RD 15

#define MINIMAL_DELAY 1

void initializeMotors(){
  pinMode(LA,OUTPUT);
  pinMode(LB,OUTPUT);
  pinMode(LC,OUTPUT);
  pinMode(LD,OUTPUT);
  pinMode(RA,OUTPUT);
  pinMode(RB,OUTPUT);
  pinMode(RC,OUTPUT);
  pinMode(RD,OUTPUT);
}

void writeForward(int a,int b,int c,int d, boolean right){
    if (right) {
        digitalWrite(RA,a);
        digitalWrite(RB,b);
        digitalWrite(RC,c);
        digitalWrite(RD,d);
    }else {
        digitalWrite(LA,a);
        digitalWrite(LB,b);
        digitalWrite(LC,c);
        digitalWrite(LD,d);
    }
}

void forwardOneStep(boolean right){
  writeForward(1,0,0,0, right);
  delay(MINIMAL_DELAY);
  writeForward(1,1,0,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,1,0,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,1,1,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,1,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,1,1, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,0,1, right);
  delay(MINIMAL_DELAY);
  writeForward(1,0,0,1, right);
  delay(MINIMAL_DELAY);
}

void backwardOneStep(boolean right) {
  writeForward(1,0,0,1, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,0,1, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,1,1, right);
  delay(MINIMAL_DELAY);
  writeForward(0,0,1,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,1,1,0, right);
  delay(MINIMAL_DELAY);
  writeForward(0,1,0,0, right);
  delay(MINIMAL_DELAY);
  writeForward(1,1,0,0, right);
  delay(MINIMAL_DELAY);
  writeForward(1,0,0,0, right);
}


void motorsForward(){
    forwardOneStep(true);
    forwardOneStep(false);
}

void motorsBackward() {
    backwardOneStep(true);
    backwardOneStep(false);
}

void motorsTurnLeft() {
    forwardOneStep(false);
}

void motorsTurnRight() {
    forwardOneStep(true);
}


