/*****************************************************
This program was produced by the
CodeWizardAVR V2.05.0 Professional
Automatic Program Generator
© Copyright 1998-2010 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : 
Version : 
Date    : 10/24/2011
Author  : 
Company : 
Comments: 


Chip type               : ATmega32
Program type            : Application
AVR Core Clock frequency: 8.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 512
*****************************************************/
#include <mega32.h>
// Alphanumeric LCD Module functions
#include <alcd.h>
#include <delay.h>
#include <stdlib.h>
#include <string.h>
#define c1 DDRB.2
#define c2 DDRB.1
#define c3 DDRB.0
#define r1 PINB.3
#define r2 PINB.4
#define r3 PINB.5
#define r4 PINB.6
// Declare your global variables here
char ar[2][12];
char cable[8]={'a'};  
int cablenum=0;
char * cablechar;  
int ci=0; 
char kind[8];

 //cable type
 
 int isstraight()
 {char c='a';
 for(ci=0;ci<8;ci++)
{
if(kind[ci]=='s')
  c='s';
  else
  {c='a';
  return 0; }
        }
        if(c=='s')
        { 
        
        lcd_puts("it is straight");
        PORTA.1=1; 
        PORTB.7=1; 
        delay_ms(200);
        lcd_clear();
        return 1;
          }
        else
          {
           return 0;
          }
         
 }
 int isrollover()
 { char c='a';
  for(ci=0;ci<8;ci++) //for the nuber display
{
if(kind[ci]=='r')
  c='r';
  else
  {c='a';
  return 0; }
}
        if(c=='r')
        {  
        
        lcd_puts("it is Rollover");
        PORTA.1=1;
       
PORTB.7=1; 
        delay_ms(200);
        lcd_clear();
        return 1;
          }
        else
          {
           return 0;
          }
 } 
 int iscross()
 {char c='a'; 
 int i=0;
  for(ci=0;ci<8;ci++) //  ?
{
if(kind[0]=='c')
{
  c='c';
}
 else
  {c='a';break;}
if(kind[2]=='c')
{
c='c';
}
 else
 {c='a';break;}
if(kind[1]=='c')
{
c='c';
}
 else
  {c='a';break;}
if(kind[5]=='c')
{
c='c';
}
 else
  {c='a';break;} 
  }
 if(c=='c')
  {     
      lcd_puts("it is Cross");
     
     return 1;
        PORTA.1=1;
PORTB.7=1;
 delay_ms(200);
        lcd_clear();
          }
        else
          {   lcd_puts("cable is damaged"); 
          for(i=0;i<4;i++) {
PORTA.3=1;
PORTB.7=1;
delay_ms(60);
PORTA.3=0;
PORTB.7=0;
delay_ms(40);} 
          
          lcd_clear();
           return 0;
          }
      
       
        
  
  
 
 } 
void updatecable()
{
   cable[0]=PIND.0;
   cable[1]=PIND.1;
   cable[2]=PIND.2;
   cable[3]=PIND.3;
   cable[4]=PIND.4;
   cable[5]=PIND.5;
   cable[6]=PIND.6;
   cable[7]=PIND.7;
   
} 
int findzero()
{
int i=0;
for(i=0;i<8;i++)
{
if(cable[i]==0)
return i;
}
return -2;
}
void Update()
{
ar[0][0]=PINC.0;
ar[0][1]=PINC.1;
ar[0][2]=PINC.2;
ar[0][3]=PINC.3;
ar[0][4]=PINC.4;
ar[0][5]=PINC.5;
ar[0][6]=PINC.6;
ar[0][7]=PINC.7;
ar[0][9]=PINB.7 ;//doesnot matter


ar[1][0]=PIND.0;
ar[1][1]=PIND.1;                         
ar[1][2]=PIND.2;
ar[1][3]=PIND.3;
ar[1][4]=PIND.4;

}
void setvalue(int pnum, int val) 
{

if(pnum==0) {   PORTC.0=val;  DDRC.0=1 ; }
if(pnum==1){     PORTC.1=val;  DDRC.1=1 ;}
if(pnum==2){     PORTC.2=val;   DDRC.2=1 ;}
if(pnum==3){     PORTC.3=val;   DDRC.3=1  ;}
if(pnum==4){     PORTC.4=val;  DDRC.4=1   ;}
if(pnum==5){     PORTC.5=val;  DDRC.5=1   ;}
if(pnum==6){     PORTC.6=val;   DDRC.6=1  ; }
if(pnum==7){    PORTC.7=val;    DDRC.7=1  ; }
if(pnum==8){     PORTD.0=val;  DDRD.0=1   ;}
if(pnum==9){     PORTD.1=val;  DDRD.1=1   ;}
if(pnum==10){     PORTD.2=val;   DDRD.2=1  ; }
if(pnum==11){    PORTD.3=val;    DDRD.3=1   ;}

}
//the delay()
void  dely_loop()
 {  
    while(1)
  {       
  
    PORTB.7=1;
    if(!(!r1||!r2||!r3||!r4)) break;
 
   } 
     PORTB.7=0;
 }   
           // THE ORDER IS IMPORTANT
