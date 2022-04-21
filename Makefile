CC = g++ -std=c++17
CFLAGS = -c
SHARED_FLAGS = -w -fPIC -g -shared

INC   = include/
CORE  = core/
FACTR = factory/
SUITE = suite/
BOOT  = bootstrap/
SRC   = src/
BASE  = assert.o scanner.o suite.o factory.o executor.o
OBJ   = $(BASE) unit_test_factory.o

all:

assert.o: $(INC)$(CORE)assert.hpp $(SRC)$(CORE)assert.cpp
	$(CC) $(INC)$(CORE)assert.hpp $(SRC)$(CORE)assert.cpp -w $(CFLAGS)

scanner.o: $(INC)$(CORE)scanner.hpp $(SRC)$(CORE)scanner.cpp
	$(CC) $(INC)$(CORE)scanner.hpp $(SRC)$(CORE)scanner.cpp -w $(CFLAGS)

suite.o: $(INC)$(BOOT)suite.hpp $(SRC)$(BOOT)suite.cpp
	$(CC) $(INC)$(BOOT)suite.hpp $(SRC)$(BOOT)suite.cpp $(CFLAGS)

factory.o: $(INC)$(BOOT)factory.hpp $(SRC)$(BOOT)factory.cpp
	$(CC) $(INC)$(BOOT)factory.hpp $(SRC)$(BOOT)factory.cpp -w $(CFLAGS)

executor.o: $(INC)$(BOOT)executor.hpp $(SRC)$(BOOT)executor.cpp
	$(CC) $(INC)$(BOOT)executor.hpp $(SRC)$(BOOT)executor.cpp -w $(CFLAGS)

unit_test_factory.o: $(INC)$(FACTR)unit_test_factory.hpp $(SRC)$(FACTR)unit_test_factory.cpp
	$(CC) $(INC)$(FACTR)unit_test_factory.hpp $(SRC)$(FACTR)unit_test_factory.cpp -w $(CFLAGS)

main:
	$(CC) -o main $(OBJ) $(SRC)main.cpp

setup: $(BASE) $(SRC)setup.cpp
	+ $(CC) -o setup $(BASE) $(SRC)setup.cpp && bash -c './setup'
	

clean:
	find . -type f -name "*.o" -exec rm -f {} \;
	find . -type f -name "*.so" -exec rm -f {} \;
	find . -type f -name "*.gch" -exec rm -f {} \;
	rm -f main setup $(SRC)$(FACTR)unit_test_factory.cpp
