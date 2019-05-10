#!/bin/sh

# sudo apt-get install avr-libc gcc-avr avrdude


avr-gcc -mmcu=atmega8 -Wall main.c USART.c inicio.c  estados.c control.c eeprom.c configuraciones.c ADC.c Leds.c Botones.c otras.c -o main.bin 
avr-objcopy -j .text -O ihex main.bin main.hex
avrdude -p m8 -V -c usbtiny -U f:w:main.hex   

#avrdude -p m8 -c usbtiny  -U lfuse:w:0xe1:m -U hfuse:w:0xd9:m