int NAND(char a,char b,char c)
{
if(a==0&&b==1&&c==1) return 1 ;

if(a==1&&b==0&&c==1) return 1 ;

if(a==0&&b==0&&c==1) return 1;

if(a==1&&b==1&&c==0) return 1;

return 0;
//statments goes here

}
int AND(char a,char b,char c)
{
if(a==0&&b==1&&c==0) return 1 ;

if(a==1&&b==0&&c==0) return 1 ;

if(a==0&&b==0&&c==0) return 1;

if(a==1&&b==1&&c==1) return 1;

return 0;
//statments goes here

}
int OR(char a,char b,char c)
{
if(a==0&&b==1&&c==1) return 1 ;

if(a==1&&b==0&&c==1) return 1 ;

if(a==0&&b==0&&c==0) return 1;

if(a==1&&b==1&&c==1) return 1;

return 0;
}
int NOR(char a,char b,char c)
{
if(a==0&&b==1&&c==0) return 1 ;

if(a==1&&b==0&&c==0) return 1 ;

if(a==0&&b==0&&c==1) return 1;

if(a==1&&b==1&&c==0) return 1;

return 0;
}
int XOR(char a,char b,char c)
{
if(a==0&&b==1&&c==1) return 1 ;

if(a==1&&b==0&&c==1) return 1 ;

if(a==0&&b==0&&c==0) return 1;

if(a==1&&b==1&&c==0) return 1;

return 0;

}
int invert(char a,char b,char c)
{
c=0;
if(a==0&&b==1) return 1 ;
if(a==1&&b==0) return 1 ;
return 0;
}
int AND3(char a,char b,char c,char d)
{
if(a==1&&b==1&&c==1&&d==1) return 1 ;
if(a==1&&b==1&&c==0&&d==0) return 1 ;
if(a==1&&b==0&&c==1&&d==0) return 1 ;
if(a==1&&b==0&&c==0&&d==0) return 1 ;
if(a==0&&b==1&&c==1&&d==0) return 1 ;
if(a==0&&b==1&&c==0&&d==0) return 1 ;
if(a==0&&b==0&&c==1&&d==0) return 1 ;
if(a==0&&b==0&&0==0&&d==0) return 1 ;


return 0;
//statments goes here

}
int NAND3(char a,char b,char c,char d)
{
if(a==1&&b==1&&c==1&&d==0) return 1 ;
if(a==1&&b==1&&c==0&&d==1) return 1 ;
if(a==1&&b==0&&c==1&&d==1) return 1 ;
if(a==1&&b==0&&c==0&&d==1) return 1 ;
if(a==0&&b==1&&c==1&&d==1) return 1 ;
if(a==0&&b==1&&c==0&&d==1) return 1 ;
if(a==0&&b==0&&c==1&&d==1) return 1 ;
if(a==0&&b==0&&0==0&&d==1) return 1 ;


return 0;
//statments goes here

}
int NOR3(char a,char b,char c,char d)
{
if(a==1&&b==1&&c==1&&d==0) return 1 ;
if(a==1&&b==1&&c==0&&d==0) return 1 ;
if(a==1&&b==0&&c==1&&d==0) return 1 ;
if(a==1&&b==0&&c==0&&d==0) return 1 ;
if(a==0&&b==1&&c==1&&d==0) return 1 ;
if(a==0&&b==1&&c==0&&d==0) return 1 ;
if(a==0&&b==0&&c==1&&d==0) return 1 ;
if(a==0&&b==0&&0==0&&d==1) return 1 ;


return 0;
//statments goes here

} 


