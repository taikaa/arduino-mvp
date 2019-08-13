#include <L298N.h>


//pin definition
#define EN 9 
#define IN1 6
#define IN2 7

// adding second motor
#define EN2 10
#define IN3 5
#define IN4 4



void setup() {
  // initialize motor pins 
  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  // initialize second motor pins
  pinMode(EN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  //used for display information
  Serial.begin(9600);
  while(!Serial);
  Serial.println("Input 1 to start Motor 2 to turn off");
  //motor.setSpeed(80); // an integer between 0 and 255

}

//create a motor instance
//L298N motor(EN, IN1, IN2); // IN1 and IN2 are the digial pins connected to IN1 and IN2 pins of the module


void loop() {

  if (Serial.available()) { // next try doing this whole loop in switch statements
    int state = Serial.parseInt();
    if (state == 1) {
      digitalWrite(IN1, HIGH);
      digitalWrite(IN2, LOW);
      analogWrite(EN, 255);
     // digitalWrite(IN3, HIGH);
     // analogWrite(EN2, 255);
      Serial.println("Turned on the motor to HIGH");
    }
    else if (state == 2) {
      digitalWrite(IN1, LOW);
      // turn off second motor
     // digitalWrite(IN3, LOW);
      Serial.println("Turned off the motor");
    }
  }
}
