#include <NewPing.h>

// output pin
#define OUTPUT_PIN 5

// button pin
#define BUTTON_PIN 4

// sonar variables
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 128

int buttonState = 0;
int previousState = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  delay(50);

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH && buttonState != previousState) {
    sendOutput();
  }
  previousState = buttonState;
}

void sendOutput() {
  unsigned int dist = sonar.ping_cm();
  int output = 0;
  digitalWrite(OUTPUT_PIN, HIGH);
  digitalWrite(13, HIGH);
  delay(500);
  
  for (int i = 0; i < 7; i++) {
    output = dist % 2;
    if (output == 1) {
      digitalWrite(OUTPUT_PIN, HIGH);
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(OUTPUT_PIN, LOW);
      digitalWrite(13, LOW);
    }
    dist = dist / 2;
    delay(50);
  }
  digitalWrite(OUTPUT_PIN, LOW);
  digitalWrite(13, LOW);
}

