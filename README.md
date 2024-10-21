# LFR
ENMT221 Line Following Robot Software  
S2 2024  

## Access to Github
Send me your GitHub username or email so I can grant you collaborater access (so you can make push and pull requests etc)  
[GitHub Desktop](https://github.com/apps/desktop)

## Set up  
Download [MiniCore](https://github.com/MCUdude/MiniCore#how-to-install) and make sure its in the correct folder   
Open [Arduino IDE](https://www.arduino.cc/en/software)  
Select Board - ATmega328 and port  
Go to tools and select preferences and burn bootloader  
+ Board: "ATmega328"  
+ BOD (Brown-out detection): "BOD 2.7V"  
+ Bootloader: "Yes (UART0)"  
+ Clock: "Internal 1 MHz"  
+ Variant: "328P / 328PA"  
+ Programmer: "Atmel-ICE ISP"  
>**Arduino as ISP**: If you have an Arduino board, you can use it to program AVR chips by setting it up as an ISP (In-System Programmer). This is a common and cost-effective method.  
>USBasp: This is a popular and inexpensive USB-based programmer for AVR microcontrollers. It's widely used and works well with AVR GCC.  
>USBtinyISP: Another inexpensive USB programmer. It’s often used with AVR microcontrollers but might be slower than USBasp.  
>AVRISP mkII: This is an official programmer from Atmel (now Microchip) designed for use with AVR microcontrollers. It is a reliable choice if you have access to it.  
>Clock: 9.216 MHz  
>[Arduino Programming](https://docs.arduino.cc/programming/)  
>When coding in Arduino IDE use [Arduino Pins](https://camo.githubusercontent.com/b719fa994f4db0dd95e224fbdd939f93f7b6ba881b3c41e480b4733d4d82b6e6/68747470733a2f2f692e696d6775722e636f6d2f715849456368542e6a7067) in blue  
  
## Arduino_Code
Incorporated  
- Reactive control  
- LEDs  
- Sensors  
- Motors  
- Config file - all #defines for pin and globals  
- Serial communication (println)  
  
NOTE:  
Only one reset button (MOTOR_CONTROL) is available since the RESET button is not connect to the microcontroller in the schematic.  
If sensors are giving random values - check the height from the ground 
Only 3 sensors ended up working hence no PID or bang bang controller  
  
 ## ATMega328P Microcontroller
[ATMega328P Features Datasheet](https://components101.com/microcontrollers/atmega328p-pinout-features-datasheet)  
[ATMega328P Manufacteres Datasheet - register summary on pg8](https://www.jameco.com/Jameco/Products/ProdDS/2139111.pdf) 
