#include <Servo.h> 
int servoPin = 7;
Servo Servo1;

int mode = 2;

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
    delay(500);
    Servo1.write(90);
    delay(500); 
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

void testMovements(){
   // Make servo go to 0 degrees 
   Servo1.write(0); 
   delay(1000); 
   // Make servo go to 90 degrees 
   Servo1.write(90); 
   delay(1000); 
   // Make servo go to 180 degrees 
   Servo1.write(180); 
   delay(1000); 
}
