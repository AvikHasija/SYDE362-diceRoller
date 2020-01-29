#include <Servo.h> 
int servoPin = 7;
Servo Servo1;

int mode = 1;

void setup() {
   Servo1.attach(servoPin);

  // Reset to the starting point
  Servo1.write(90);
  delay(1000);

  if (mode == 1) {
   modeOne(); 
  }
  else if (mode == 2) {
   modeTwo(); 
  }
   
}

void loop(){
}

void modeOne(){
  int loops = 6;
  while (loops > 0){
    Servo1.write(0);
    delay(600);
    Servo1.write(90);
    delay(600); 
    loops -= 1;
  }
  
  Servo1.write(180);
  delay(1000);
  Servo1.write(90);
}

void modeTwo(){
  Servo1.write(120);
  delay(1000);
  Servo1.write(90);
}
