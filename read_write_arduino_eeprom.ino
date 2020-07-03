/*

File name: read_write_arduino_eeprom.ino

This sketch that allows a user to access data in EEPROM using the serial monitor.
In the serial monitor the user should be able to type one of two commands:
“read” and “write. "Read" takes one argument, an EEPROM address. 
"Write" takes two arguments, an EEPROM address and a value.

For example, if the user types “read 3” then the contents of EEPROM
address 3 should be printed to the serial monitor.
If the user types “write 3 10” then the value 10 should be written into 
address 3 of the EEPROM

(c) 2015 Carlos de la Calleja

*/

#include <EEPROM.h>

//Variables declaration
int readAddress, writeAddress, writeValue, value, index1;
int errorFlag = 0;
String inputCommand, inputRead, inputWrite, writeInput, writeAddressS, writeValueS;

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  
    for (int i = 0; i < 1024; i++) // fill all memmory with ff
    EEPROM.write(i, 255);
}

void loop() {
  
  while(Serial.available()) {

	inputCommand = Serial.readString();// read the incoming data as string
	Serial.println(inputCommand);   
    
    //starts parsing the input command
   
    if (inputCommand.startsWith("READ")|| inputCommand.startsWith("read")){          
        
      inputRead = inputCommand.substring(5); // extract the read address
       
      readAddress = inputRead.toInt(); //integer conversion
      
      if(readAddress == 0){   //check if it´s incorrect
        if (inputRead!="0")
          errorFlag = 1;
      }
      
         //check if addres is out of range
      if (!errorFlag && readAddress > -1 && readAddress < 1024 ){
      
         value = EEPROM.read(readAddress); //read the byte stored at readAddress
         Serial.println(value);
 
      }
      else {
            Serial.println("- Input error");
            errorFlag = 0;
      }
       
    }
    else if (inputCommand.startsWith("WRITE")|| inputCommand.startsWith("write"))
	{
               
      inputWrite = inputCommand.substring(6);          
      index1 = inputWrite.indexOf(' ');   //finds location of separator      
      
      writeAddressS = inputWrite.substring(0,index1); //extract address
      writeValueS = inputWrite.substring(index1+1);   //extract value
      
      writeAddress = writeAddressS.toInt(); //conversion to integer
      if(writeAddress == 0){
        if (writeAddressS!="0")
          errorFlag = 1;
      }
      writeValue = writeValueS.toInt();  //conversion to integer
      if(writeValue == 0){
        if (writeValueS!="0")
          errorFlag = 1;
      }
      
        // check if address of value are out of range
    if (!errorFlag && writeAddress > -1 && writeAddress <1024 && writeValue > -1 && writeValue <256 ){
      
         EEPROM.write(writeAddress,writeValue); //write the writeValue byte pointed by writeAddress
         Serial.println("- Success!"); 
      }
      else {
            Serial.println("- Input error");   //displays error message
            errorFlag = 0;
      }
                    
     }
     
    else Serial.println("- Input error");  // displays error message
   }
}
