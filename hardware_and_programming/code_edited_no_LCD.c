#include<reg51.h> 
#include<string.h>
#include<stdio.h>
#include<stdlib.h>


sbit sda=P2^1;
sbit scl=P2^0;
sbit SENSOR=P3^2;
sbit RESET=P2^2;
int ack;
unsigned char reead,write,write2,i,j;
unsigned int temp;
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

void getPulse() 
{
 	Pulse++;
	delay(10);
	if(Pulse>=10)
	{
		Pulse=0;
		Unit++;
	}
}

//---------------8051 Configuraton and Setup----------------------

void init()
{
	TMOD=0x20;
   	SCON=0x50;
   	TH1=0xfd;
   	TR1=1;
}

void aknowledge() //acknowledge condition
{
	scl=1;
	scl=0;
} 
void start() //start condition
{
	sda=1;
	scl=1;
	sda=0;
	scl=0;
}
void stop() //stop condition
{
	sda=0;
	scl=1;
	sda=1;
	scl=0;
}

void EEPROMSave(char *s) //save in EEPROM
{
	start();
	send_byte(0xA0); //device address
	send_byte(0x00); //word address
	for(i=0;s[i]!='\0';i++)
	 {
	   send_byte(s[i]); //send data
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
	send_byte(0xA1); //device address
    	for(i=0;i<100;i++)
	{
		c=read_byte();
	   	EEPROMData[i]=c;
	}
	EEPROMData[i]=0;
	stop();
}

//-------------------SERIAL COMM------------------------

void send_byte(unsigned char value) //send byte serially
{ 
	unsigned int i;
	unsigned char send;
	send=value;
	for(i=0;i<8;i++)
	{
		sda=send/128;	//extracting MSB
		send=send<<1;	//shiftng left
		scl=1;
		scl=0;
	}
}

unsigned char read_byte() //reading from EEPROM serially
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

//------------------ESP8266----------------------------- 
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
void main() 
{
 	char buffer[6];
	init();

    	if(RESET==0)
	{
	   EEPROMSave("0");
	   delay(100);
	}

	ESP8266_Init();
	delay(100);
   	EEPROMRead(buffer);
	Unit=atoi(buffer);
   
	while(1)	
	{
	   	if(SENSOR==0) getPulse();   
  		 
		if(Pulse!=LastPulse)
		{
			LastPulse=Pulse;
		}
		if(Unit!=LastUnit)
		{
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
	  




