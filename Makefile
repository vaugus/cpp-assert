CXX = g++ -std=c++17
CXXFLAGS = -c -w -fPIC -g -shared

SRC = $(shell find src -type f -name '*.cpp')
OBJ = $(subst .cpp,.o,$(SRC))

.PHONY: all clean

all: $(OBJ) main

main: $(OBJ)
	$(CXX) -o main $^

clean:
	find . -type f -name '*.gch' -exec rm {} \;
	rm -f $(OBJ) main
