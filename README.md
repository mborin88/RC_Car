# RC_Car

Project to control Bluetooth car

avr-gcc -mmcu=atmega644p -DF_CPU=12000000 -Wall -Os main.c -o main.elf

avr-objcopy -O ihex main.elf main.hex

avrdude -c usbasp -p m644p -U flash:w:main.hex
