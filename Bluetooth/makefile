PKG =bluetooth
CC =avr-gcc
OBJCOPY=avr-objcopy

CFLAGS = -mmcu=atmega644p -DF_CPU=12000000 -Wall -Os
OFLAGS = -O ihex
PORT = 

upload: $(PKG).c
		avr-gcc $(CFLAGS) $(PKG).c -o $(PKG).elf
		avr-objcopy $(OFLAGS) $(PKG).elf $(PKG).hex
		avrdude -c usbasp -p m644p -U flash:w:$(PKG).hex

clean: 
		del $(PKG).elf
		del $(PKG).hex