int flipfloptable(char clr,char j,char k,char clk,char q1,char q2,char q10,char q20)
{
if(clr==0&&q1==0&&q2==1) return 1;
if(clr==1&&clk==0&&j==1&&k==0&&q1==1&&q2==0) return 1;
if(clr==1&&clk==0&&j==0&&k==1&&q1==0&&q2==1) return 1;
if(clr==1&&clk==0&&j==0&&k==0&&q1==q10&&q2==q20) return 1;
if(clr==1&&clk==0&&j==1&&k==1&&q1==1-q10&&q2==1-q20) return 1;
return 0;
}
int flipflop(int klr,int jj,int kk,int klk,int qq1,int qq2)
{                     //the i index is the first and (without i) is the second
 int clr=0;
 int j=0;
 int k=0;int clk=0;int q1=0;int q2=0;
 int iclr=0;int ij=0;int ik=0;int iclk=0;int iq1=0;int iq2=0;
int res=0;

  /////////////////////////////////////////////////////////////////////////
if(klr<=7)
{
iclr=0;
clr=klr;
}
else
{
iclr=1;
clr=klr-8;/////////////////////////
}
if(jj<=7)
{
ij=0;
j=jj;
}
else
{
ij=1;
j=jj-8; /////////////////////////////////////
}
if(kk<=7)
{
ik=0;
k=kk;
}
else
{
ik=1;
k=kk-8; //////////////////////////////////////
}

if(klk<=7)
{
iclk=0;
clk=klk;
}
else
{
iclk=1;
clk=klk-8;//////////////////////////////////
}

if(qq1<=7)
{
iq1=0;
q1=qq1;
}
else
{
iq1=1;
q1=qq1-8;/////////////////////////////////////
}


if(qq2<=7)
{
iq2=0;
q2=qq2;
}
else
{
iq2=1;
q2=qq1-8; ////////////////////////////////////
}

setvalue(clr,0);
Update();
res=flipfloptable(ar[iclr][clr],ar[ij][j],ar[ik][k],ar[iclk][clk],ar[iq1][q1],ar[iq2][q2],0,0);
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(j,1);
setvalue(k,0);
setvalue(clk,1);
setvalue(clk,0);
Update();
res=flipfloptable(ar[iclr][clr],ar[ij][j],ar[ik][k],ar[iclk][clk],ar[iq1][q1],ar[iq2][q2],0,0);
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(j,0);
setvalue(k,1);
setvalue(clk,1);
setvalue(clk,0);
Update();
res=flipfloptable(ar[iclr][clr],ar[ij][j],ar[ik][k],ar[iclk][clk],ar[iq1][q1],ar[iq2][q2],0,0);
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(j,0);
setvalue(k,0);
setvalue(clk,1);
setvalue(clk,0);
Update();
res=flipfloptable(ar[iclr][clr],ar[ij][j],ar[ik][k],ar[iclk][clk],ar[iq1][q1],ar[iq2][q2],0,1); // the same
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(j,1);
setvalue(k,1);
setvalue(clk,1);
setvalue(clk,0);
Update();
res=flipfloptable(ar[iclr][clr],ar[ij][j],ar[ik][k],ar[iclk][clk],ar[iq1][q1],ar[iq2][q2],0,1); //toggle
return res ;

}
/*
int D_flipfloptable(char pre,char clr,char clk,char d,char q1,char q2,char q10,char q20)
{

if(clr==1&&clk==1&&pre==1&&d==0&&q1==0&&q2==1) return 1;

if(clr==1&&clk==1&&pre==1&&d==1&&q1==1&&q2==0) return 1;


if(clr==1&&clk==0&&pre==1&&d==0&&q1==q10&&q2==q20) return 1;
return 0;
} 
*/
/*
int D_flipflop(int bre,int klr,int klk,int dd,int qq1,int qq2)
{   
 int clr=0; 
 int pre=0;
 int d=0;
int clk=0;int q1=0;int q2=0;
int ipre=0;
 int iclr=0;int id=0;int iclk=0;int iq1=0;int iq2=0;
int res=0;

  /////////////////////////////////////////////////////////////////////////
if(klr<=7)
{
iclr=0;
clr=klr;
}
else
{
iclr=1;
clr=klr-8;/////////////////////////
}
if(dd<=7)
{
id=0;
d=dd;
}
else
{
id=1;
d=dd-8; /////////////////////////////////////
}

if(bre<=7)
{
ipre=0;
pre=bre;
}
else
{
ipre=1;
pre=bre-8; /////////////////////////////////////
}

if(klk<=7)
{
iclk=0;
clk=klk;
}
else
{
iclk=1;
clk=klk-8;//////////////////////////////////
}

if(qq1<=7)
{
iq1=0;
q1=qq1;
}
else
{
iq1=1;
q1=qq1-8;/////////////////////////////////////
}


if(qq2<=7)
{
iq2=0;
q2=qq2;
}
else
{
iq2=1;
q2=qq1-8; ////////////////////////////////////
}

setvalue(clr,1);
setvalue(d,1);
setvalue(bre,1);
setvalue(clk,0);
setvalue(clk,1);
Update();
res=flipfloptable(ar[ipre][pre],ar[iclr][clr],ar[iclk][clk],ar[id][d],ar[iq1][q1],ar[iq2][q2],0,0);// the lasr 2 parameter will not matter in thes case
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(d,0);
setvalue(bre,1);
setvalue(clk,0);
setvalue(clk,1);;
Update();
res=flipfloptable(ar[ipre][pre],ar[iclr][clr],ar[iclk][clk],ar[id][d],ar[iq1][q1],ar[iq2][q2],0,0);
if(res!=1) return 0; 
///////////////////////////////////////// 
setvalue(clr,1);
setvalue(d,0);
setvalue(bre,1);
setvalue(clk,0);
setvalue(clk,1);;
Update();
res=flipfloptable(ar[ipre][pre],ar[iclr][clr],ar[iclk][clk],ar[id][d],ar[iq1][q1],ar[iq2][q2],0,1);
return res ;


}
 */

