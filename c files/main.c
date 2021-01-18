/*
 * Smart-Garage-System.c
 *
 * Created: 1/16/2021 1:01:10 AM
 * Author : Mostafa Elshiekh
 */ 

#include <avr/io.h>
#include <util/delay.h>
#include <lcd driver.c>
#include <GPIOs driver.c>
#define  F_CPU   4000000 UL

#define  A 0x39
#define  B 0x36
#define  C 0x33
#define  D 0x30
#define  output 1
#define input 0


int main(void)
{
	Port_Direction(B,output);                    //make port B as output (LCD)
	Pin_Direction(A,6,output);                  //A6 as output (RS-LCD)
	Pin_Direction(A,7,output);                 //A7 as output (E-LCD)
	Pin_Direction(C,0,output);                //C0 as output (servo motor exit )
	Pin_Direction(C,1,input);                     //C1 as output (PIR sensor exit)
	Pin_Direction(A,0,output);               //A6 as output (RS-LCD)
	Pin_Direction(D,6,input);                  // D6 as input (IRsensor entry)
	Pin_Direction(D,7,output);              //D7 as output (servo motor entrance)
	Pin_Direction(D,0,output);	          //D0 as output (car 2)
	Pin_Direction(D,5,output);             //D6 as input (car 3)
	Pin_Direction(C,3,output);             //D3 as output (car 1)
	char counter=0;
	
	
	
	lcd_init();                  //function which initialize LCD
    while (1) 
    {
					 if( (PIND&0b01000000)==0b01000000)   //entrance gate
					 {
								  if(counter<3)          // number of cars inside garage less than 3
										{
										    lcd_go_to(1,3);
										    lcd_go_to(1,3);
										     lcd_print("THERE IS A CAR");
											 lcd_go_to(3,1);	
										     lcd_print("AT THE ENTRANCE GATE");
											 lcd_go_to(4,3);
											 _delay_ms(1000);
											 //motor enter up +90 angle
										     PORTD|=(1<<7);
										    _delay_us(980);
								  		     PORTD&=~(1<<7);
											  _delay_ms(500);
										    //set the led by number car inter
										    if(counter==0)
								        		   PORTC|=(1<<3);      //set led 1 (car1)
										    if(counter==1)
										            PORTD|=(1<<0);     //set led 2 (car2)
										    if(counter==2)
										                PORTD|=(1<<5); //set led 3 (car3)

           
										  //motor entry down -90 angle
										   PORTD|=(1<<7);
										   _delay_us(1499);
										   PORTD&=~(1<<7);  

										    counter++; //increase number of cars inside the garage
											
										   lcd_command(0xC);
										   lcd_command(0x01);
										}
										if(counter==3 ) //garage is full (number of car = 3)
					                   {
						  
										  lcd_go_to(1,3);
										  lcd_go_to(1,3);
										  lcd_print("CARS IN GARAGE=");
										  lcd_go_to(1,18);
										  lcd_int(counter);
										  lcd_go_to(3,4);
										  lcd_print("GARAGE IS FULL");
						                  lcd_go_to(4,2);
										  lcd_print("TAKES ONLY 3 CARS");
										  lcd_command(0xC);
										  _delay_ms(1000);
										  lcd_command(0x01);
									  }	
					    
					 }
					
					 
					 else if( (PINC&0b00000010)==0b00000010  ) //exit gate
					 {

									 lcd_go_to(2,4);
									 lcd_go_to(2,4);
									 lcd_print("THERE IS A CAR");
									 lcd_go_to(3,2);
						             lcd_go_to(3,2);
									 lcd_print("AT THE EXIT GATE") ;
									 
									 //exit motor up +90
									 PORTC|=(1<<0);
									 _delay_us(2000);
									 PORTC&=~(1<<0);
									 _delay_ms(1000);
	                                
	                                //reset led
									if(counter==3) //if car at exit gate and count=3 reset led1 when car1 exit
									     PORTC&=~(1<<3);
									if(counter==2)
								         PORTD&=~(1<<0); //if car at exit gate and count=2 reset led2 when car2 exit
								    if(counter==1)
										 PORTD&=~(1<<5); //if car at exit gate and count=1 reset led3 when car3 exit
						            
						            //exit motor down -90 angle
						            PORTC|=(1<<0);
									 _delay_us(1499);
					           	     PORTC&=~(1<<0);

					           	     counter--;  //decrease the number of cars inside the garage Because one car exit
									 lcd_command(0xC);
									 _delay_ms(1500);
									 lcd_command(0x01);
					 }
					  	
				  	else         //in case there is no car at the entrance or exit gate
				  	{
				  		if(counter<=2)  //if number of care inside the garage less or equal 2
				    	{
								 lcd_go_to(1,3);
								 lcd_go_to(1,3);
								lcd_print("CARS IN GARAGE=");
								 lcd_go_to(1,18);
								lcd_int(counter);
								 lcd_go_to(3,3);
								 lcd_print("ENTRY IS ALLOWED");  
						}
						if(counter==3 ) //garage is full (number of car = 3)
						{
							
							lcd_go_to(1,3);
							lcd_go_to(1,3);
							lcd_print("CARS IN GARAGE=");
							lcd_go_to(1,18);
							lcd_int(counter);
							lcd_go_to(3,4);
							lcd_print("GARAGE IS FULL");
							lcd_go_to(4,2);
							lcd_print("TAKES ONLY 3 CARS");
						}
							lcd_command(0xC);
						   _delay_ms(1000	);
							lcd_command(0x01);
				}					 
	}
	return 0;
}

