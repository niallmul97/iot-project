#include <math.h>

int redPin = 6;
int greenPin = 3;
 
//uncomment this line if using a Common Anode LED
//#define COMMON_ANODE
 
void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
 
void loop()
{  
  setColor(0, 0, 255);  // green
  delay(500);
  setColor(20, 0, 100);  // lime
  delay(500);
    setColor(50, 0, 50);  // yellow
  delay(500);
      setColor(120, 0, 100);  // orange
  delay(500);
    setColor(255, 0, 0);  // red
  delay(500);
}
 
void setColor(int red, int green, int blue)
{
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
}
