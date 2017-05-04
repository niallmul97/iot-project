int sensorPin = A0;
int sensorValue = 0;
int tempGreen = 670;
int tempYellow = 680;
int tempRed = 690;

  void setup(){
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
}


void loop() {
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  delay(sensorValue);
  led(sensorValue);
}

void led(int sensorValue){
  if(sensorValue >= tempGreen){
     digitalWrite(13, HIGH);
     digitalWrite(12, LOW);
     digitalWrite(11, LOW);
  }
  else{
    digitalWrite(13, LOW);    
  }
  if(sensorValue >= tempYellow){
     digitalWrite(13, LOW);
     digitalWrite(12, HIGH);
     digitalWrite(11, LOW);
  }
  else{
    digitalWrite(12, LOW);    
  }
  if(sensorValue >= tempRed){
     digitalWrite(13, LOW);
     digitalWrite(12, LOW);
     digitalWrite(11, HIGH);
  }
  else{
    digitalWrite(11, LOW);    
  }
}
