#include <Stepper.h>

const int stepsPerRevolution = 200;
const int stepperSpeed = 60; // rpm
const float degPerMSecond = stepperSpeed / 60000.0;

int ch5;
int stepperLoc = 0; // Current angle position in degrees
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

const int neutralPWM = 1500; // Define neutral position (in µs)
const int deadzone = 30;     // Define a deadzone to prevent jitter

void setup() {
  myStepper.setSpeed(stepperSpeed);
  pinMode(5, INPUT); // Channel 5 input pin
  Serial.begin(9600);
}

void loop() {
  // Read the PWM pulse width from the RC controller on channel 5
  ch5 = pulseIn(5, HIGH, 30000);
    if (ch5 == 0){
    Serial.print("Caught 0");
    return;
  }

  // Calculate the difference from neutral
  int offset = ch5 - neutralPWM;

  // Determine the movement direction based on the offset
  if (abs(offset) > deadzone) { // Only act if outside the deadzone
    int mappedSpeed = map(abs(offset), 0, 500, 0, 200); // 500 is max offset
    myStepper.setSpeed(mappedSpeed);
    
    int diff = map(offset, -500, 500, -180, 180); // Map offset to angle
    
    // Convert degree difference to steps and move the stepper
    int stepsToMove = (stepsPerRevolution / 360.0) * diff;
    myStepper.step(stepsToMove);
    
    // Update the stepper's new location
    stepperLoc += diff;
    
    // Delay proportional to movement, if needed
    delay(abs(diff) * degPerMSecond);
  }
  
  // Output for debugging
  Serial.print("PWM: "); Serial.print(ch5);
  Serial.print(" | Offset from Neutral: "); Serial.print(offset);
  Serial.print(" | Stepper Loc: "); Serial.println(stepperLoc);
}
