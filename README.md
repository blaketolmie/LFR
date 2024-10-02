# LFR
ENMT221 Line Following Robot Software  
S2 2024  
[NOTE ON COLLARBORATION](https://docs.github.com/en/pull-requests/collaborating-with-pull-requests/proposing-changes-to-your-work-with-pull-requests/about-pull-requests)

## ATMega328P Microcontroller
[ATMega328P Datasheet](https://components101.com/microcontrollers/atmega328p-pinout-features-datasheet)  
[Pinout with ADC pins explained](https://www.learningaboutelectronics.com/Articles/Atmega328-pinout.php#:~:text=Since%20the%20ADC%20for%20the%20Atmega328%20is%20a,value%3B%20thus%2C%20it%20is%20its%20digital%20correspondent%20value.)

## Downloading the bootloader (using Arduino IDE)
[Arduino IDE](https://docs.arduino.cc/software/ide/)    <br>
[MiniCore](https://github.com/MCUdude/MiniCore#how-to-install)


## Programming
[Arduino Programming](https://docs.arduino.cc/programming/)  
[MiniCore Tips](https://github.com/MCUdude/MiniCore#how-to-install)  
[Embedded C](https://www.learningaboutelectronics.com/EmbeddedC/)  

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

### Example Code
![image](https://github.com/user-attachments/assets/1dcd34ce-a26a-4fc3-a142-9096b09b8416)


[GitHub Flavored Markdown Spec](https://github.github.com/gfm/)
