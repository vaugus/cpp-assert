CC = g++ -std=c++17
CFLAGS = -c 
SHARED_FLAGS =  -w -fPIC -g -shared

OBJ = assert.o scanner.o suite_generator.o factory_generator.o
INC = include/

CORE_HPP = include/core/
CORE_CPP = src/core/

FACTORY_HPP = include/factory/
FACTORY_CPP = src/factory/

SUITE_HPP = include/suite/
SUITE_CPP = src/suite/

GENERATOR_HPP = include/generator/
GENERATOR_CPP = src/generator/

GENERATION = generation/
SRC = src/


all: main

# assert: $(CORE_HPP)assert.hpp $(CORE_CPP)assert.cpp
# 	$(CC) -o assert.so $(CORE_HPP)assert.hpp $(CORE_CPP)assert.cpp $(SHARED_FLAGS)

# suite_generator: $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp
# 	$(CC) -o test_suite.so $(SUITE_HPP)test_suite.hpp $(SUITE_CPP)test_suite.cpp $(SHARED_FLAGS)	

# test_factory: $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp
# 	$(CC) -o unit_test_factory.so $(INC)unit_test_factory.hpp $(SRC)unit_test_factory.cpp $(SHARED_FLAGS)

main: $(OBJ) $(SRC)main.cpp
	$(CC) -o main $(OBJ) $(SRC)main.cpp

assert.o: $(CORE_HPP)assert.hpp $(CORE_CPP)assert.cpp
	$(CC) $(CORE_HPP)assert.hpp $(CORE_CPP)assert.cpp -w $(CFLAGS)

scanner.o: $(SUITE_HPP)scanner.hpp $(SUITE_CPP)scanner.cpp
	 $(CC) $(SUITE_HPP)scanner.hpp $(SUITE_CPP)scanner.cpp -w $(CFLAGS)

suite_generator.o: $(GENERATOR_HPP)suite_generator.hpp $(GENERATOR_CPP)suite_generator.cpp
	    	 $(CC) $(GENERATOR_HPP)suite_generator.hpp $(GENERATOR_CPP)suite_generator.cpp $(CFLAGS)

factory_generator.o: $(GENERATOR_HPP)factory_generator.hpp $(GENERATOR_CPP)factory_generator.cpp
			   $(CC) $(GENERATOR_HPP)factory_generator.hpp $(GENERATOR_CPP)factory_generator.cpp -w $(CFLAGS)


factory: 
	$(CC) -o factory $(OBJ) $(GENERATION)factory_generation.cpp

suite: 
	$(CC) -o suite $(OBJ) $(GENERATION)suite_generation.cpp


run:
	@./main

clean:
	find . -type f -name "*.o" -exec rm -f {} \;
	find . -type f -name "*.so" -exec rm -f {} \;
	find . -type f -name "*.gch" -exec rm -f {} \;
	rm -f main
	rm -f run_tests
	rm -f writer
	rm -f factory
	rm -f suite
	rm -f runners/run_tests.cpp
	rm -f runners/unit_test_factory.cpp
