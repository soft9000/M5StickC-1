/*** BlinkyTexty
   File:     BlinkyTexty.ino
   Board:    M5StickC
   Platform: Arduino 1.8.15
   Author:   Randall Nagy

Demonstrations:
   Blinking the 'stick's internal LED
   Writing larger strings
   Managing text colors
   Homing the cursor
   Clearing the screen  
*/

#include <M5StickC.h>

const int ledPin = 10;

int colors[5];
int color = 0;

void setup() {
  // setup pin 5 as a digital output pin
  pinMode (ledPin, OUTPUT);
  colors[0] = WHITE;
  colors[1] = RED;
  colors[2] = GREEN;
  colors[3] = BLUE;
  colors[4] = BLACK;
  M5.begin();
  M5.Lcd.setTextSize(2);
}

bool bFirst = true;
int times = 0;
char *buff = new char(100);
void loop() {
  if (bFirst || times % 10 == 0) {
    (color == 4) ? color = 0 : color++;
    M5.Lcd.fillScreen(colors[color]);
    M5.Lcd.setCursor(0, 0); // In_eSPI.h
    int fg;
    (colors[color] == WHITE) ? fg = BLUE : fg = WHITE;
    M5.Lcd.setTextColor(fg,colors[color]);
    bFirst = false;
  }
  sprintf(buff, "%d.%d\n", color, times);
  M5.Lcd.print(buff);
  (times == 9999) ? times = 0, bFirst = true : times++;
  digitalWrite (ledPin, HIGH);  // turn on the LED
  delay(1000); // wait for a second or 1000 milliseconds
  digitalWrite (ledPin, LOW); // turn off the LED
  delay(500); // wait for half a second or 500 milliseconds
  m5.update();
}
