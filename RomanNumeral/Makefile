SRC_FILES := $(shell ls src/*.c)
SRC_TEST_FILES := $(shell ls src/tests/*.c)

SRC = ./src/
INCL = ./include/
BIN = ./bin/
LIB_PATH = -L /usr/lib/x86_64-linux-gnu -L /lib64 -L /lib
LIB = -lcheck -lm -lpthread -lrt
FILTER = %romanNumeralRunner.c

all: default

default: RomanNumerals test

RomanNumerals: $(SRC_FILES)
	gcc $(SRC_FILES) -o romanNumerals -I $(INCL) $(LIB_PATH) $(LIB)

test:	$(SRC_FILES) $(SRC_TEST_FILES)
	gcc $(filter-out $(FILTER), $(SRC_FILES)) $(SRC_TEST_FILES) -o romanNumeralTests -I $(INCL) -I $(INCL)tests/ $(LIB_PATH) $(LIB)

clean: 
	rm -f romanNumerals
	rm -f romanNumeralTests