//scan key pad


char ScanKeyPad()
{     
char a='a';
PORTB.7=0;
 c1=1;c2=0;c3=0;
 delay_us(10);
 if(!r1){a= '1'; dely_loop();}
 if(!r2) { a=  '4';    dely_loop();}
 if(!r3)  {a=  '7';   dely_loop();}
 if(!r4)  {a=  '*';  dely_loop();}
 c1=0;c2=1;c3=0;
 delay_us(10);
 if(!r1) { a=  '2';  dely_loop();}
 if(!r2)  {a=  '5';  dely_loop();}
 if(!r3)  {a=  '8'; dely_loop();}
 if(!r4)  {a=  '0'; dely_loop();}
 c1=0;c2=0;c3=1;
 delay_us(10);
 if(!r1)  {a=  '3';  dely_loop();}
 if(!r2)  {a=  '6';   dely_loop();}
 if(!r3)  {a=  '9';   dely_loop();}
 if(!r4)  {a= '#';   dely_loop();}
          return a;     
  }
typedef int (*GateType) (char x,char y,char z);//pointer to a function that return int
typedef int (*GateType3in) (char x,char y,char z,char zz);
int CheckTheGate(char a,char b,char c,char whatgate)  // in in out 
{ 
 int r=0; 
int i1a=0;
int i1b=0;
int i1c=0; 
 int i2a=0;
 int i2b=0;
 int i2c=0;  
              // the programmer should know the exact sequence sequnce 
GateType types[] = 
{
NAND,
AND, 
OR,
NOR,
XOR,
invert
};
  /////////////////////////////////////////////////////////////////////////
if(a<=7)
{
i1a=0;
i2a=a;
}
else
{
i1a=1;
i2a=a-8;
}
if(b<=7)
{
i1b=0;
i2b=b;                                                                 
}
else
{
i1b=1;
i2b=b-8;
}
if(c<=7)
{
i1c=0;
i2c=c;
}
else
{
i1c=1;
i2c=c-8;
}

  /////////////////////////////////////////////////////////////////////////
setvalue(a,1); 
setvalue(b,1); //11 
delay_ms(20);
Update();
delay_ms(20);
r=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c]);

