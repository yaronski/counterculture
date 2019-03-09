/*
  ____Counter_Culture____
  → Learning to count ... 
  → easy as ichi, dwa, sān!
  
  Final Project
  Digital Fabrication by Prof. N.Tai
  NTUT 2018/19
  Y.Z.

*/

/**********************************/

#include "SD.h"                 //Lib to read SD card
#include "TMRpcm.h"             //Lib to play auido
#include "SPI.h"                //Lib SPI for SD card
#include "SevSeg.h"             //Lib 7 segment display

#define SD_ChipSelectPin 53     //Chip select is pin number 53 on Arduino Mega 2560
//  
//
//
//
TMRpcm audio;                   //Lib object »audio«
SevSeg sevseg;                  //Lib object »sevseg«

/* languages: 
'jp' -> japanese
'cn' -> chinese
'ko' -> korean
'pl' -> polish
'hi' -> hindi
'de' -> german
*/

const String langArray[] = {"jp", "cn", "ko", "hi", "pl", "de"};
String lang;                                            

int song_number = -1;

int readSw = 0;
int maxVoltageBits = 1023;
float dividedBits = maxVoltageBits / 5;       // = 204,6 at 6 pos. rotary switch
int rotaryInput = A5;
int myDebounce = 150;
int randomButton = 7;
int rndVal = 0;
int mainButton = 2;

/*************************/
void setup() {

  audio.speakerPin = 11;
  int freshButtonpress = 1;


  // 7 segment stuff
  byte numDigits = 1;
  byte digitPins[] = {};
  byte segmentPins[] = {28, 32, 36, 30, 34, 26, 24, 40};
  //28, 32, 36, 30, 34, 26, 24, 40         [Arduino pin]
  // A,  B,  C,  D,  E,  F,  G,  DP CHANGE [Segment]
  // 7,  6,  4,  2,  1,  9, 10,  5         [Display pin]
  
  bool resistorsOnSegments = true;
  bool disableDecPoint = false;
 
  // 9V +voltage at the common pins (8; opt. 1) and ground to each segment pin
  byte hardwareConfig = COMMON_CATHODE;  
 
  sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments, disableDecPoint);
  //    sevseg.setBrightness(100);

  //Auido out on pin 9 //A0
  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {
    Serial.println("SD fail");
    return;
  }

  pinMode(mainButton, INPUT_PULLUP);      // Button 2 with internal pull up to chage track
  pinMode(rotaryInput, INPUT);            // Analog in rotary switch

  pinMode(randomButton, INPUT_PULLUP);

  audio.setVolume(4);                     //  0 to 7. Set volume level
  audio.quality(0);                       //  Set 1 for 2x oversampling Set 0 for normal
}

/*************************/
void loop() {

  int freshButtonpress = 0;
  
  readSw = analogRead(rotaryInput) + 100;     // to move away from the border from the next country ... language!

  if (readSw < round(dividedBits * 1)) {
    lang = langArray[0];
  }
  else if (readSw < round(dividedBits * 2)) {
    lang = langArray[1];
  }
  else if (readSw < round(dividedBits * 3)) {
    lang = langArray[2];
  }
  else if (readSw < round(dividedBits * 4)) {
    lang = langArray[3];
  }
  else if (readSw < round(dividedBits * 5)) {
    lang = langArray[4];
  }
  else if (readSw > round(dividedBits * 5)) {
    lang = langArray[5];
  }

// **Debugging**
//  Serial.println(readSw);
//  Serial.println(lang);
//  Serial.print("song_number = ");
//  Serial.println(song_number);
//  Serial.print("Random Value = ");
//  Serial.println(rndVal);
//  Serial.print("freshButtonpress Before = ");
//  Serial.println(freshButtonpress);
//  Serial.println("/audio/" + lang + "_0" + String(song_number) + ".wav");

  if (digitalRead(mainButton) == LOW && rndVal == 0) {
    song_number++;
    Serial.println("Next button pressed");
    freshButtonpress = 1;
    delay(myDebounce);
  }

  if (digitalRead(mainButton) == LOW && rndVal == 1) {
    song_number = random(0, 11);
    freshButtonpress = 1;
    delay(myDebounce);
  }

  if (digitalRead(randomButton) == HIGH) {
    rndVal = 1;
    delay(10);
  }
  
  if (digitalRead(randomButton) == LOW && rndVal == 1){
    rndVal = 0;
    delay(10);
  }

  if (song_number == 11) {
    song_number = 0;
    delay(100);                 // avoid debounce
  }

  String path = "/audio/" + lang + "_0" + String(song_number) + ".wav";
  const char *newPath = path.c_str();
  
  if (freshButtonpress == 1){
    audio.play(newPath);
//    audio.loop(0); 
  }

  switch (song_number) {
    case -1:
      sevseg.blank();
      break;
    case 0:
      sevseg.setNumber(0, 0);
      break;
    case 1:
      sevseg.setNumber(1, 0);
      break;
    case 2:
      sevseg.setNumber(2, 0);
      break;
    case 3:
      sevseg.setNumber(3, 0);
      break;
    case 4:
      sevseg.setNumber(4, 0);
      break;
    case 5:
      sevseg.setNumber(5, 0);
      break;
    case 6:
      sevseg.setNumber(6, 0);
      break;
    case 7:
      sevseg.setNumber(7, 0);
      break;
    case 8:
      sevseg.setNumber(8, 0);
      break;
    case 9:
      sevseg.setNumber(9, 0);
      break;
    case 10:   

      int x = 0;

      if (x == 0){
        
      sevseg.blank();
      sevseg.refreshDisplay();
      
      digitalWrite(28, LOW);
      digitalWrite(32, LOW);
      digitalWrite(36, LOW);
      digitalWrite(30, LOW);
      digitalWrite(34, LOW);
      digitalWrite(26, LOW);
      digitalWrite(24, LOW);
            
      delay(200);

      digitalWrite(32, HIGH);
      digitalWrite(36, HIGH);
      
      delay(500);

      digitalWrite(28, HIGH);
      digitalWrite(32, HIGH);
      digitalWrite(36, HIGH);
      digitalWrite(30, HIGH);
      digitalWrite(34, HIGH);
      digitalWrite(26, HIGH);
      digitalWrite(24, LOW);

      delay(500);
      
      sevseg.blank();
      sevseg.refreshDisplay();
      
      x = 1;
      song_number = -1;      
      }
      break;      
  }

  sevseg.refreshDisplay();
  
  while (audio.isPlaying() == 1){
    delay(20);
  }

//  **Debugging**
//  Serial.print("freshButtonpress After = ");
//  Serial.println(freshButtonpress);

  if (freshButtonpress == 1 && audio.isPlaying() == 0) freshButtonpress == 0;
  delay(50);

//  **Debugging**
//  Serial.print("freshButtonpress End = ");
//  Serial.println(freshButtonpress);

}
