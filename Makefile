CC = g++ -std=c++17
CFLAGS = -c

OBJ = assert_equals.o test_suite_writer.o
INC = include/
SRC = src/

all: main

main: $(OBJ) $(SRC)main.cpp
	$(info Building main)
	$(CC) -o main $(OBJ) $(SRC)main.cpp
	mkdir build
	mv main build/

assert_equals.o: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) $(INC)assert_equals.hpp $(SRC)assert_equals.cpp -w $(CFLAGS)

test_suite_writer.o: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(info Building test_suite_writer.o)
	$(CC) $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp -w $(CFLAGS)

build_tests: $(OBJ) $(SRC)build_tests.cpp
	$(info Building build_unit_tests)
	$(CC) -o build_tests $(OBJ) $(SRC)build_tests.cpp

test: $(OBJ) $(SRC)run_tests.cpp
	$(info Building run_tests)
	$(CC) -o run_tests $(OBJ) $(SRC)run_tests.cpp

run:
	@./main

clean:
	rm main
	rm *.o
	rm $(INC)*.gch
	rm -r build
