/*
 * This is program code that controls servo motors with pinball machines
 */

#include <Servo.h>
Servo motor1;
Servo motor2;

int Tipkalo = 10; // we define on which pin the buttons are located
int Tipkalo2 = 6;

int PozicijaMotora = 0; // we define engine positions
int PozicijaMotora2 = 90; 

void setup () {
  motor1.attach(8); // servo motor 1 on pin 8
  pinMode(Tipkalo, INPUT_PULLUP);
   
  motor2.attach(9); // servo motor 2 on pin 9
  pinMode(Tipkalo2, INPUT_PULLUP);

// initial button states
  Tipkalo == LOW; 
  Tipkalo2 == LOW;
}

void loop () {
  if(digitalRead(Tipkalo) == HIGH) { // if the player pressed button no. 1
    motor1.write(90); // activate the servo motor at 90 degrees
  }
  else { // otherwise return the servo motor to the home position
    motor1.write(PozicijaMotora);
  }
  delay(100);
  
  if(digitalRead(Tipkalo2) == HIGH) { // if the player pressed button no. 2
    motor2.write(0); // activate the servo motor at 0 degrees
  }
  else { // otherwise return the servo motor to the home position
    motor2.write(PozicijaMotora2);
  }
  delay(100);
}
