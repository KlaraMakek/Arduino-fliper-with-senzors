/*
 * This is program code that controls the sensors, the speaker and is used to print on the LCD screen
 */

#include <LiquidCrystal.h>

LiquidCrystal lcd(6, 7, 1, 2, 3, 4);

int Score = 0;
int speaker = 9;

void setup() {
  //definiramo pinove na MKR1000
  pinMode(A3, INPUT); //  vibration sensor
  pinMode(A4, INPUT); //  vibration sensor
  pinMode(A5, INPUT); //  vibration sensor 
  pinMode(A6, INPUT); // reset button
  pinMode(speaker, OUTPUT); // speaker
  
  // postavke za LCD:
  lcd.begin(16, 2);
  lcd.clear();
  
  lcd.print("HIGHSCORE:");  // prints on the screen "HIGHSCORE"
}

void loop() {

  lcd.setCursor(0, 1);
 
  if (digitalRead(A3) == LOW) { // if the vibration sensor recorded a "hit"
    tone(speaker, 1915,200); // activate the speaker
    Score += 30; // add points to the total score         
    delay(200); // pause 200 milliseconds
  }
 
  if (digitalRead(A4) == LOW) { // vibration sensor
    tone(speaker, 1915,200);
    Score += 30;                
    delay(200);  
  }
 
  if (digitalRead(A5) == LOW) { // vibration sensor
    tone(speaker, 1915,200);
    Score += 30;                
    delay(200);
  }

  if (digitalRead(A6) == HIGH) { // reset button
    Score = 0;
    lcd.clear();      
    lcd.begin(16, 2);
    lcd.print("HIGHSCORE:");
    lcd.setCursor(0, 1); 
    delay(200);
  }

  lcd.print(Score);  // prints the result of the game
}  
