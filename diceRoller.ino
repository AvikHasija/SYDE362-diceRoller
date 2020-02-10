#include <Servo.h> 
int servoPin = 7;
int buttonOnePin = 3;
int buttonTwoPin = 2;
Servo Servo1;

int mode = 0;

void setup() {
   Serial.begin(9600);
   
   Servo1.attach(servoPin);

  // Reset to the starting point
  Servo1.write(90);
  delay(1000);

  pinMode(buttonOnePin, INPUT_PULLUP);
  pinMode(buttonTwoPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonOnePin), switchToModeOne, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonTwoPin), switchToModeTwo, RISING);
}

void loop(){
  Serial.println(mode);
  
  if(mode == 1){
    modeOne();
  } else if (mode == 2){
    modeTwo();
  }
}

void switchToModeOne(){
  mode = 1;
}

void switchToModeTwo(){
  mode = 2;
}

void modeOne(){
  int loops = random(4,8);
  while (loops > 0){
    Servo1.write(90);
    delay(600);
    Servo1.write(180);
    delay(600); 
    loops -= 1;
  }
  
  Servo1.write(35);
  delay(1000);
  Servo1.write(90);

  mode = 0;
}

void modeTwo(){
  Servo1.write(90);
  delay(600);
  Servo1.write(20);
  delay(1000);
  Servo1.write(90);

  mode = 0;
}
