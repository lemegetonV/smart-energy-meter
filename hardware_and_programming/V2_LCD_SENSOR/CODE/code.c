#include<reg51.h> // Include Header file to ork with 8051 Family Microcontroller
#include<string.h>
#include <stdio.h>
#include<stdlib.h>
//---------------------------
sbit sda=P2^1;
sbit scl=P2^0;
int ack;
unsigned char reead,write,write2,i,j;
unsigned int temp;
//----------------------------------
void init(void);
void tx(char);
char rx(void);
void xputs(char *);
//----------------------------------
void aknowledge()	  //acknowledge condition
{
	scl=1;
	scl=0;
} 
void start()		//start condition
{
	sda=1;
	scl=1;
	sda=0;
	scl=0;
}
void stop()			//stop condition
{
	sda=0;
	scl=1;
	sda=1;
	scl=0;
}
void send_byte(unsigned char value)	//send byte serially
{ 
	unsigned int i;
	unsigned char send;
	send=value;
	for(i=0;i<8;i++)
	{
		sda=send/128;			//extracting MSB
		send=send<<1;			//shiftng left
		scl=1;
		scl=0;
	}
}
unsigned char read_byte()			//reading from EEPROM serially
{
	unsigned int i;
	sda=1;
	reead=0;
	for(i=0;i<8;i++)
	{
		reead=reead<<1;
		scl=1;
		if(sda==1)
			reead++;
		scl=0;
	}
	return reead;				//Returns 8 bit data here
}		
void EEPROMSave(char *s)					//save in EEPROM
{
	start();
	send_byte(0xA0);						//device address
	send_byte(0x00);						//word address
	for(i=0;s[i]!='\0';i++)
	 {
	   send_byte(s[i]);							//send data
	   aknowledge();
	 }

	stop();							   
}
void EEPROMRead(char *EEPROMData)
{
	int i;
	char c;
	start();
	send_byte(0xA0);
	send_byte(0x00);
	start();
	send_byte(0xA1);					 //device address
    for(i=0;i<100;i++)
	  {
	    c=read_byte();
	   	EEPROMData[i]=c;
	  }
	EEPROMData[i]=0;
	stop();
}


#define LCDPort P1   // LCD data/Command bus are connected to P1 of 8051
sbit    RS=P0^0;     // The RS pin of LCD (PIN 4) is Connected to P0.0 (PIN 39) of 8051
sbit    RW=P0^1;     // The RW pin of LCD (PIN 5) is Connected to P0.1 (PIN 38) of 8051
sbit    EN=P0^2;     // The EN pin of LCD (PIN 6) is Connected to P0.2 (PIN 37) of 8051
sbit SENSOR=P3^2;
sbit RESET=P2^2;


char strUnit[5];
int Pulse=0;
int Unit=0;
int LastPulse=0;
int LastUnit=0;
void delay(int t)    // This function will generate t ms Delay
 {
      int i;
	  while(t>0)
	   {
	      i=1275;
		  while(i>0) i--;
		  t--;
	   }

 }


void LCDCommand(char c) // This function will send a command to LCD
 {
	RS=0; // RS=0 means, we are sending Command to LCD
	RW=0; // RW=0 means, we are using the LCD in Write Mode
	LCDPort=c; // Copy the value of c(Command) into LCDPort (P1 in our Case)
	EN=1;      // Set EN pin High -----------------+
	delay(1);  // Wait for 2 ms					   +--- Generate a high to low Pulse
	EN=0;      // Reset the EN pin Back to Low ----+
	
 }

void LCDData(char c) // This function will send a Data to LCD
 {
	RS=1; // RS=1 means, we are sending Data to LCD
	RW=0; // RW=0 means, we are using the LCD in Write Mode
	LCDPort=c; // Copy the value of c(Data) into LCDPort (P1 in our Case)
	EN=1;      // Set EN pin High -----------------+
	delay(1);  // Wait for 2 ms					   +--- Generate a high to low Pulse
	EN=0;      // Reset the EN pin Back to Low ----+
 }

// To use the LCD we must have to Initilized it

void LCDInit() // This function will initilized the LCD
 {
     LCDCommand(0x38); // 0x38 - 8 bit Mode
	 LCDCommand(0x06); // 0x06 - Display from Left to Right
	 LCDCommand(0x0c); // 0x0c - Display On, Cursor Hide
	 LCDCommand(0x01); // 0x01 - Clear LCD
 }
