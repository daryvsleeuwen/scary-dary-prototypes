int BAUDRATE = 9600;

#define A 2
#define B 3
#define C 4
#define D 5
#define NUMBER_OF_STEPS_PER_REV 512

#define MINIMAL_DELAY 1


void setup() {
  Serial.begin(BAUDRATE);

  pinMode(A,OUTPUT);
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
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
  int i = 0;
  while(i<NUMBER_OF_STEPS_PER_REV){
    reverseOneStep();
    Serial.println(NUMBER_OF_STEPS_PER_REV);
    i++;
  }
}