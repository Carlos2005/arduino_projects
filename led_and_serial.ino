// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
int flag=0, led = 13, inByte;


// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
  Serial.begin(9600);  //set the serial port
}

// the loop routine runs over and over again forever:
void loop() {
  
{
  if (!flag){
     digitalWrite(led, LOW);   // turn the LED off only once (HIGH is the voltage level)
     flag++; }
  
  if (Serial.available()) {
    inByte = Serial.read();
    if ( inByte == 1) digitalWrite(led, HIGH)
    else if  inByte == 0) digitalWrite(led, LOW)

  }
  
}
