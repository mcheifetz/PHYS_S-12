#include <Adafruit_NeoPixel.h>

#define PIN        6 
#define NUMPIXELS 10 
#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels

Adafruit_NeoPixel strip(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

//Constants for the note frequencies
const int c = 262;
const int cS = 277;
const int d = 294;
const int dS = 311;
const int e = 329;
const int f = 349;
const int fS = 370;
const int g = 392;
const int gS = 415;
const int a = 440;
const int aS = 466;
const int b = 493;
const int cH = 523;
const int cSH = 554;
const int dH = 587;
const int dSH = 622;
const int eH = 659;
const int fH = 698;
const int fSH = 740;
const int gH = 784;
const int gSH = 831;
const int aH = 880;
const int aSH = 932;
const int bH = 988;
const int cHH = 1047;

//Initializing note lengths for the different notes in the songs
//Allows me to change the length of all notes of the same type (ie. all quarter notes) without having to change each individual one
int halfNoteDuration;
int quarterNoteDuration;
int dottedEigthNoteDuration;
int eigthNoteDuration;
int sixteenthNoteDuration;
int thirtySecondNoteDuration;

int buzzerPin = 10;

void setup() {  
  //Setup pin mode
  pinMode(buzzerPin, OUTPUT);

  strip.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(10); // Set BRIGHTNESS low to reduce draw (max = 255)
}

void loop() {
  strip.clear(); // Set all pixel colors to 'off'
  
  playHappyBirthday(buzzerPin, 125 );
  delay(4000);

  //playRondoAllaTurca(buzzerPin, 160);
  //delay(4000);
}

//Function to play Happy Birthday
void playHappyBirthday(int buzzerPin, int bpm){
  //60,000 because there's 60,000 ms in a minute
  quarterNoteDuration = (int) ((float) 60000 / bpm); //At 120 BPM a quarter note will have a duration of 500 ms
  halfNoteDuration = quarterNoteDuration * 2;                     
  dottedEigthNoteDuration = (int) (quarterNoteDuration * 0.75);       
  sixteenthNoteDuration = (int) ((float) quarterNoteDuration / 4);

  tone(buzzerPin, c, dottedEigthNoteDuration);
  displayRandomLED(dottedEigthNoteDuration);

  tone(buzzerPin, c, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, d, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, c, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, f, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, e, halfNoteDuration);
  displayRandomLED(halfNoteDuration);

  tone(buzzerPin, c, dottedEigthNoteDuration);
  displayRandomLED(dottedEigthNoteDuration);

  tone(buzzerPin, c, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, d, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, c, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, g, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, f, halfNoteDuration);
  displayRandomLED(halfNoteDuration);

  tone(buzzerPin, c, dottedEigthNoteDuration);
  displayRandomLED(dottedEigthNoteDuration);

  tone(buzzerPin, c, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cH, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, a, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, f, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, e, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, d, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, aS, dottedEigthNoteDuration);
  displayRandomLED(dottedEigthNoteDuration);

  tone(buzzerPin, aS, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, a, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, f, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, g, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, f, halfNoteDuration);
  displayRandomLED(halfNoteDuration);
}

//Function to play Rondo Alla Turca
void playRondoAllaTurca(int buzzerPin, int bpm){
  rondoSectionOne(buzzerPin, bpm);
  rondoSectionOne(buzzerPin, bpm);

  rondoSectionTwo(buzzerPin, bpm);
}


//First Section of Rondo Alla Turca
void rondoSectionOne(int buzzerPin, int bpm){
  quarterNoteDuration = (int) ((float) 60000 / bpm);
  halfNoteDuration = quarterNoteDuration * 2;                     
  eigthNoteDuration = (int) (quarterNoteDuration / 2);         
  sixteenthNoteDuration = (int) ((float) quarterNoteDuration / 4);
  thirtySecondNoteDuration = (int) ((float) sixteenthNoteDuration / 2);

  tone(buzzerPin, b, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, a, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gS, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, a, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cH, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration * 2);

  tone(buzzerPin, dH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, b, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration * 2);

  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, dSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, bH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, bH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cHH, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, cHH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  //Grace notes start
  tone(buzzerPin, gH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);

  tone(buzzerPin, aH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);
  //Grace notes end
  
  tone(buzzerPin, bH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  //Grace notes start
  tone(buzzerPin, gH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);

  tone(buzzerPin, aH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);
  //Grace notes end

  tone(buzzerPin, bH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  //Grace notes start
  tone(buzzerPin, gH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);

  tone(buzzerPin, aH, thirtySecondNoteDuration / 2);
  displayRandomLED(thirtySecondNoteDuration / 2);
  //Grace notes end

  tone(buzzerPin, bH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fSH, eigthNoteDuration - 25);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, quarterNoteDuration - 50);
  displayRandomLED(quarterNoteDuration);
}

//Second Section of Rondo Alla Turca
void rondoSectionTwo(int buzzerPin, int bpm){
  quarterNoteDuration = (int) ((float) 60000 / bpm);
  halfNoteDuration = quarterNoteDuration * 2;                     
  eigthNoteDuration = (int) (quarterNoteDuration / 2);         
  sixteenthNoteDuration = (int) ((float) quarterNoteDuration / 4);
  thirtySecondNoteDuration = (int) ((float) sixteenthNoteDuration / 2);
  
  tone(buzzerPin, eH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, gH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, dH, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, g, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, gH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, dH, quarterNoteDuration - 50);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, cH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, dH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, dH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, b, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, e, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, cH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, dH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, dH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, b, quarterNoteDuration - 50);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, b, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, a, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gS, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, a, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cH, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration * 2);

  tone(buzzerPin, dH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, b, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, cH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration);
  displayRandomLED(eigthNoteDuration * 2);

  tone(buzzerPin, fH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, dSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, eH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, bH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, bH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, gSH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);
   
  tone(buzzerPin, aH, sixteenthNoteDuration);
  displayRandomLED(sixteenthNoteDuration);

  tone(buzzerPin, cHH, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, bH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, cHH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, bH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, gSH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, aH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, eH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, fH, eigthNoteDuration - 50);
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, dH, eigthNoteDuration - 50 );
  displayRandomLED(eigthNoteDuration);

  tone(buzzerPin, cH, quarterNoteDuration - 50);
  displayRandomLED(quarterNoteDuration);

  tone(buzzerPin, b, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, cH, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, b, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, cH, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, b, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, cH, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, a, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, b, thirtySecondNoteDuration);
  displayRandomLED(thirtySecondNoteDuration);

  tone(buzzerPin, a, quarterNoteDuration);
  displayRandomLED(quarterNoteDuration);
}

//Function to display a random color on the LED strip
void displayRandomLED(int delayLength){
  strip.clear(); // Set all pixel colors to 'off'

  //Array of the RGB values for each color of the rainbow
  int rainbowColors[7][3] = {{255, 0, 0}, {255, 127, 0}, {255, 255, 0}, {0, 255, 0}, {0, 0, 255}, {75, 0, 130}, {148, 0, 211}};

  //Chooses a random number 0-6 (index of each color of the rainbow)
  int rainbowCol = rand() % 7;
  int ledSpot = rand() % 10;
  strip.setPixelColor(ledSpot, rainbowColors[rainbowCol][0], rainbowColors[rainbowCol][1], rainbowColors[rainbowCol][2]);  
  strip.show();
  delay(delayLength);
}
  
