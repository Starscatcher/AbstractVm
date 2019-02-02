#include <fstream>
#include "Vm.h"

Vm::Vm() {}

Vm::~Vm() {}

Vm      &Vm::operator=(Vm const &src) {}

void    Vm::push()
{

}

void    Vm::pop(){}
void    Vm::dump(){}
void    Vm::assert(){}
void    Vm::add(){}
void    Vm::sub(){}
void    Vm::mul(){}
void    Vm::div(){}
void    Vm::mod(){}
void    Vm::print(){}


int     Vm::checkInstruction(const std::string instruction)
{

}

int     Vm::readStdin()
{
    std::string line;

    while (getline(std::cin, line) && line != "exit")
    {
        if (!checkInstruction(line))
        {
            std::cout << "Invalid instruction" << std::endl;
            return (1);
        }
    }
    if (line == "exit")
    {
        getline(std::cin, line);
        if (line != ";;")
        {
            std::cout << "Invalid ;; instruction" << std::endl;
            return (1);
        }
    }
    else
    {
        std::cout << "Invalid exit instruction" << std::endl;
        return (1);
    }
    return (0);
}

int     Vm::readFile(const std::string fileName)
{
    std::ifstream   fd(fileName);
    std::string     line;

    if (fd)
    {
        while (getline(fd, line) && line != "exit")
        {
            if (!checkInstruction(line))
            {
                std::cout << "Invalid instruction" << std::endl;
                return (1);
            }
        }
        if (line != "exit")
        {
            std::cout << "Invalid exit instruction" << std::endl;
            return (1);
        }
    }
}
