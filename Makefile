CC = g++ -std=c++17
CFLAGS = -c

OBJ = assert_equals.o
INC = include/
SRC = src/

all: ./main

main: $(OBJ) $(SRC)main.cpp
	$(info Building main)
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert_equals.o: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) $(INC)assert_equals.hpp $(SRC)assert_equals.cpp -w $(CFLAGS)

run:
	@./main

clean:
	rm main
	rm *.o
	rm $(INC)*.gch
