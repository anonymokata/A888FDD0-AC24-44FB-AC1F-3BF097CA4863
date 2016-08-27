SRC = ./src/
INCL = ./include/
BIN = ./bin/
LIB_PATH = -L /usr/lib/x86_64-linux-gnu -L /lib64 -L /lib
LIB = -lcheck -lm -lpthread -lrt

all: default

default: RomanNumerals

RomanNumerals: $(SRC)*.c
	gcc $(SRC)*.c -o romanNumerals -I $(INCL) $(LIB_PATH) $(LIB)
	./romanNumerals tests

clean: 
	rm -f romanNumerals
