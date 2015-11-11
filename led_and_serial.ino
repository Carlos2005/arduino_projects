// (c) 2015, Carlos de la Calleja

// led set to Pin 13 inbuild led, flag and byte received 
int flag = 0, led = 13, ByteReceived;

// the setup routine runs once when you press reset:
void setup() {  							
  pinMode(led, OUTPUT);  // initialize the digital pin as an output.
  Serial.begin(9600);  //set the serial port
}

// the loop routine runs over and over again forever:
void loop() {
  if (!flag){
     digitalWrite(led, HIGH);   // turn off the LED only once 
     flag++; }
  
  while (Serial.available() > 0) {   //check if data is incoming from the  serial monitor
     ByteReceived = Serial.read(); // read the byte
     if (ByteReceived == '1') digitalWrite(led, HIGH);
     if (ByteReceived == '0') digitalWrite(led, LOW);
  }  
}
