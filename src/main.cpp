#include <Arduino.h>
#include <IRremote.h>

// put function declarations here:
int myFunction(int, int);
int RECV_PIN = 11; // Define input pin on Arduino
int SEND_PIN = 3;  // Define output pin for IR sender
int buzzerPin = 9; // Pin connected to the passive buzzer

void setup() {
  Serial.begin(115200);   // Initialize serial communication
  IrSender.begin(SEND_PIN); // Initialize IR sender on the specified pin
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  // put your setup code here, to run once:
  int result = myFunction(2, 3);
}

void loop() {
  // put your main code here, to run repeatedly:
}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}