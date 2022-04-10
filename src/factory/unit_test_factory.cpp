#include "../../include/entity/unit_test.hpp"
#include "../../include/factory/unit_test_factory.hpp"

#include "../../test/assert_test.cpp"
// #include "../../test/test_suite_writer_test.cpp"
#include "../../test/unit_test_factory_test.cpp"

#include <iostream>
#include <string>
#include <map>

#include <cstdio>
#include <functional>
#include <map>

// UnitTest* x() {
//     return new AssertEqualsTest();
// }    
// UnitTest* y() {
//     return new UnitTestFactoryTest();
// }

// using TestLookup = std::map<std::string, std::function<UnitTest*()>>;

// void func4(std::vector<double>& v) {
//     std::transform(v.begin(), v.end(), v.begin(),
//         [](double d) -> double {
//             if (d < 0.0001) {
//                 return 0;
//             } else {
//                 return d;
//             }
//         });
// }


UnitTest *UnitTestFactory::create(std::string const &type)
{

    // TestLookup myMap = {
    //     { 1, []() -> UnitTest* { return new } },
    //     { 2, y },
    // };

    // auto it = myMap.find(2);

    // if (it != myMap.end()) {
    //     it->second();
    // }


    if (type == "assert_test")
    {
        return new AssertEqualsTest();
    }

    if (type == "unit_test_factory_test")
    {
        return new UnitTestFactoryTest();
    }

    // if (type == "test_suite_writer_test")
    // {
    //     return new TestSuiteWriterTest();
    // }

    return nullptr;
}