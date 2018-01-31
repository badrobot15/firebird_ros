#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

void motor_config (void)
{
 DDRA = 0xFF;  //PORT J is configured as output
 PORTA = 0x00; //Output is set to 0
}

void LED_bargraph_config (void)
{
 DDRJ = 0xFF;  //PORT J is configured as output
 PORTJ = 0x00; //Output is set to 0
}

void adc_pin_config (void)
{
 DDRF = 0x00; 
 PORTF = 0x00;
 DDRK = 0x00;
 PORTK = 0x00;
}

void adc_init()
{
  ADCSRA = 0x00;
  ADCSRB = 0x00;
  ADMUX = 0x20;   //Vref=5V external --- ADLAR=1 --- MUX4:0 = 0000
  ACSR = 0x80;
  ADCSRA = 0x86;
}

unsigned char ADC_Conversion(unsigned char Ch) 
{
  unsigned char a;
  if(Ch>7)
  {
    ADCSRB = 0x08;
  }
  Ch = Ch & 0x07;       
  ADMUX= 0x20| Ch;        
  ADCSRA = ADCSRA | 0x40;
  while((ADCSRA&0x10)==0);
  a=ADCH;
  ADCSRA = ADCSRA|0x10;
  ADCSRB = 0x00;
  return a;
}

void motion_set (unsigned char Direction)
{
 unsigned char PortARestore = 0;

 Direction &= 0x0F;       // removing upper nibbel as it is not needed
 PortARestore = PORTA;      // reading the PORTA's original status
 PortARestore &= 0xF0;      // setting lower direction nibbel to 0
 PortARestore |= Direction;   // adding lower nibbel for direction command and restoring the PORTA status
 PORTA = PortARestore;      // setting the command to the port
}

void forward (void) //both wheels forward
{
  motion_set(0x06);
}

void back (void) //both wheels backward
{
  motion_set(0x09);
}

void left (void) //Left wheel backward, Right wheel forward
{
  motion_set(0x05);
}

void right (void) //Left wheel forward, Right wheel backward
{
  motion_set(0x0A);
}

void soft_left (void) //Left wheel stationary, Right wheel forward
{
  motion_set(0x04);
}

void soft_right (void) //Left wheel forward, Right wheel is stationary
{
  motion_set(0x02);
}

void soft_left_2 (void) //Left wheel backward, right wheel stationary
{
  motion_set(0x01);
}

void soft_right_2 (void) //Left wheel stationary, Right wheel backward
{
  motion_set(0x08);
}

void _stop (void)
{
  motion_set(0x00);
}
