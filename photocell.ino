/*
Arduino connected to a photoresistor and a piezo buzzer. 

Circuit that causes a piezo buzzer to sound when it is sufficiently dark in a room.

(c) 2015 Carlos de la Calleja

Circuit:
  - 10K Ohm resistor
  - 10K Ohm resitor
  - Photo resistor
  - Piezo buzzer

int buzzerPin = 8;   // selet the input pin for the buzzer
int photocellPin = A0;    // analog input pin for the photoresistor
int photocellValue = 0;  //  value coming from the photocell

void setup() {

  Serial.begin(9600);  // use the serial input to debug the program
}

void loop() {
  // read the value from the photocell:
  photocellValue = analogRead(photocellPin); // read the value

  Serial.println(sphotocellValue); // uart transmits the values to the serial monitor
  
  if (photoCellrValue < 300) tone(buzzerPin,1000); //if there is no light then generate tone
  else noTone(buzzerPin); // stop buzzer
  
}
