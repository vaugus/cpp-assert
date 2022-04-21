#include <map>
#include "../../include/core/unit_test.hpp"
#include "../../include/factory/test_factory.hpp"

using ConstructorMap = std::map<std::string, std::function<UnitTest*()>>;

UnitTest *UnitTestFactory::create(std::string const &type)
{
    ConstructorMap constructor_map = {
    };
    
    auto it = constructor_map.find(type);

    if (it != constructor_map.end()) {
        return it->second();
    }

    return nullptr;
}