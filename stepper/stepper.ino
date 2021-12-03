// Include the Arduino Stepper.h library:
#include <Stepper.h>

// Define number of steps per rotation:
const int stepsPerRevolution = 2048;
// Wiring:
// Pin 8 to IN1
// Pin 9 to IN2
// Pin 10 to IN3
// Pin 11 to IN4
// Create stepper object called 'myStepper', note the pin order:
Stepper myStepper1 = Stepper(stepsPerRevolution, 6, 8, 7, 9);
Stepper myStepper2 = Stepper(stepsPerRevolution, 2, 4, 3, 5);
Stepper myStepper3 = Stepper(stepsPerRevolution, 10, 12, 11, 13);
void setup() {
  // Set the speed to 1 rpm:
  myStepper1.setSpeed(5);
  myStepper2.setSpeed(5);
  myStepper3.setSpeed(5);
  //shutter
  pinMode(A0,OUTPUT);
  // Begin Serial communication at a baud rate of 9600:
  Serial.begin(9600);
}
float v=0.002;
char c = 'N';
void loop() {

  // Up Down Left Right Front Back Shot

  if (Serial.available() > 0)
  {
    c = Serial.read() ;
    if (c == 'F')
    {
      myStepper1.step(stepsPerRevolution *2* v);
      Serial.print('P');
    }
     
    else if ( c == 'B')
    {
      myStepper1.step(-stepsPerRevolution *2* v);
      Serial.print('P');
    }
    
    else if ( c == 'L')
    {
      myStepper2.step(stepsPerRevolution *5* v);
      Serial.print('P');
    }
    
    else if ( c == 'R')
    {      
      myStepper2.step(-stepsPerRevolution *5* v);
      Serial.print('P');
    }
    
    else if ( c == 'U')
    {
      myStepper3.step(-stepsPerRevolution * 0.005);
      Serial.print('P');
    }
    
    else if ( c == 'D')
    {
      myStepper3.step(stepsPerRevolution * 0.005);
      Serial.print('P');
    }
    else if ( c == 'S')
    {
      digitalWrite(A0,HIGH);      
      delay(500);
      digitalWrite(A0,LOW);
      delay(1000);
      Serial.print('P');
    }
    else
    {
      Serial.print('N');
    }

  }
  c = 'N';
}
