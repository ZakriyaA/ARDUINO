#include <Arduino.h>
#include <IRremote.h>

// put function declarations here:
int myFunction(int, int);
int RECV_PIN = 11; // Define input pin on Arduino
int SEND_PIN = 3;  // Define output pin for IR sender
int buzzerPin = 9; // Pin connected to the passive buzzer
int touch = 2;  // pin for touch sensor
unsigned long lastReceivedTime = 0; // Variable to store the last received time
void sendAndReceiveIR();

void setup() {
  Serial.begin(115200);   // Initialize serial communication
  IrSender.begin(SEND_PIN); // Initialize IR sender on the specified pin
  IrReceiver.begin(RECV_PIN, ENABLE_LED_FEEDBACK); // Start the receiver
  pinMode(touch, INPUT); //sets touch sensor to input mode
}

void loop() {
  sendAndReceiveIR();

}


void sendAndReceiveIR() {
  while (true) {  // Loop indefinitely until the max interval condition is met to break out
    unsigned long irCode = 0xF7C03F; // Example NEC code
    IrSender.sendNEC(irCode, 32);    // Send a NEC signal with a specific code and length
    delay(200);                      // Short delay to allow for transmission
    if (IrReceiver.decode()) {
      unsigned long currentTime = millis(); // Get current time when signal is received
      if (lastReceivedTime != 0) {
        unsigned long timeInterval = currentTime - lastReceivedTime;
        Serial.print("Time interval since last received: ");
        Serial.print(timeInterval);
        Serial.println(" ms");
      }
      lastReceivedTime = currentTime; // Update the last received time
      IrReceiver.resume();            // Resume the receiver to receive the next IR signal
    }
  }
}