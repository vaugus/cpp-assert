CC = g++ -std=c++17
CFLAGS = -c

OBJ = assert_equals.o
INC = include/
SRC = src/

all: ./main

main: $(SRC)main.cpp
	$(info Building main)
	$(CC) -o main $(INC)assert_equals.hpp $(SRC)main.cpp

run:
	@./main

clean:
	rm main
	rm *.o
	rm $(INC)*.gch
