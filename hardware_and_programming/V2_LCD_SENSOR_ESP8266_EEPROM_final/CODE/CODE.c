#include<reg51.h> // Include Header file to work With 8051 Family Microcontroller
#include<stdio.h> // Include stdio.h , as we are using sprintf() function
#define LCDPort P1  // LCD data/Command bus (PIBN 7 to PIN 14) is Connected to P1 (PIN 1 to PIN 8) of 8051
sbit  RS=P0^0; // RS pin of LCD (PIN 4) is Connected to P0.0 (PIN 39) of 8051
sbit  RW=P0^1; // RW pin of LCD (PIN 5) is Connected to P0.1 (PIN 38) of 8051
sbit  EN=P0^2; // EN pin of LCD (PIN 6) is Connected to P0.2 (PIN 37) of 8051
sbit SENSOR=P3^2; // The PULSE Sensor is Connected with P3.2 (PIN 12) of 8051



//------------------------------------------------------------------------------//
void delay(int t) // This function will generate approx t ms delay
{
    int i;
     
	while(t>0) // Loop until t become ZERO
	 { 
 	   i=1275; // Set the Starting Value of i with 1275
	   while(i>0) i--; // Decrease the Value of i by -1, unti i become ZERO
	   t--; // Decrease the Value of t by -1
	 }

}

void LCDCommand(char c) // This function will send a command to LCD
  {
    RS=0; // RS=0 means, we are sending Command to LCD
	RW=0; // RW=0 means, we are using the LCD in Write Mode
	LCDPort=c; //Copy the Value of c(Command) to LCDPort (P1 in Our Case)
	EN=1; // Set EN pin High ---------------+
	delay(2); // Wait for 2 ms				+--- Generate a High to  Low Pulse
	EN=0; // Reset the EN pin Back to LOW --+
  }
  
void LCDData(char c) // This function will send a Data to LCD
  {
    RS=1; // RS=1 means, we are sending Data to LCD
	RW=0; // RW=0 means, we are using the LCD in Write Mode
	LCDPort=c; //Copy the Value of c(Data) to LCDPort (P1 in Our Case)
	EN=1; // Set EN pin High ---------------+
	delay(2); // Wait for 2 ms				+--- Generate a High to  Low Pulse
	EN=0; // Reset the EN pin Back to LOW --+
  }
 // To use the LCD we must have to Initilized IT
void LCDInit() // This function will Initilized the LCD
 { 
     LCDCommand(0x38); // 0x38 - 8 Bit Mode
	 LCDCommand(0x06); // 0x06 - Display from Left To Right
	 LCDCommand(0x0c); // 0x0c - Display On, Cursor Hide
	 LCDCommand(0x01); // 0x01 - Clear LCD
 }	  
// String:  A string is Nothing but array of Characters , terminated by NULL ('\0')
//          array index start from ZERO (0)

void LCDPuts(char *s) // This function will Display a string on LCD
{
   int i; // Declare Local Variable i to use as index of the character of the Stringfor(i=0;
   for(i=0;s[i]!='\0';i++) // Scan each and every Character of the string one by one, untill it encounter NULL ('\0')
	 {
	    LCDData(s[i]); // and display the data on LCD with the Help of LCDData() function
	 }
}


void main() // the main() function start here
{
   
   int PULSE=0; // Declare Local Variable PULSE to store the PULOSE Count
   int UNIT=0;  // Declare Variable to Store UNIT
   char buffer[10]; // Declare an array of character to store converted data
   LCDInit(); // Initilizing the LCD
   
   LCDPuts("   IoT  Based   ");
   LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
   LCDPuts(" Energy Meter   ");
   

     delay(100); // Wait for 100 ms
	 LCDCommand(0x01); // Clear The LCD
	 LCDPuts("Developed By....");
	 delay(100); // Wait for 100 ms

 	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("Arindam Das     ");
  	 delay(100); // Wait for 100 ms

 	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("Rajarshi Nath   ");
  	 delay(100); // Wait for 100 ms


 	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("Bitopan Nath    ");
  	 delay(100); // Wait for 100 ms


  	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("Shadaab Ahmed   ");
  	 delay(100); // Wait for 100 ms

 	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("AEC-EE-2019     ");
  	 delay(100); // Wait for 100 ms

	 LCDCommand(0x01); // Clear The LCD
	
	 LCDPuts("UNIT :");
 	 LCDCommand(0xc0); // Move the Cursor to the Starting of Second Line
     LCDPuts("Pulse:");
	

      
   while(1)  // Starting of main indefinit loop
    {
	  
	    if(SENSOR==0) // if Sensor Output Goes LOW
		 {
            PULSE++; // Increase the PULSE by +1
			sprintf(buffer,"%4d",PULSE); // Convert the Numeric PULSE Value into String, and store it in buffer
			LCDCommand(0xc6); // Move the Cursor to the 6th position of 2nd Line
			LCDPuts(buffer); // and display the data stored in buffer(PULSE)
			while(SENSOR==0); // Wait unitl the sensor OUTPUT goes LOW
			if(PULSE>=10) // if PULSE become 10 (in case of actual implementation it will be 800/1600/3200 depending on meter)
			 {
                 UNIT++; // Increase the value of UNIT by +1
                 PULSE=0; // Reset the Value of PULSE to 0

			   sprintf(buffer,"%4d",UNIT); // Convert the Numeric UNIT Value into String, and store it in buffer
			   LCDCommand(0x86); // Move the Cursor to the 6th position of 1st Line
			   LCDPuts(buffer); // and display the data stored in buffer(UNIT)

			   
			   sprintf(buffer,"%4d",PULSE); // Convert the Numeric PULSE Value into String, and store it in buffer
			   LCDCommand(0xc6); // Move the Cursor to the 6th position of 2nd Line
			   LCDPuts(buffer); // and display the data stored in buffer(PULSE)

			  
			 }
		 }



	}
    

}