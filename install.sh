#!/bin/bash

make assert
make test_suite_writer
make unit_test_factory

cp -R include/ cpp-assert/
mv cpp-assert /usr/local/include/
