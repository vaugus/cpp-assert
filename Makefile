CC = g++ -std=c++17
CFLAGS = -c 
SHARED_FLAGS =  -w -fPIC -g -shared

OBJ = assert.o scanner.o test_suite.o unit_test_factory.o
INC = include/
ENTITY_HPP = include/entity/
ENTITY_CPP = src/entity/
FACTORY_HPP = include/factory/
FACTORY_CPP = src/factory/
SUITE_HPP = include/suite/
SUITE_CPP = src/suite/
SRC = src/


all: main

assert: $(ENTITY_HPP)assert.hpp $(ENTITY_CPP)assert.cpp
	$(CC) -o assert.so $(ENTITY_HPP)assert.hpp $(ENTITY_CPP)assert.cpp $(SHARED_FLAGS)

test_suite: $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp
	$(CC) -o test_suite.so $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp $(SHARED_FLAGS)	

unit_test_factory: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
	$(CC) -o unit_test_factory.so $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp $(SHARED_FLAGS)

main: $(OBJ) $(SRC)main.cpp
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert.o: $(ENTITY_HPP)assert.hpp $(ENTITY_CPP)assert.cpp
	$(CC) $(ENTITY_HPP)assert.hpp $(ENTITY_CPP)assert.cpp -w $(CFLAGS)

scanner.o: $(SUITE_HPP)scanner.hpp $(SUITE_CPP)scanner.cpp
	 $(CC) $(SUITE_HPP)scanner.hpp $(SUITE_CPP)scanner.cpp -w $(CFLAGS)

test_suite.o: $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp
	    $(CC) $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp $(CFLAGS)

unit_test_factory.o: $(FACTORY_HPP)unit_test_factory.hpp $(FACTORY_CPP)unit_test_factory.cpp
	           $(CC) $(FACTORY_HPP)unit_test_factory.hpp $(FACTORY_CPP)unit_test_factory.cpp -w $(CFLAGS)

run:
	@./main

clean:
	find . -type f -name "*.o" -exec rm -f {} \;
	find . -type f -name "*.so" -exec rm -f {} \;
	find . -type f -name "*.gch" -exec rm -f {} \;
	rm -f main
	rm -f run_tests
	rm -f writer
