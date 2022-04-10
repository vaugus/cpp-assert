#ifndef UNIT_TEST_FACTORY_BUILDER_HPP
#define UNIT_TEST_FACTORY_BUILDER_HPP

#include <dirent.h>
#include <fstream>
#include <sstream>
#include "../types.hpp"

class UnitTestFactoryGenerator
{
private:
    
public:
    void generate(Vector<String> const &headers);
};

#endif