# LFR
ENMT221 Line Following Robot Software  
S2 2024  

## Set up  
Download [MiniCore](https://github.com/MCUdude/MiniCore#how-to-install) and make sure its in the correct folder   
Open Arduino IDE  
Select Board - ATmega328 and port  
Go to tools and select preferences and burn bootloader  
>**Arduino as ISP**: If you have an Arduino board, you can use it to program AVR chips by setting it up as an ISP (In-System Programmer). This is a common and cost-effective method.  
>USBasp: This is a popular and inexpensive USB-based programmer for AVR microcontrollers. It's widely used and works well with AVR GCC.  
>USBtinyISP: Another inexpensive USB programmer. It’s often used with AVR microcontrollers but might be slower than USBasp.  
>AVRISP mkII: This is an official programmer from Atmel (now Microchip) designed for use with AVR microcontrollers. It is a reliable choice if you have access to it.  
>Clock: 9.216 MHz
 
Can now use serial port  
  
## ATMega328P Microcontroller
[ATMega328P Features Datasheet](https://components101.com/microcontrollers/atmega328p-pinout-features-datasheet)  
[ATMega328P Manufacteres Datasheet - register summary on pg8](https://www.jameco.com/Jameco/Products/ProdDS/2139111.pdf)  
[Pinout with ADC pins explained](https://www.learningaboutelectronics.com/Articles/Atmega328-pinout.php#:~:text=Since%20the%20ADC%20for%20the%20Atmega328%20is%20a,value%3B%20thus%2C%20it%20is%20its%20digital%20correspondent%20value.)  


 