if(r!=1) return 0;        

/////////////////////////////////////////////////
setvalue(a,0); // 
setvalue(b,1); 
delay_ms(20); //10
Update();
delay_ms(20);
r=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c]);
if(r!=1) return 0;
/////////////////////////////////////////// 
setvalue(a,1); 
setvalue(b,0);
delay_ms(20);  // 10
Update();
delay_ms(20);
r=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c]);
if(r!=1) return 0;
///////////////////////////////////////// 
setvalue(a,0); // set the value of the truth table  00 01 10 11
setvalue(b,0);  // 00
Update();
r=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c]);
if(r!=1) return 0;
return 1;
}
int Check3InGate(char a,char b,char c,char d,char whatgate)  // in in in out 
{ 
 int rr=0; 
int i1a=0;
int i1b=0;
int i1c=0; 
 int i2a=0;
 int i2b=0;
 int i2c=0;
 int i1d=0; 
  int i2d=0;  
              // the programmer should know the exact sequence sequnce 
GateType3in types[] = 
{
NAND3,
AND3, 
NOR3,
};
  /////////////////////////////////////////////////////////////////////////
if(a<=7)
{
i1a=0;
i2a=a;
}
else
{
i1a=1;
i2a=a-8;
}
if(b<=7)
{
i1b=0;
i2b=b;                                                                 
}
else
{
i1b=1;
i2b=b-8;
}
if(c<=7)
{
i1c=0;
i2c=c;
}
else
{
i1c=1;
i2c=c-8;
}
if(d<=7)
{
i1d=0;
i2d=d;
}
else
{
i1d=1;
i2d=a-8;
}
  /////////////////////////////////////////////////////////////////////////
setvalue(a,1); 
setvalue(b,1);
setvalue(c,1); //11 
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;          

/////////////////////////////////////////////////
setvalue(a,1); // 
setvalue(b,1);
setvalue(c,0);  //10
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;
///////////////////////////////////////// 
setvalue(a,1); // set the value of the truth table  00 01 10 11
setvalue(b,0);
setvalue(c,1); 
 // 00
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;
 
/////////////////////////////////////////// 
setvalue(a,1); 
setvalue(b,0);
setvalue(c,0);  // 10
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;
 
setvalue(a,0); 
setvalue(b,1);
setvalue(c,1); 
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;
 
setvalue(a,0); 
setvalue(b,0);
setvalue(c,1); 
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0; 

setvalue(a,0); 
setvalue(b,1);
setvalue(c,0); 
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;
 
setvalue(a,0); 
setvalue(b,0);
setvalue(c,0); 
Update();
rr=types[whatgate](ar[i1a][i2a],ar[i1b][i2b],ar[i1c][i2c],ar[i1d][i2d]);
if(rr!=1) return 0;

return 1;
}
void main(void)
{
// Declare your local variables here
//initilizatio of the variable
     char option='#';    
       char n='a'; //for the input digit
       char a[7]; 
       int i=0; int ii=0; //for the keypad and geting the nameof ic 
       int res=0; 
      int final_res=1;
          // it is true but we will prove it is damaged  
// Input/Output Ports initialization
// Port A initialization
// Func7=Out Func6=Out Func5=Out Func4=Out Func3=Out Func2=Out Func1=Out Func0=Out 
// State7=0 State6=0 State5=0 State4=0 State3=0 State2=0 State1=0 State0=0 
PORTA=0x00;
DDRA=0xFF;

// Port B initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 
PORTB=0x78;   // the input pins 3 4 5 6  are pulldown 
DDRB=0x80;
PORTB.7=0;

// Port C initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 


PORTC=0x00;
DDRC=0x00;

// Port D initialization
// Func7=In Func6=In Func5=In Func4=In Func3=In Func2=In Func1=In Func0=In 
// State7=T State6=T State5=T State4=T State3=T State2=T State1=T State0=T 


PORTD=0x00;
DDRD=0x00;

// Timer/Counter 0 initialization
// Clock source: System Clock
// Clock value: Timer 0 Stopped
// Mode: Normal top=0xFF
// OC0 output: Disconnected
TCCR0=0x00;
TCNT0=0x00;
OCR0=0x00;

// Timer/Counter 1 initialization
// Clock source: System Clock
// Clock value: Timer1 Stopped
// Mode: Normal top=0xFFFF
// OC1A output: Discon.
// OC1B output: Discon.
// Noise Canceler: Off
// Input Capture on Falling Edge
// Timer1 Overflow Interrupt: Off
// Input Capture Interrupt: Off
// Compare A Match Interrupt: Off
// Compare B Match Interrupt: Off
TCCR1A=0x00;
TCCR1B=0x00;
TCNT1H=0x00;
TCNT1L=0x00;
ICR1H=0x00;
ICR1L=0x00;
OCR1AH=0x00;
OCR1AL=0x00;
OCR1BH=0x00;
OCR1BL=0x00;

// Timer/Counter 2 initialization
// Clock source: System Clock
// Clock value: Timer2 Stopped
// Mode: Normal top=0xFF
// OC2 output: Disconnected
ASSR=0x00;
TCCR2=0x00;
TCNT2=0x00;
OCR2=0x00;

// External Interrupt(s) initialization
// INT0: Off
// INT1: Off
// INT2: Off
MCUCR=0x00;
MCUCSR=0x00;

// Timer(s)/Counter(s) Interrupt(s) initialization
TIMSK=0x00;

// USART initialization
// USART disabled
UCSRB=0x00;

// Analog Comparator initialization
// Analog Comparator: Off
// Analog Comparator Input Capture by Timer/Counter 1: Off
ACSR=0x80;
SFIOR=0x00;

// ADC initialization
// ADC disabled
ADCSRA=0x00;

// SPI initialization
// SPI disabled
SPCR=0x00;

// TWI initialization
// TWI disabled
TWCR=0x00;

/////////////////////////////////////////////

//asking for the ic name
 do 
      {
      lcd_clear();
       delay_ms(100);
lcd_init(40);
lcd_puts("Choose Test..");
delay_ms(200);
lcd_clear();
lcd_puts("1 For IC test\n");
lcd_puts("2 For Cable test");
//////////////////////////////////////////////
while(1)
{
  n=ScanKeyPad();
if(n=='1')
{
PORTC=0xff;
DDRC=0x00;
 PORTD=0xff;
DDRD=0x00;
final_res=1;
res=0;
lcd_clear();
lcd_puts("Enter IC Name");
delay_ms(200);
lcd_clear();      
lcd_puts("# To Confirm\n");
lcd_puts("* To Delete");
while (n!='#')
{    
n=ScanKeyPad();
PORTB=0x78;    //re initilize for keypad
DDRB=0x80;
if(n!='a')
{
lcd_clear();
if(n!='*') 
{
a[i]=n ;
lcd_clear();   
for(ii=0;ii<=i;ii++)  
{
lcd_putchar(a[ii]);
}
i++;}
else       // if last character is desired  to be deleted 
{
i--;
lcd_clear();   
for(ii=0;ii<i;ii++) //for the nuber display
{
lcd_putchar(a[ii]);
}

}
 
}
  
}
lcd_init(40);
lcd_clear();   
lcd_puts("Checking ");
for(ii=0;ii<i-1;ii++) //for the nuber display
{
lcd_putchar(a[ii]);
}
delay_ms(180);
a[i-1]='\0';  
if(!strcmp(a,"4011")) ///////////////////////////
{
 
//MEAN U SHOULD CHECK THE GATE 'NAND'
res=CheckTheGate(7,6,11,0); // these are the pin numeber in the portc(0 1.. . . 7) and portd (8 9 10 11 )
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("NAND is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(3,2,1,0);
if (res!=1){ final_res=0;
lcd_clear(); 
lcd_puts("NAND G2 is Damaged");
delay_ms(200);
lcd_clear(); }
res=CheckTheGate(5,4,0,0);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("NAND G3 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(8,9,10,0);
if (res!=1){ final_res=0;
lcd_clear(); 
lcd_puts("NAND G4 is Damaged");
delay_ms(200);
lcd_clear();}

}
else if(!strcmp(a,"4050"))  // 4 nand  nut in differrnt connection
{

} 
else if(!strcmp(a,"4001"))  //4 nor  //3 types in the order   ///////////////////////////////////////////////////////
{ 
res=CheckTheGate(3,2,1,3);
if (res!=1){final_res=0;
lcd_clear(); 
lcd_puts("Nor G1 is Damaged");
delay_ms(200);
lcd_clear();}  // these are the pin numeber in the portc(0 1.. . . 7) and portd (8 9 10 11 )
res=CheckTheGate(5,4,0,3);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("Nor G2 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(8,9,10,3);
if (res!=1){final_res=0;
lcd_clear(); 
lcd_puts("Nor G3 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(7,6,11,3);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("Nor G4 is Damaged");
delay_ms(200);
lcd_clear();}
   
}                      
else if(!strcmp(a,"7404"))  //inverts    
{

}
else if(!strcmp(a,"4081"))   //4 and    ///////////////////
{  
res=CheckTheGate(3,2,1,1);  // these are the pin numeber in the portc(0 1.. . . 7) and portd (8 9 10 11 )
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("AND G1 is Damaged");
delay_ms(200);
lcd_clear();}

res=CheckTheGate(5,4,0,1);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("AND G2 is Damaged");
delay_ms(200);
lcd_clear();}

res=CheckTheGate(8,9,10,1);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("AND G3 is Damaged");
delay_ms(200);
lcd_clear();} 

res=CheckTheGate(7,6,11,1);
if (res!=1){final_res=0;
lcd_clear(); 
lcd_puts("AND G4 is Damaged");
delay_ms(200);
lcd_clear();} 
  }
else if(!strcmp(a,"7432"))   //4 or 
{  
res=CheckTheGate(3,2,1,2);  // these are the pin numeber in the portc(0 1.. . . 7) and portd (8 9 10 11 )
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("OR G1 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(0,4,5,2);
if (res!=1){final_res=0;
lcd_clear(); 
lcd_puts("OR G2 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(8,9,10,2);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("OR G3 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(11,6,7,2);
if (res!=1) {final_res=0;
lcd_clear(); 
lcd_puts("OR G4 is Damaged");
delay_ms(200);
lcd_clear();}
 
}
else if(!strcmp(a,"4030"))   //4 xor   ///////////////////////////////////
{  
res=CheckTheGate(3,2,1,4);  // these are the pin numeber in the portc(0 1.. . . 7) and portd (8 9 10 11 )
if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("XOR G1 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(5,4,0,4);
if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("XOR G2 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(8,9,10,4);
if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("XOR G3 is Damaged");
delay_ms(200);
lcd_clear();}
res=CheckTheGate(7,6,11,4);
if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("XOR G4 is Damaged");
delay_ms(200);
lcd_clear();}
 
}
else if(!strcmp(a,"74107"))    //jk flipflop
{
   res= flipflop(2,2,1,3,5,4); 
    if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("Unit1 is Damaged");
delay_ms(200);
lcd_clear();}
    res=  flipflop(0,2,1,3,5,4);  
    if (res!=1)  {final_res=0;
lcd_clear(); 
lcd_puts("Unit2 is Damaged");
delay_ms(200);
lcd_clear();}
 
}
else if(!strcmp(a,"7474"))     //D flipflop
{   Check3InGate(0,0,0,0,0);
}
else if(!strcmp(a,"7410"))    //3in nand
{
}
else if(!strcmp(a,"7411"))     //3in and
{
}
else if(!strcmp(a,"7427"))     //3in nor
{
}
else
{
  lcd_puts("The IC Is Not \nIn The Database");
  delay_ms(170);
      lcd_clear();
      break;
}
if(final_res==1)
{
lcd_clear();
lcd_puts("IC Is Good");
PORTA.1=1;
PORTB.7=1;
delay_ms(200);
lcd_clear();
}
else
{
lcd_clear();
lcd_puts("IC Is Damaged");
for(i=0;i<4;i++) {
PORTA.3=1;
PORTB.7=1;
delay_ms(60);
PORTA.3=0;
PORTB.7=0;
delay_ms(40);}
}
break;
} //the try again and quit procedure
if(n=='2')   //for cable
{
lcd_clear();
PORTC=0x00;
DDRC=0xFF;
PORTD=0xff;// pull up 
DDRD=0x00;
 if(PIND==0xFF)
 {
    lcd_puts("Insert The Cable ");    //there is a cable inserted
    delay_ms(200);
    lcd_clear(); 
    
    break;
 } 
 PORTC=0xFF;
DDRC=0xFF;

for(ci=0;ci<=7;ci++)
{
PORTC=1<<ci;
PORTC=~PORTC;
delay_ms(50);
cablenum=ci+1;
itoa(cablenum,cablechar) ;
lcd_init(40);
lcd_puts("   C");
lcd_putchar(*cablechar);
updatecable();
cablenum=findzero();
itoa(cablenum+1,cablechar) ;
lcd_puts("   C");
lcd_putchar(*cablechar);
delay_ms(200);
lcd_clear(); 
if(ci==cablenum)
kind[ci]='s';
if(ci==7-cablenum)
kind[ci]='r';
if(ci==0&&cablenum==2)
{
kind[1-1]='c';
}
if(ci==2&&cablenum==0)
{
kind[3-1]='c';
}
if(ci==1&&cablenum==5)
{
kind[2-1]='c';
}
if(ci==5&&cablenum==1)
{
kind[6-1]='c';
}
}

if(isstraight()==1)break;
if(isrollover()==1)break;
iscross();
       break;
}
else
{
  if(n=='a')
   {  }
  else{ 
  lcd_clear();
      lcd_init(40); 
      lcd_puts("Wrong Entry");
       delay_ms(200);
      lcd_clear(); 
      lcd_puts("1 For IC test\n");
     lcd_puts("2 For Cable test");
      }
      }       
}
  // Place your code here we place all the entering the ic name and the testing 
      PORTA.1=0;
      PORTA.3=0;
      lcd_clear();
      lcd_init(40);    
      lcd_puts("* To Quit\n"); 
      lcd_puts("# To Try again"); 
          while(1)
         { 
         n=ScanKeyPad(); 
         if(n=='#')  
         {   option='#' ;
               break;
         }
         if(n=='*')
         {option='*';
         break;
         } 
         }   
        n='a';
        a[0]='\0';  a[1]='\0';  a[2]='\0';  a[3]='\0';  a[4]='\0'; 
        i=0;  ii=0;  
        res=0;   
        PORTC=0x00;
        DDRC=0x00;
        
        PORTD=0x00;
        DDRD=0x00;
       final_res=1; 
      }   
     while (option !='*');
        lcd_clear(); 
      lcd_init(40);
      lcd_puts("    BYE BYE"); 
       delay_ms(200);
      lcd_clear();
       
}
