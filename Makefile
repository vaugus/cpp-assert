CC = g++ -std=c++17
CFLAGS = -c 
SHARED_FLAGS =  -w -fPIC -g -shared

OBJ = assert_equals.o test_suite_writer.o unit_test_factory.o
INC = include/
SRC = src/


all: main

assert_equals: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) -o assert_equals.so $(INC)assert_equals.hpp $(SRC)assert_equals.cpp $(SHARED_FLAGS)

test_suite_writer: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(CC) -o test_suite_writer.so $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp $(SHARED_FLAGS)

unit_test_factory: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
	$(CC) -o unit_test_factory.so $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp $(SHARED_FLAGS)

main: $(OBJ) $(SRC)main.cpp
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert_equals.o: $(INC)assert_equals.hpp $(SRC)assert_equals.cpp
	$(CC) $(INC)assert_equals.hpp $(SRC)assert_equals.cpp -w $(CFLAGS)

test_suite_writer.o: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(CC) $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp -w $(CFLAGS)

unit_test_factory.o: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
	$(CC) $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp -w $(CFLAGS)

writer: $(OBJ) $(SRC)build_tests.cpp
	$(CC) -o writer $(OBJ) $(SRC)build_tests.cpp

run_tests: $(OBJ) $(SRC)run_tests.cpp
	$(CC) -o run_tests $(OBJ) $(SRC)run_tests.cpp

run:
	@./main

clean:
	rm -f *.o
	rm -f *.so
	rm -f $(INC)*.gch
	rm -f main
	rm -f run_tests
	rm -f writer
