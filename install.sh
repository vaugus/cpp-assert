#!/bin/bash

make assert
make test_suite_writer
make unit_test_factory

mv libassert_equals.so     $LIB
mv libtest_suite_writer.so $LIB
mv libunit_test_factory.so $LIB

cp -R include/ cpp-assert/
mv cpp-assert $INC
