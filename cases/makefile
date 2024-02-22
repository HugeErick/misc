CC	:= gcc
C_FLAGS := -Wall -Wextra -std=c2x

SRC	:= $(shell find src -name '*.c')
INCLUDE	:= hdr

EXECUTABLE	:= main.exe

all:	$(EXECUTABLE)

run: all
		./$(EXECUTABLE)

$(EXECUTABLE): $(SRC)
	$(CC) $(C_FLAGS) -I$(INCLUDE) $^ -o $@

clean:
	-rm $(EXECUTABLE)
