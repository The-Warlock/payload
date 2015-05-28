VERSION = 3.02
CC	= /usr/bin/avr-gcc
AO	= /usr/bin/avr-objcopy
CFLAGS	= -mmcu=atmega8 -Wall -Os -o
DFLAGS 	= -j .text -j .data -O ihex  
PFLAGS 	= -pm8 -cjtag2isp -Pusb -e

OBJ = main.o

all: $(OBJ)
	$(AO) $(DFLAGS) $(OBJ) flash.hex

%.o: %.c
	$(CC) $(CFLAGS) $@ $<

clean:
	rm -rf $(OBJ)

program:
	avrdude $(PFLAGS) -U flash:w:flash.hex