/* String: String is nothing but array of characters, terminated by NULL('\0')
           Array index start from 0
*/
		             
void LCDPuts(char *s)  // This function will Display a string on LCD
 {
       int i;
	   for(i=0; s[i]!='\0';i++) LCDData(s[i]);

 }

 //-----------------------------------------------
 void init()
 {
   TMOD=0x20;
   SCON=0x50;
   TH1=0xfd;
   TR1=1;
 }
void tx(char c)
 {
   SBUF=c;
   while(TI==0);
   TI=0;
 }
void xputs(char *s)
 {
   int i;
   for(i=0;s[i]!='\0';i++)
    {
	  tx(s[i]);
	}

 }
 void ESP8266_Init()
 {
    xputs("AT");
	tx(10);
	tx(13);
	delay(100);


    xputs("AT+CWMODE=1");
	tx(10);
	tx(13);
	delay(100);


    xputs("AT+CIPMUX=1");
	tx(10);
	tx(13);
	delay(100);

 }
void startTCPConnection()
 {
   xputs("AT+CIPSTART=4,TCP,SERVER,80");
   tx(10);
   tx(13);
  
 }
void initTCP()
{ 
 
  xputs("AT+CIPSEND=4,200");
  tx(10);
  tx(13);
 }

void sendTCPData()
{
 
 
  xputs("/aeciotemeter.com/update.php?MID=M001&UNIT="); //  40   - 57
  xputs(strUnit);
  tx(10);	
  tx(13);	
  
}


//------------------------------------------------
void getPulse() 
 {
     Pulse++;
	 delay(10);
	 if(Pulse>=10)
	  {
	    LCDCommand(0x8A);
	    LCDData('0');
		Pulse=0;
		Unit++;
	  }
 } 
//------------------------------------------------
void main() // the main() function start here
 {
 	char buffer[6];
	init();
	LCDInit(); // Initilizing the LCD

    if(RESET==0)
	 {
	   EEPROMSave("0");
	   LCDPuts("RESET READING");
	   delay(100);

	 }

	LCDCommand(0x01);
    LCDPuts("IoT Based");
	LCDCommand(0xc0); // Starting of Second Line
	LCDPuts("Energy Meter");
	delay(100); // Wait for 100 ms
	LCDCommand(0x01); // Clear LCD
	LCDPuts("Group Members");
	delay(100); // Wait for 100ms
	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("Arindam Das     ")	;
	delay(100); // Wait for 100 ms

	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("Rajarshi Nath	 ")	;
	delay(100); // Wait for 100 ms

	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("Bitopan Nath    ");
	delay(100); // Wait for 100 ms

	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("Ripunjoy Kashyap");
	delay(100); // Wait for 100 ms

	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("Shadaab Ahmed   ");
	delay(100); // Wait for 100 ms


	
	LCDCommand(0xc0); // Move the Cursor to Starting of Second Line
	LCDPuts("AEC - EE- 2019  ");
	delay(100); // Wait for 100 ms 
  

  	LCDCommand(0x01);
	LCDPuts("Starting.......");
	ESP8266_Init();
	delay(100);

    LCDCommand(0x01);
	LCDPuts("Pulse:");
	LCDCommand(0xc0);
	LCDPuts("Unit :");

    LCDCommand(0x86);
    sprintf(buffer,"%5d",Pulse);
    LCDPuts(buffer);
   
   
   	EEPROMRead(buffer);
	Unit=atoi(buffer);
   
   
    LCDCommand(0xc6);
    sprintf(buffer,"%5d",Unit);
	LCDPuts(buffer);



	while(1)
	 {
	   
	     if(SENSOR==0) getPulse();   
  		 
		 if(Pulse!=LastPulse)
		  {
			 LCDCommand(0x86);
			 sprintf(buffer,"%5d",Pulse);
			 LCDPuts(buffer);
			 LastPulse=Pulse;
		  }
		 if(Unit!=LastUnit)
			  {
			    LCDCommand(0xc6);
			    sprintf(buffer,"%5d",Unit);
			    LCDPuts(buffer);
				startTCPConnection();
		        initTCP();
		        sendTCPData();
				LastUnit=Unit;

				//---------------------------
				EEPROMSave(strUnit);
		       //---------------------------

			  }
	 }

 }
	  




