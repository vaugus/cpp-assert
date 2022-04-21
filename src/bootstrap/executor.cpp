#include "../../include/bootstrap/executor.hpp"

void BoostrapExecutor::compile(string file)
{
    std::stringstream command_builder;
    command_builder << BootstrapConstants::MAKE;
    command_builder << file;

    const char *command = command_builder.str().c_str();
    std::cout << "Compiling file using " << command << std::endl;
    system(command);
}

void BoostrapExecutor::run(string command)
{
}

// int main ()
// {
//     char filename[100];
//     cout << "Enter file name to compile ";
//     cin.getline(filename, 100);
  
//     // Build command to execute.  For example if the input
//     // file name is a.cpp, then str holds "gcc -o a.out a.cpp" 
//     // Here -o is used to specify executable file name

  

  
//     cout << "\nRunning file ";
//     system("./foo");
  
//     return 0;
// }