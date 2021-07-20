CC = g++ -std=c++20
CFLAGS = -c

OBJ = assert_equals.o
INC = include/
SRC = src/

all: ./main

main: $(SRC)main.cpp
	$(info Building main)
	g++ -std=c++17 -o main include/assert_equals.hpp $(SRC)main.cpp

run:
	@./main

clean:
	rm main
	rm *.o
	rm $(INC)*.gch
