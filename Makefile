CC = g++ -std=c++17
CFLAGS = -c

OBJ = assert_equals.o util.o
INC = include/
SRC = src/

all: main

main: $(OBJ) $(SRC)main.cpp
	$(info Building main)
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert_equals.o: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) $(INC)assert_equals.hpp $(SRC)assert_equals.cpp -w $(CFLAGS)

util.o: $(INC)util.hpp $(SRC)util.cpp
	$(info Building util.o)
	$(CC) $(INC)util.hpp $(SRC)util.cpp -w $(CFLAGS)

test_runner_writer: $(OBJ) $(SRC)test_runner_writer.cpp
	$(CC) -o test_runner_writer $(OBJ) $(SRC)test_runner_writer.cpp

run:
	@./main

clean:
	rm main
	rm *.o
	rm $(INC)*.gch
