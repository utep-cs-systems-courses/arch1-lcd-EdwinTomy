# makefile configuration
COMMON_OBJECTS  =
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -L/opt/ti/msp430_gcc/include
LDFLAGS		= -L../lib -L/opt/ti/msp430_gcc/include


#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: main.elf

#additional rules for files
main.elf: ${COMMON_OBJECTS} buzzer.o led.o switches.o main.o switching_s.o wdt_handler.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ -lTimer -lLcd -lm

load: main.elf
	msp430loader.sh  $^

clean: $^
	rm -f *.o *.elf *.c~ *.h~ *.c#

wdt.elf: wdt-c.o 
buzzer.o: buzzer.h 
led.o: led.h 
switches.o: switches.h led.h 

switching_s.o: led.h
