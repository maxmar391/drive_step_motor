// Include the AccelStepper Library
#include <AccelStepper.h>

// Define pin connections
const int dirPin = 2;
const int stepPin = 3;

// Define motor interface type
#define motorInterfaceType 1

// Creates an instance of the stepper
AccelStepper myStepper(motorInterfaceType, stepPin, dirPin);

// define remaining variables
int i = 0;
int cycles = 200;
int motorSpeed = 1000;
int motorAngle = 50;
int motorDelay = 300;


void setup() 
{
  Serial.begin(9600); // start transmission on serial monitor

  myStepper.setMaxSpeed(motorSpeed * 1.5); // set the maximum speed
  myStepper.setAcceleration(motorSpeed / 2); // set the maximum acceleration factor
  myStepper.setSpeed(motorSpeed); // set the initial speed
  myStepper.moveTo(motorAngle); // set the target position to 180° (200 steps per revolution)
}



void loop() {
  if (i < cycles) 
  {
    // Change direction once the motor reaches target position
    if (myStepper.distanceToGo() == 0) {
      myStepper.moveTo(-myStepper.currentPosition()); // reverse the target position

      delay(motorDelay); // wait for half a second before changing direction

      i++; // increase counter by one for each half revolution

      Serial.print("Testzyklus: ");
      Serial.println(i); // print the current test cycle index
    }

    // Move the motor half a revolution
    myStepper.run();
  }
  else 
  {
    Serial.println("Test abgeschlossen");
  }
}
