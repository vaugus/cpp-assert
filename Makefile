CC = g++ -std=c++17
CFLAGS = -c 
SHARED_FLAGS =  -w -fPIC -g -shared

OBJ = assert.o test_suite_writer.o unit_test_factory.o scanner.o test_suite.o
INC = include/
SRC = src/


all: main

assert: $(INC)assert.hpp $(SRC)assert.cpp
	$(CC) -o assert.so $(INC)assert.hpp $(SRC)assert.cpp $(SHARED_FLAGS)

test_suite_writer: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(CC) -o test_suite_writer.so $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp $(SHARED_FLAGS)

test_suite: $(INC)test_suite.hpp $(SRC)test_suite.cpp
	$(CC) -o test_suite.so $(INC)test_suite.hpp $(SRC)test_suite.cpp $(SHARED_FLAGS)	

unit_test_factory: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
	$(CC) -o unit_test_factory.so $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp $(SHARED_FLAGS)

main: $(OBJ) $(SRC)main.cpp
	$(CC) -o cpp-assert $(OBJ) $(SRC)main.cpp

assert.o: $(INC)assert.hpp $(SRC)assert.cpp
	$(CC) $(INC)assert.hpp $(SRC)assert.cpp -w $(CFLAGS)

scanner.o: $(INC)scanner.hpp $(SRC)scanner.cpp
	$(CC) $(INC)scanner.hpp $(SRC)scanner.cpp -w $(CFLAGS)

test_suite_writer.o: $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp
	$(CC) $(INC)test_suite_writer.hpp $(SRC)test_suite_writer.cpp -w $(CFLAGS)

test_suite.o: $(INC)test_suite.hpp $(SRC)test_suite.cpp
	$(CC) $(INC)test_suite.hpp $(SRC)test_suite.cpp $(CFLAGS)

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
	rm -f cpp-assert
	rm -f run_tests
	rm -f writer
