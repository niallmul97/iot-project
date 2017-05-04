#include <math.h>

int redPin = 6;
int greenPin = 3;
int sensorPin = A0;
int sensorValue = 0;
double tempInCelcius = 0;
int red = 0;
int green = 0;
int blue = 0;
  
void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}
 
void loop()
{  
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(sensorValue);
  setColor(red, blue, green);
  colorChange(sensorValue);
  tempInCelcius = thermistor(sensorValue);
  sensor();
}

void sensor(){
  Serial.println(tempInCelcius);
  delay(sensorValue);
}

void colorChange(int sensorValue){
  if(tempInCelcius > 0 && tempInCelcius < 15){
     setColor(0, 0, 255);  // green
  }
  else if(tempInCelcius > 15 && tempInCelcius < 17){
     setColor(10, 0, 20);  // lime
  }
  else if(tempInCelcius > 17 && tempInCelcius < 19){
     setColor(20, 0, 200);  // yellow
  }
  else if(tempInCelcius > 19 && tempInCelcius < 21){
     setColor(120, 0, 100);  // orange
  }
  else if(tempInCelcius > 21){
     setColor(255, 0, 0);  // red
  }
}
 
void setColor(int red, int green, int blue)
{
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
}

double thermistor(int sensorValue){
  double temp;
  temp = log(10000.0*((1441.0/sensorValue-1)));
  temp = 1/(0.001129148 + (0.000234125 +(0.0000000876741 *temp *temp))*temp);
  temp = temp - 273.15;
  return temp;
}

