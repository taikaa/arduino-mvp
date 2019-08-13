#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>


// pin definition 
#define EN 9
#define IN1 6
#define IN2 7

const int RECV_PIN = 3;

// integer to remember toggle state
int togglestate = 0;

// define IR Receiver and Results Object
IRrecv irrecv(RECV_PIN);
decode_results results;

void setup() {
  // initialize motor pins
  pinMode(EN, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  // Serial Monitor at 9600 baud
  Serial.begin(9600);
  // enable the IR Receiver
  irrecv.enableIRIn();
}

void loop() {
  if (irrecv.decode(&results)) {
//   Print code in HEX
   Serial.println(results.value, HEX);
   switch(results.value) {
    case 0xFF30CF:
      Serial.println("Pressed 1");
    if (togglestate == 0) {
      Serial.println("Turn motor on");
      digitalWrite(IN1, HIGH);
      analogWrite(EN, 255);
      togglestate = 1;
    }
    else {
      Serial.println("Motor is already on");
    }
    break;
    case 0xFF6897:
    Serial.println("Pressed 0");
    if (togglestate == 0) {
      Serial.println("Motor is already off");
    }
    else {
      Serial.println("Turning motor off");
      digitalWrite(IN1, LOW);
      togglestate = 0;
    }
    break;
   }
   irrecv.resume();
  }
}
