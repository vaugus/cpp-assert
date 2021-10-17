CC = g++ -std=c++17
CFLAGS = -c

OBJ = assert_equals.o test_suite_writer.o unit_test_factory.o
INC = include/
SRC = src/


all: main

main: $(OBJ) $(SRC)main.cpp
	$(info Building main)
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert_equals.o: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) $(INC)assert_equals.hpp $(SRC)assert_equals.cpp -w $(CFLAGS)

test_suite_writer.o: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(CC) $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp -w $(CFLAGS)

unit_test_factory.o: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
	$(CC) $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp -w $(CFLAGS)

build_tests: $(OBJ) $(SRC)build_tests.cpp
	$(info Building build_tests)
	$(CC) -o build_tests $(OBJ) $(SRC)build_tests.cpp

run:
	@./main

clean:
	rm *.o
	rm $(INC)*.gch
