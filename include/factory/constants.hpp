#ifndef FACTORY_CONSTANTS_HPP
#define FACTORY_CONSTANTS_HPP

#include <string>

namespace FactoryConstants
{
    const std::string UNIT_TEST_ENTRY = "{ name , []() -> UnitTest* { return new constructor } }";
}

#endif