#include <NewPing.h>

// output pin
#define OUTPUT_PIN 5

// button pin


// sonar variables
#define TRIGGER_PIN 2
#define ECHO_PIN 3
#define MAX_DISTANCE 128

int buttonState = 0;
int previousState = 0;

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);


//to check if the garbage bin has closed
const int trigPin = 9;
const int echoPin = 10;

NewPing close_check(trigPin, echoPin, MAX_DISTANCE);
long duration;
int initial = 0;

void setup() {
  pinMode(OUTPUT_PIN, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  pinMode(13, OUTPUT);
}

void loop() {
  delay(1000);

 int change = close_check.ping_cm();
 if((change  - initial)< (-5) && (change  - initial)<6000 ){
    sendOutput();
  }
  initial = change;
  
}

void sendOutput() {
  unsigned int dist = sonar.ping_cm();
  int output = 0;
  digitalWrite(OUTPUT_PIN, HIGH);
  digitalWrite(13, HIGH);
  delay(500);
  Serial.println(dist);
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

