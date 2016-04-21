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
#include "AnalogButtons.h"

// All hardware pin usage is defined here:
#define OLED_DC 5
#define OLED_CS SS
#define OLED_RESET 9

#define LEDPIN 13
#define JOY_PIN A0

//Create display object
U8GLIB_SSD1306_128X64 u8g(OLED_CS, OLED_DC, OLED_RESET);

//Create joytick objects (5 buttons)
AnalogButtons analogButtons(JOY_PIN, INPUT,0);
Button btnUp = Button(382, &bUClick);
Button btnDown = Button(10, &bDClick);
Button btnLeft = Button(290, &bLClick);
Button btnRight = Button(170, &bRClick);
Button btnCenter = Button(454, &bCClick, &bCHold, 2000);

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
  
}
void bCHold(){
  
}
void drawBox(){
  u8g.drawBox(boxX, boxY, boxXSize, boxYSize);
}

void setup() {
   Serial.begin(115200);
   pinMode(LEDPIN, OUTPUT);
   analogButtons.add(btnUp);
   analogButtons.add(btnDown);
   analogButtons.add(btnLeft);
   analogButtons.add(btnRight);
   analogButtons.add(btnCenter); 
}

void loop() {
  analogButtons.check(); //Check for buttons presses
  u8g.firstPage();  
  do {
    drawBox();
  } while( u8g.nextPage() );

}
