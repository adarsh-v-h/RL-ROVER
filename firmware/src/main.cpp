
#include <Arduino.h>
 
// Purpose of this file, for now: nothing more than proving the ESP32
// toolchain is set up correctly. No sensors, no motors, no WiFi yet.
// If this builds and, once flashed to a real board, blinks the onboard
// LED and prints to serial, PlatformIO is correctly configured.
 
#define LED_PIN 2  // Onboard LED on most ESP32 devkit boards
 
void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  Serial.println("PlatformIO + ESP32 toolchain: OK");
}
 
void loop() {
  digitalWrite(LED_PIN, HIGH);
  delay(500);
  digitalWrite(LED_PIN, LOW);
  delay(500);
  Serial.println("Alive");
}