

#!/bin/sh

# sudo apt-get install avr-libc gcc-avr avrdude binutils-avr gdb-avr


avr-gcc -mmcu=atmega328 -Wall main.c inicio.c  -o main.bin
avr-objcopy -j .text -O ihex main.bin main.hex
avrdude -p m328 -V -c usbtiny -U f:w:main.hex

#avrdude -p m8 -c usbtiny  -U lfuse:w:0xe1:m -U hfuse:w:0xd9:m


# USART.c inicio.c estados.c control.c eeprom.c configuraciones.c ADC.c Leds.c Botones.c otras.c

#http://www.linuxandubuntu.com/home/setting-up-avr-gcc-toolchain-and-avrdude-to-program-an-avr-development-board-in-ubuntu
