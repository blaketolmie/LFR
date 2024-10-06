# LFR
ENMT221 Line Following Robot Software  
S2 2024  
[NOTE ON COLLABORATION](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)

## ATMega328P Microcontroller
[ATMega328P Datasheet](https://components101.com/microcontrollers/atmega328p-pinout-features-datasheet)  
[Pinout with ADC pins explained](https://www.learningaboutelectronics.com/Articles/Atmega328-pinout.php#:~:text=Since%20the%20ADC%20for%20the%20Atmega328%20is%20a,value%3B%20thus%2C%20it%20is%20its%20digital%20correspondent%20value.)
[Full datasheet - register summary on pg8](https://www.jameco.com/Jameco/Products/ProdDS/2139111.pdf)  
## Downloading the bootloader (using Arduino IDE)
[Arduino IDE](https://docs.arduino.cc/software/ide/)    <br>
[MiniCore](https://github.com/MCUdude/MiniCore#how-to-install)  
   
>To burn a bootloader using AVR GCC, the choice of programmer depends on the hardware you have available for interfacing with the microcontroller.  
>Here’s a breakdown of the programmers listed in your image and their common uses:  
>  
>Arduino as ISP: If you have an Arduino board, you can use it to program AVR chips by setting it up as an ISP (In-System Programmer). This is a common and cost-effective method.  
>**USBasp:** This is a popular and inexpensive USB-based programmer for AVR microcontrollers. It's widely used and works well with AVR GCC.  
>**USBtinyISP:** Another inexpensive USB programmer. It’s often used with AVR microcontrollers but might be slower than USBasp.  
>**AVRISP mkII:** This is an official programmer from Atmel (now Microchip) designed for use with AVR microcontrollers. It is a reliable choice if you have access to it.  
>Clock: 9.216 MHz  

## Programming CHANGE TO ARDUINO PROGRAMMING SINCE EASIER / FASTER
[Arduino Programming](https://docs.arduino.cc/programming/)  
>Serial.print(): Used to print data to the serial monitor without a newline.  
>Serial.println(): Used to print data to the serial monitor with a newline.  
>Serial.println("The value is: " + String(value));  
[MiniCore Tips](https://github.com/MCUdude/MiniCore#how-to-install)  
[Embedded C](https://www.learningaboutelectronics.com/EmbeddedC/)  
[AVR](https://github.com/avrdudes/avr-libc)  
More  
[Microcontrollers](https://www.eng.auburn.edu/~nelson/courses/elec3040_3050/C%20programming%20for%20embedded%20system%20applications.pdf#:~:text=C%20programming%20for%20embedded)  
[Using ATMEL Studios](https://hardwarebee.com/step-by-step-guide-to-microcontroller-programming/#:~:text=What%20is%20microcontroller%20programming?)  
[tutorial](https://github.com/a5221985/tutorials/blob/master/Embedded_Systems/microcontroller_embedded_c_programming_absolute_beginners.md)  
[other](https://github.com/aman-goel/avr)  
[ENCE260 Richard Claire Code](https://eng-git.canterbury.ac.nz/rmc84/ence260-ucfk4)  
### Pin macros
// Use PIN_PB5 macro to refer to pin PB5 (Arduino pin 13)  
digitalWrite(PIN_PB5, HIGH);

// Results in the exact same compiled code  
digitalWrite(13, HIGH);

### Other things of note with MiniCore
Printf support  
EEPROM option (Electrically Erasable Programmable Read-Only Memory)  
BOD option  
[ADC pins explained](https://www.hackster.io/yeshvanth_muniraj/analog-to-digital-converter-module-of-atmega328p-e255ea#:~:text=Features%20of%20the%20ADC%20in%20ATmega328P:%20The#:~:text=Features%20of%20the%20ADC%20in%20ATmega328P:%20The)  
[More on ADCs](https://www.tspi.at/2021/07/15/atmegaavradc.html#:~:text=The%20ATMega328p%20and%20the%20ATMega2560%20offers)  
[Using the ATmega328P ADC Module](https://ece-classes.usc.edu/ee459/library/documents/ADC.pdf#:~:text=Using%20the%20Atmel%20ATmega328P%20Analog%20to)  
[building circuits](https://www.build-electronic-circuits.com/microcontroller-tutorial-part3/)  


### Example Code
![image](https://github.com/user-attachments/assets/1dcd34ce-a26a-4fc3-a142-9096b09b8416)


[GitHub Flavored Markdown Spec](https://github.github.com/gfm/)
