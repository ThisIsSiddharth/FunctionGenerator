#include<reg51.h>

#define display_port P2             // Data pins connected to port 2 on microcontroller
sbit rs = P3^3;                     // RS pin connected to pin 2 of port 3
sbit rw = P3^4;                     // RW pin connected to pin 3 of port 3
sbit e =  P3^5;                     // E pin connected to pin 4 of port 3
sbit C4 = P1^0;                     // Connecting keypad to Port 1
sbit C3 = P1^1;
sbit C2 = P1^2;
sbit C1 = P1^3;
sbit R4 = P1^4;
sbit R3 = P1^5;
sbit R2 = P1^6;
sbit R1 = P1^7;

sbit con = P3^7;

void Sin(unsigned int);
void Square(unsigned int);
void triangle(unsigned int);
void Sawtooth(unsigned int);
void Amplitude_Modulation(unsigned int);


unsigned int timed=0;

void msdelay(unsigned int time)      // Function for creating delay in milliseconds.
{
    unsigned int i,j ;
    for(i=0;i<time;i++);
    for(j=0;j<1275;j++);
}
void lcd_cmd(unsigned char command)  //Function to send command instruction to LCD
{
    display_port = command;
    rs= 0;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_data(unsigned char disp_data)  //Function to send display dat to LCD
{
    display_port = disp_data;
    rs= 1;
    rw=0;
    e=1;
    msdelay(1);
    e=0;
}

void lcd_init()    //Function to prepare the LCD  and get it ready
{
    lcd_cmd(0x38);  // for usin 2 lines and 5X7 matrix of LCD
    msdelay(10);
    lcd_cmd(0x0F);  // turn display ON, cursor blinking
    msdelay(10);
    lcd_cmd(0x01);  //clear screen
    msdelay(10);
    lcd_cmd(0x81);  // bring cursor to position 1 of line 1
    msdelay(10);
}
void row_finder1() //Function for finding the row for column 1
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{lcd_data('t');triangle(timed);}
	if(R2==0)
	{lcd_data('s');Sawtooth(timed);}
	if(R3==0)
	{lcd_data('s');Square(timed);}
	if(R4==0)
		{lcd_data('A');Amplitude_Modulation(timed); }
}

void row_finder2() //Function for finding the row for column 2
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
	if(R1==0)
	{lcd_data('S');Sin(timed);}
}
void row_finder3() //Function for finding the row for column 3
{
	R1=R2=R3=R4=1;
	C1=C2=C3=C4=0;
  lcd_data('f');
	if(R1==0)
		timed=0;
	if(R2==0)
		timed=1;
	if(R3==0)
		timed=2;
	if(R4==0)
		timed=3;
}

void row_finder4() //Function for finding the row for column 4
{
		R1=R2=R3=R4=1;
		C1=C2=C3=C4=0;
    lcd_data('f');
		if(R1==0)
			timed=4;
		if(R2==0)
			timed=5;
		if(R3==0)
			timed=5;
}
void Sin(unsigned int freq)                                                   
{ 
	 int sin1[] = {128,192,238,255,238,192,128,64,17,0,17,64};
	 int i;
	 R1=R2=R3=R4=0;
	 C1=C2=C3=C4=1;
	 while(1)
	 {
		 if(C4==0)
		 {
			 C4=0;R4=1;
			 if(R4==0) 
			 {
				 lcd_data('*');
				 lcd_cmd(0x01);  //clear screen
				 msdelay(10);
				 lcd_cmd(0x81);  // bring cursor to position 1 of line 1
				 msdelay(10);
				 break;
			 }
			 else {C4=1;R4=0;}
		 }
		 for(i=0;i<12;i++)
		 {
			 P0 = sin1[i];
			 msdelay(freq);
		 }
	 }
}
void Square(unsigned int freq)                                 
{
	int a = 0;
	int con=1;
	C4=1;R4=0;
	while(con==1)
	{
		 if(C4==0)
		 {
			 C4=0;R4=1;
			 if(R4==0) con=0;
					else {C4=1;R4=0;}
		 }
		P0 = 0;
		msdelay(freq);
		P0 = 255;
		msdelay(freq);
	}	
}
void triangle(unsigned int freq)                             
{
	int a = 0;
	int con=1;
		 C4=1;R4=0;
	while(con==1)
	{
		 if(C4==0)
		 {
			 C4=0;R4=1;
			 if(R4==0) con=0;
			 else {C4=1;R4=0;}
		 }
		while(a<=254)
		{
			P0 = a;
			msdelay(freq);
			a++;
		}
		while(a>=1)
		{
			P0 = a;
			msdelay(freq);
			a--;
		}
	}
}
void Sawtooth(unsigned int freq)                                
{
	int a = 0;
	int con=1;
		 C4=1;R4=0;
	while(con==1)
	{
		 if(C4==0)
		 {
			 C4=0;R4=1;
			 if(R4==0) con=0;
			 else {C4=1;R4=0;}
		 }
		while(a<=254)
		{
			P0= a;
			msdelay(freq);
			a=a+20;
		}
		a = 0;
		msdelay(freq);
	}
}
void Amplitude_Modulation(unsigned int freq)
{
	   int j;
	   int c[51]={255,230, 166,88, 26, 0, 27, 90, 165, 224, 245, 221, 163, 93, 40, 22, 44, 97, 158, 204, 219, 199, 154, 102, 64, 53, 69, 106, 148, 178, 186, 173, 143, 112, 90, 83, 91, 115, 139, 155, 160, 152, 136, 119, 106, 102, 108, 120, 135, 146, 150};
		 int con=1;
			 C4=1;R4=0;
		while(con==1)
	  {
		 if(C4==0)
		 {
			 C4=0;R4=1;
			 if(R4==0) {con=0;}
			 else {C4=1;R4=0;}
		 } 
		for(j=0;j<51;j++)
    {
    P0=c[j];
    }
		for(j=50;j>=0;j--)
		{
			P0=c[j];
		}
		msdelay(freq);
	}
}
void main()
{
	lcd_init();
	while(1)
	{
		con = 1;
		msdelay(30); 
    C1=C2=C3=C4=1;
    R1=R2=R3=R4=0;
    if(C3==0)
				row_finder3();
		else if(C4==0)
				row_finder4();
		if(C1==0)
				row_finder1();
    else if(C2==0)
        row_finder2();
	}
}