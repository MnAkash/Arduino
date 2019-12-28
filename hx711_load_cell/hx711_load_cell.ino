#include <HX711.h>

// Scale Settings
const int DOUT = A1;  //5
const int SCALE_SCK_PIN = A0;  //6

HX711 scale;

void setup() {
  Serial.begin(115200);
  scale.begin(DOUT, SCALE_SCK_PIN);
  scale.set_scale(56);// <- set here calibration factor!!! 56
  scale.tare();
}

void loop() {
  float weight = scale.get_units(1);
  Serial.println(String(weight, 2));
  delay(200);
}
