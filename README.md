# ROS package for Firebird
ROS package for the Firebird robot by Nex robotics. The package uses xbee modules for communication. It is also dependent on the rosserial package.

## Getting Started
Follow these instructions to get the project running

### Configuring XBEE modules
Before using this package, you need to configure your xbee modules. You will need minimum two modules, one as a master/server and second as a slave/client module connected to the firebird robot. Multiple clients can be connected to the same server. Use the [XCTU software by DiGi International](https://www.digi.com/products/xbee-rf-solutions/xctu-software/xctu#productsupport-utilities) to configure the two xbees. Ensure you keep your baud rate at 57600 only.

### Configuring the Firebird robot
Find the hex file that needs to be uploaded to the firebird robot within the embedded folder. Along with it, you can find avrdude_script.sh which you can use to upload the hex file unto your robot. You will find the embedded C code under embedded/rosserial_firebird. Use the Arduino IDE to open the rosserial_firebird.ino file. Additionally, in order to compile the code in the Arduino IDE you will need the ROS library compatible for arduino. You must copy the ros_lib and paste it in your arduino libraries folder for this.

### Using the rosserial package
Clone the rosserial package. Ensure you have chosen the correct ros-distro
```
git clone https://github.com/ros-drivers/rosserial/tree/indigo-devel
```

Follow the instructions given in [rosserial_xbee](http://wiki.ros.org/rosserial_xbee) to setup a xbee network. Additionally you can check this [example](http://wiki.ros.org/rosserial_xbee/Tutorials/Example%20Network) to verify the network you set up.

You must always run the xbee_network.py before working with the firebird package to establish your network.

## Firebird Message

### sensor.msg
The firebird robot has 16 ADC channels that consist of 3 white line sensors, 5 sharp IR sensors, 8 IR proximity sensors, 1 battery voltage sensor and 2 auxiliary channels for external connected sensors. The Sensor.msg encompasses these 16 channels into one message

### lcd.msg
In order to print something on the LCD of the firebird robot, you can use the lcd.msg message. The row and col sets the cursor location and the val contains the data you intend to print

## Topics
The firebird robot subscribes to 9 topics and publishes 1 topic. These topics are all under the namespace **/firebird**. You should use *rostopic info /topic* to see the msg type of the topic

### /sensors
The **/firebird/sensors** topic publishes the sensor data from the robot using the sensor.msg. The data published is a raw 8-bit data from the Analog to Digital conversion.
Note: If a sensor is not connected to the channel, a garbage value will be returned to the topic and hence, you may see random values to pins without sensors.

### /buzzer
The **/firebird/buzzer** is boolean topic. Sending 1 on this topic will turn on the buzzer and sending 0 on this topic will turn off the buzzer.

### /motor
The **/firebird/motor** topic is a ns for motor topics of configuring the direction of the robot, the pwm for its left and right motors and using the encoder sensors connected to the wheels.

#### /config
Use **/firebird/motor/config** to set the direction of the motor. The following table displays the value required for a corresponding direction:

1 - Forward
2 - Left
3 - Right
4 - Back
5 - Soft Left
6 - Soft Right
7 - Soft Left Back
8 - Soft Right Back
0 - Stop

#### /pwm_l
**/firebird/motor/pwm_l** sets a 8 bit pwm(0-255) to the left motor

#### /pwm_r
**/firebird/motor/pwm_r** sets a 8 bit pwm(0-255) to the right motor

#### /linear
Using **/firebird/motor/linear** you can set a distance (in mm) for the robot to traverse

#### /angle
Using **/firebird/motor/angle** you can set an angle for the robot to rotate

### /lcd
Use the **/firebird/lcd** ns for the printing data on the lcd and clearing the lcd

#### /print
**/firebird/lcd/print** uses the lcd.msg to print data on the lcd. The cursor is first positioned at row and column, as specified in the message, and then the data is printed

#### /clear
**/firebird/lcd/clear** clears the lcd and erases everything printed on it. It does not take any parameters or msgs

### /bargraph_led
In order to access the bargraph leds on the robot, use the **/firebird/bargraph_led** topic. You need to set an 8-bit value (0-255) to turn on the corresponding LEDs.


