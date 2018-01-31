#!/usr/bin/env python

import rospy
from firebird.msg import Lcd
from firebird.msg import Sensor
from std_msgs.msg import *
import time

class firebird():

	def __init__(self):

		self.buzzer_pub = rospy.Publisher('/firebird/buzzer', Bool, queue_size = 10)
		self.motor_pub = rospy.Publisher('/firebird/motor/config', Byte, queue_size = 10)
		self.pwm_l_pub = rospy.Publisher('/firebird/motor/pwm_l', Byte, queue_size = 10)
		self.pwm_r_pub = rospy.Publisher('/firebird/motor/pwm_r', Byte, queue_size = 10)
		self.linear_pub = rospy.Publisher('/firebird/motor/linear', UInt32, queue_size = 10)
		self.angle_pub = rospy.Publisher('/firebird/motor/angle', UInt32, queue_size = 10)
		self.bargraph_led_pub = rospy.Publisher('/firebird/bargraph_led', UInt8, queue_size = 10)
		self.lcd_print_pub = rospy.Publisher('/firebird/lcd/print', Lcd, queue_size = 10)
		self.lcd_clear_pub = rospy.Publisher('/firebird/lcd/clear', Empty, queue_size = 10)

		rospy.Subscriber('/firebird/sensors', Sensor, self.callback)
		
		rospy.init_node('firebird_control_test')

		self.lcd_msg = Lcd()

		self.lcd_msg.row = 1
		self.lcd_msg.col = 1
		self.lcd_msg.val = ""

		self.motor_pub.publish(0)

	def pwm(self,l,r):
		self.pwm_l_pub.publish(l)
		time.sleep(.2)
		self.pwm_r_pub.publish(r)

	def motor_config(self, val):
		self.motor_pub.publish(val)

	def forward(self):
		self.motor_pub.publish(1)

	def left(self):
		self.motor_pub.publish(2)

	def right(self):
		self.motor_pub.publish(3)

	def back(self):
		self.motor_pub.publish(4)

	def sft_left(self):
		self.motor_pub.publish(5)

	def sft_right(self):
		self.motor_pub.publish(6)

	def sft_left_back(self):
		self.motor_pub.publish(7)

	def sft_right_back(self):
		self.motor_pub.publish(8)

	def stop(self):
		self.motor_pub.publish(0)

	def linear(self, dist):
		self.linear_pub.publish(dist)

	def angle(self, angle):
		self.angle_pub.publish(angle)

	def buzzer_on(self):
		self.buzzer_pub.publish(1)

	def buzzer_off(self):
		self.buzzer_pub.publish(0)

	def bargraph_led(self, val):
		self.bargraph_led_pub.publish(val)

	def lcd_print(self, row, col, val):
		self.lcd_msg.row = row
		self.lcd_msg.col = col
		self.lcd_msg.val = val
		self.lcd_print_pub.publish(self.lcd_msg)

	def lcd_clear(self):
		self.lcd_clear_pub.publish()

	def callback(self, msg):
		print msg


	def testRobo(self):

		self.buzzer_on()
		time.sleep(0.5)
		self.buzzer_off()
		time.sleep(1)

		i = 0

		while i < 256:
			self.bargraph_led(i)
			i += 1
			time.sleep(0.2)

		self.bargraph_led(0)
		time.sleep(1)

		self.lcd_print(2,2,"Hello")
		time.sleep(2)
		self.lcd_clear()
		time.sleep(1)

		self.pwm(120,120)
		time.sleep(1)

		i = 0

		while i < 9:
			self.motor_config(i)
			time.sleep(2)
			i += 1

		self.motor_config(0)

		time.sleep(2)

		self.motor_config(1)
		time.sleep(0.1)
		self.linear(50)
		time.sleep(2)

		self.motor_config(1)
		time.sleep(0.1)
		self.angle(90)
		time.sleep(2)

		self.pwm(0,0)

		self.lcd_print(1,1,"Done")



if __name__ == '__main__':

	test = firebird()

	rate = rospy.Rate(800)
	
	while not rospy.is_shutdown():
	
		#TODO here
		test.testRobo()

		rate.sleep()
		
		rospy.spin()