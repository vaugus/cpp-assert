#!/bin/bash

g++ -O -c src/AssertEquals.cpp include/AssertEquals.hpp

ar rcs lmylib.a AssertEquals.o

g++ -c src/main.cpp -L. -lcpp_assert
g++ assert_equals.o src/main.cpp 

g++ -o main src/assert_equals.cpp src/main.cpp

