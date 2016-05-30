/*------------------------------------------------------------------------------
* Author       William Garrido
* Created      04-2016
* Purpose      Demo sketch for SUPEROLED8
* Git:         https://github.com/FriedCircuits/SUPEROLED8             
* Purchase:    http://friedCircuits.us
* License:     CC-BY-SA
-------------------------------------------------------------------------------
* *History*
*
* 
*          
------------------------------------------------------------------------------*/

#include "U8glib.h"
//#include "AnalogButtons.h"

// All hardware pin usage is defined here:
#define OLED_DC 5
#define OLED_CS SS
#define OLED_RESET 9

#define LEDPIN 13
#define JOY_PIN A0

//Create display object
U8GLIB_SSD1306_128X64 u8g(OLED_CS, OLED_DC, OLED_RESET);

//Create joytick objects

uint16_t btnUp = 382;
uint16_t btnDown = 10;
uint16_t btnLeft = 290;
uint16_t btnRight = 170;
uint16_t btnCenter = 454;

uint8_t btnOffSet = 10;

//Box Size
uint8_t boxXSize = 10;
uint8_t boxYSize = 10;

//For holding box starting coord
uint8_t boxX = 64-boxXSize, boxY = 32-boxYSize;

//Callback functions for handling each button click
void bUClick(){
  boxY--;
}
void bDClick(){
  boxY++;
}
void bLClick(){
  boxX--;
}
void bRClick(){
  boxX++;
}
void bCClick(){
  boxX = 64-boxXSize;
  boxY = 32-boxYSize;
  digitalWrite(LEDPIN, HIGH);
  delay(200);
  digitalWrite(LEDPIN, LOW);
}
void bCHold(){
  
}
void drawBox(){
  u8g.drawBox(boxX, boxY, boxXSize, boxYSize);
}

void buttonCheck(){
  uint16_t btnADC = analogRead(JOY_PIN);
  if((btnADC >= btnUp-btnOffSet) && (btnADC <= btnUp+btnOffSet)) bUClick();
  if((btnADC >= btnDown-btnOffSet) && (btnADC <= btnDown+btnOffSet)) bDClick();
  if((btnADC >= btnLeft-btnOffSet) && (btnADC <= btnLeft+btnOffSet)) bLClick();
  if((btnADC >= btnRight-btnOffSet) && (btnADC <= btnRight+btnOffSet)) bRClick();
  if((btnADC >= btnCenter-btnOffSet) && (btnADC <= btnCenter+btnOffSet)) bCClick();
  
}

void setup() {
   Serial.begin(115200);
   pinMode(LEDPIN, OUTPUT);
}

void loop() {
  buttonCheck(); //Check for buttons presses
  u8g.firstPage();  
  do {
    drawBox();
  } while( u8g.nextPage() );

}
