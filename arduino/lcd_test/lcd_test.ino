#include <LiquidCrystal.h>
const int c = 261;
const int d = 294;
const int e = 329;
const int f = 349;
const int g = 391;
const int gS = 415;
const int a = 440;
const int aS = 455;
const int b = 466;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 830;
const int aH = 880;
 
const int buzzerPin = 9;

 
int counter = 0;


LiquidCrystal lcd(8,2,4,5,6,7);
const int inPin = 3;
const int ledPin = 13;

int runningSum;
String receivedPacket;
int currBit = 0;

void setup() {
  lcd.begin(16,2);
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(inPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  currBit = digitalRead(inPin);
  if (currBit == HIGH) {
    int runningSum = 0;
    receivedPacket = "";
    delay(510);
    for (int i = 0; i < 7; i++) {
      currBit = digitalRead(inPin);
      runningSum = runningSum + (currBit * pow(2, i));
      if (currBit == HIGH) {
        digitalWrite(ledPin, HIGH);
      } else {
        digitalWrite(ledPin, LOW);
      }
      receivedPacket = currBit + receivedPacket;
      delay(50);
    }

    if (runningSum > 75) {
      runningSum = 0;
    }
    
    updateLCD(runningSum);
    if (runningSum < 5){
        //Play first section
//  firstSection();
// 
//  //Play second section
//  secondSection();
// 
//  //Variant 1
//  beep(f, 250);  
//  beep(gS, 500);  
//  beep(f, 350);  
//  beep(a, 125);
//  beep(cH, 500);
//  beep(a, 375);  
//  beep(cH, 125);
//  beep(eH, 650);
// 
//  delay(500);
// 
//  //Repeat second section
//  secondSection();
// 
//  //Variant 2
//  beep(f, 250);  
//  beep(gS, 500);  
//  beep(f, 375);  
//  beep(cH, 125);
//  beep(a, 500);  
//  beep(f, 375);  
//  beep(cH, 125);
//  beep(a, 650);  
// 
//  delay(650);
//      
//      
      }
    Serial.println(runningSum);
  }

}

void updateLCD(int runningSum) {
  lcd.clear();
  lcd.setCursor(0,0); // Sets the location at which subsequent text written to the LCD will be displayed
  lcd.print("Distance: "); // Prints string "Distance" on the LCD
  lcd.print(runningSum); // Prints the distance value from the sensor
  lcd.print(" cm");
}

void beep(int note, int duration)
{
  //Play tone on buzzerPin
  tone(buzzerPin, note, duration);
 
  //Play different LED depending on value of 'counter'
  if(counter % 2 == 0)
  {
   
    delay(duration);
    
  }else
  {
   
    delay(duration);
   
  }
 
  //Stop tone on buzzerPin
  noTone(buzzerPin);
 
  delay(50);
 
  //Increment counter
  counter++;
}
 
void firstSection()
{
  beep(a, 500);
  beep(a, 500);    
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);  
  beep(a, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
 
  beep(eH, 500);
  beep(eH, 500);
  beep(eH, 500);  
  beep(fH, 350);
  beep(cH, 150);
  beep(gS, 500);
  beep(f, 350);
  beep(cH, 150);
  beep(a, 650);
 
  delay(500);
}
 
void secondSection()
{
  beep(aH, 500);
  beep(a, 300);
  beep(a, 150);
  beep(aH, 500);
  beep(gSH, 325);
  beep(gH, 175);
  beep(fSH, 125);
  beep(fH, 125);    
  beep(fSH, 250);
 
  delay(325);
 
  beep(aS, 250);
  beep(dSH, 500);
  beep(dH, 325);  
  beep(cSH, 175);  
  beep(cH, 125);  
  beep(b, 125);  
  beep(cH, 250);  
 
  delay(350);
}

