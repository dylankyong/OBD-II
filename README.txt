Dylan Yong
September 11, 2018
Project: OBD-II Speedometer/RPM display
Libraries: OBD.h, Adafruit_LEDBackpack.h, Adafruit_GFX.h, Wire.h 
Materials: Arduino Uno, 4x7 Segment LED Display + Breadboard, 4x7 Segment LED + Adafruit Backpack, Freematics OBD-II to Arduino Scanner

The objective of this project was to display the speed and RPM of a car using an OBD-II scanner and an Arduino Uno. The Arduino received the diagnostic data from the scanner and displayed it on two 4x7 segment LED displays. One of these displays is using an Adafruit Backpack (SCL/SDA input) to simplify the printing of numbers. The other display is using multiple Arduino digital outputs and a breadboard for maximum control of each individual LED.
