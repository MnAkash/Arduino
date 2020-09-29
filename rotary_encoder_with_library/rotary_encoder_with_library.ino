#include <ClickEncoder.h>
#include <TimerOne.h>

ClickEncoder *encoder;
int16_t last, value;

void timerIsr() {
  encoder->service();
}

void displayAccelerationStatus() {

  Serial.print("Acceleration ");
  Serial.print(encoder->getAccelerationEnabled() ? "on " : "off");
}

void setup() {
  Serial.begin(9600);
  encoder = new ClickEncoder(A1, A0, A2);
  displayAccelerationStatus();


  Timer1.initialize(1000);
  Timer1.attachInterrupt(timerIsr); 
  
  last = -1;
}

void loop() {  
  value += encoder->getValue();
  
  if (value != last) {
    last = value;
    Serial.println(value);

  }
  
  ClickEncoder::Button b = encoder->getButton();
  if (b != ClickEncoder::Open) {
    Serial.print("Button: ");
    #define VERBOSECASE(label) case label: Serial.println(#label); break;
    switch (b) {
      VERBOSECASE(ClickEncoder::Pressed);
      VERBOSECASE(ClickEncoder::Held)
      VERBOSECASE(ClickEncoder::Released)
      VERBOSECASE(ClickEncoder::Clicked)
      case ClickEncoder::DoubleClicked:
          Serial.println("DoubleClicked");
          encoder->setAccelerationEnabled(!encoder->getAccelerationEnabled());
          Serial.print("  Acceleration is ");
          Serial.println((encoder->getAccelerationEnabled()) ? "enabled" : "disabled");
          displayAccelerationStatus();
        break;
    }
  }    
}
