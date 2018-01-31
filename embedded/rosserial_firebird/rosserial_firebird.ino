
#include <ros.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Byte.h>
#include <std_msgs/UInt8.h>
#include <std_msgs/UInt32.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <firebird/Sensor.h>
#include <firebird/Lcd.h>

#include <avr/io.h>
#include <util/delay.h>
#include "LCD.c"
#include "firebird.c"

unsigned long int ShaftCountLeft = 0; 
unsigned long int ShaftCountRight = 0; 
unsigned int Degrees;

void left_encoder_pin_config (void)
{
 DDRE  = DDRE & 0xEF;
 PORTE = PORTE | 0x10;
}

void right_encoder_pin_config (void)
{
 DDRE  = DDRE & 0xDF;
 PORTE = PORTE | 0x20;
}

void left_position_encoder_interrupt_init (void)
{ 
 EICRB = EICRB | 0x02; 
 EIMSK = EIMSK | 0x10;
}

void right_position_encoder_interrupt_init (void)
{
 EICRB = EICRB | 0x08; 
 EIMSK = EIMSK | 0x20;
}


ISR(INT5_vect)  
{
 ShaftCountRight++;
}


ISR(INT4_vect)
{
 ShaftCountLeft++; 
}

void angle_rotate(unsigned int Degrees)
{
 float ReqdShaftCount = 0;
 unsigned long int ReqdShaftCountInt = 0;

 ReqdShaftCount = (float) Degrees/ 4.090; // division by resolution to get shaft count
 ReqdShaftCountInt = (unsigned int) ReqdShaftCount;
 ShaftCountRight = 0; 
 ShaftCountLeft = 0; 

 while (1)
 {
  _delay_ms(1);
  if((ShaftCountRight >= ReqdShaftCountInt) | (ShaftCountLeft >= ReqdShaftCountInt)){
    break;
  }
 }
 _stop();
}

void linear_distance_mm(unsigned int DistanceInMM)
{
  float ReqdShaftCount = 0;
  unsigned long int ReqdShaftCountInt = 0;

 ReqdShaftCount = DistanceInMM / 5.338; // division by resolution to get shaft count
 ReqdShaftCountInt = (unsigned long int) ReqdShaftCount;
 ShaftCountRight = 0;
 while(1)
 {
  _delay_ms(1);
  if(ShaftCountRight > ReqdShaftCountInt)
  {
    break;
  }
 } 
 _stop();
}

void motor(const std_msgs::Byte& motor_msg){
   if(motor_msg.data == 1){
    //Forward
    forward();
   }else if(motor_msg.data == 2){
    //Left
    left();
   }else if(motor_msg.data == 3){
    //Right
    right();
   }else if(motor_msg.data == 4){
    //Reverse
    back();
   }else if(motor_msg.data == 5){
    //Soft Left
    soft_left();
   }else if(motor_msg.data == 6){
    //Soft Right
    soft_right();
   }else if(motor_msg.data == 7){
    //Soft Left back
    soft_left_2();
   }else if(motor_msg.data == 8){
    //Soft Right back
    soft_right_2();
   }else if(motor_msg.data == 0){
    //Stop
    _stop();
   }
}

void buzzer(const std_msgs::Bool& buzzer_msg){
  digitalWrite(34,buzzer_msg.data);
}

void pwm_l(const std_msgs::UInt8& pwm_l_msg){
  analogWrite(46,pwm_l_msg.data);
}

void pwm_r(const std_msgs::UInt8& pwm_r_msg){
  analogWrite(45,pwm_r_msg.data);
}

void bargraph_led(const std_msgs::UInt8& bargraph_msg){
  PORTJ = bargraph_msg.data;
}

void lcd(const firebird::Lcd& lcd_msg){
  lcd_cursor(lcd_msg.row,lcd_msg.col);
  lcd_string(lcd_msg.val);
}

void lcd_clear(const std_msgs::Empty& lcd_clear_msg){
  lcd_wr_command(0x01);
}

void linear(const std_msgs::UInt32& linear_msg){
  linear_distance_mm(linear_msg.data);
}

void angle(const std_msgs::UInt32& angle_msg){
  angle_rotate(angle_msg.data);
}

firebird::Sensor sensor_msg;

ros::NodeHandle nh;

ros::Publisher sense("/firebird/sensors", &sensor_msg);

ros::Subscriber<std_msgs::Bool> buzzer_sub("/firebird/buzzer", &buzzer);
ros::Subscriber<std_msgs::Byte> motor_sub("/firebird/motor/config", &motor);
ros::Subscriber<std_msgs::UInt8> pwm_l_sub("/firebird/motor/pwm_l", &pwm_l);
ros::Subscriber<std_msgs::UInt8> pwm_r_sub("/firebird/motor/pwm_r", &pwm_r);
ros::Subscriber<std_msgs::UInt32> linear_sub("/firebird/motor/linear", &linear);
ros::Subscriber<std_msgs::UInt32> angle_sub("/firebird/motor/angle", &angle);
ros::Subscriber<std_msgs::UInt8> bargraph_led_sub("/firebird/bargraph_led", &bargraph_led);
ros::Subscriber<firebird::Lcd> lcd_sub("/firebird/lcd/print", &lcd);
ros::Subscriber<std_msgs::Empty> lcd_clear_sub("/firebird/lcd/clear", &lcd_clear);

void setup()
{
  //Functions init
  cli();
  LED_bargraph_config();
  adc_pin_config();
  adc_init();
  lcd_port_config();
  lcd_set_4bit();
  lcd_init();
  left_position_encoder_interrupt_init();
  right_position_encoder_interrupt_init();
  motor_config();
  sei(); 

  //Node init
  nh.initNode();

  //Subscribers init
  nh.subscribe(buzzer_sub);
  nh.subscribe(motor_sub);
  nh.subscribe(pwm_l_sub);
  nh.subscribe(pwm_r_sub);
  nh.subscribe(bargraph_led_sub);
  nh.subscribe(lcd_sub);
  nh.subscribe(lcd_clear_sub);
  nh.subscribe(linear_sub);
  nh.subscribe(angle_sub);

  //Publishers init
  nh.advertise(sense);
  
}
 
void loop()
{
  sensor_msg.battery.bat_volt = ADC_Conversion(0);
  sensor_msg.wls.wls1 = ADC_Conversion(3);
  sensor_msg.wls.wls2 = ADC_Conversion(2);
  sensor_msg.wls.wls3 = ADC_Conversion(1);
  sensor_msg.ir.ir1 = ADC_Conversion(4);
  sensor_msg.ir.ir2 = ADC_Conversion(5);
  sensor_msg.ir.ir3 = ADC_Conversion(6);
  sensor_msg.ir.ir4 = ADC_Conversion(7);
  sensor_msg.ir.ir5 = ADC_Conversion(8);
  sensor_msg.sharp.sharp1 = ADC_Conversion(9);
  sensor_msg.sharp.sharp2 = ADC_Conversion(10);
  sensor_msg.sharp.sharp3 = ADC_Conversion(11);
  sensor_msg.sharp.sharp4 = ADC_Conversion(12);
  sensor_msg.sharp.sharp5 = ADC_Conversion(13);
  sensor_msg.aux.aux1 = ADC_Conversion(14);
  sensor_msg.aux.aux2 = ADC_Conversion(15);
  
  sense.publish(&sensor_msg);
  
  nh.spinOnce();
  _delay_ms(10);
}